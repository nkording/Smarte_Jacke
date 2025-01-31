#include <ArduinoBLE.h>
#include <Arduino_LSM6DSOX.h>

BLEService sjService("19B10000-E8F2-537E-4F6C-D104768A1214"); // Bluetooth® Low Energy LED Service  //Spezifische Nummer für den Arduino

// Bluetooth® Low Energy LED Switch Characteristic - custom 128-bit UUID, read and writable by central
BLEByteCharacteristic sjCharacteristic("19B10001-E8F2-537E-4F6C-D104768A1214", BLERead | BLEWrite);  //Merkmale des Arduinos, Festlegung das man vom Handy Ihn auslesen und beschreiben kann

const int buttonPin = 3;  // Nummer des Pins am Arduino an dem der Taster angeschlossen ist
const int mosfetPin = 17;  // Nummer des Pins der den MOSFET durchschaltet und somit das Licht und den Lärm

int mosfetState = LOW; // mosfetState fuer den akustischen und visuellen Alarm
int buttonState = LOW; // buttonState Variable fuer den Schalterzustand
int hoch = 0, fall = 0, bew = 0, period = 30000; // hoch zaehlt Extremwerte (hoch) beim Aufschlag; fall zaehlt schwerelose Werte; bew zaehlt Bewegung nach Sturz; period ist Zeitfenster fuer Bewegungszaehlung

float Ax = 0, Ay = 0, Az = 0, tA = 0; // Ax, Ay, Az (Acceleration) Beschleunigung; tA (Total Acceleration) Gesamtbeschleunigung, damit die Ausrichtung des Sensors sich nicht auf die Sturzerkennung auswirkt

unsigned long time_alarm = 0; // time_alarm Zeitpunkt wenn das Entschaerfungsfenster ausgeloest wurde
unsigned long currentMillis = 0, previousMillis = 0;   // currentMillis und previousMillis sind fuer das Blinken des Alarms 
unsigned long startTime = 0, endTime = 0, duration = 0; // Start- und Endzeitpunkt der Tastermessung, sowie Dauer zwischen beiden
unsigned long time_now = 0, currentMillisSensor = 0, previousMillisSensor = 0 ; // time_now wird fuer den Bewegungs-Timer benoetigt; currentMillisSensor und previousMillisSensor sind fuer den Timer der Sensorabfrage, damit der Sensor nicht ueberlastet wird

const long intervaldefuse = 45000; // intervaldefuse Zeitfenster zum Entschaerfen des Alarms; 
const long intervalAlarm = 1000; // intervalAlarm Intervall fuer das Blinken des Alarms
const long intervalSensor = 10; // intervalSensor fuer den Sensor Timer

bool alarm = false;  // alarm gibt an ob ein Fast-Alarm ausgeloest wurde
bool tswitch = false, done = false; // tswitch ob Timer fuer den Taster läuft; done Alarm-Abfrage nur wenn auch gedrueckt wurde
bool on = false, mch = false; // on gibt an, ob gerade eine Bewegungszaehlung stattfindet; mch (motion capture happend) gibt an, ob eine Bewegungszaehlung stattgefunden hat

void setup() {
  Serial.begin(9600);

  if (!IMU.begin()) {  //Pruefung, ob Sensoren ueberhaupt antworten
    Serial.println("Failed to initialize IMU!");
    while (1);
  }

  // Initialisiere MOSFET-Pin als Output:
  pinMode(mosfetPin, OUTPUT);

  // Initialisere Taster als Input:
  pinMode(buttonPin, INPUT);

  // Initialisierung des Bluetooth
  if (!BLE.begin()) {
    Serial.println("starting Bluetooth® Low Energy module failed!");

    while (1);
  }
  
  // Anzeigename und UUID werden dem Bluetooth zugeordnet
  BLE.setLocalName("SMARTE JACKE");  // Name
  BLE.setAdvertisedService(sjService);  // UUID

  // Merkmale werden dem Bluetooth zugeordnet
  sjService.addCharacteristic(sjCharacteristic);

  // service wird hinzugefuegt
  BLE.addService(sjService);

  // Startwert für die Variable die spaeter als Übetragung des Alarms dient 
  sjCharacteristic.writeValue(0); 

  // Arduino macht sich bekannt bei Geraeten in der Umgebung
  BLE.advertise();

  Serial.println("BLE SMARTE JACKE");
}

void loop() {
  // hoert auf Bluetooth® Low Energy Geraete zum verbinden:
  BLEDevice central = BLE.central();

  // wenn das Handy, das als Central fungiert, mit dem Arduino verbunden ist:
  if (central) {
    Serial.print("Connected to central: ");
    // Ausgabe der Handy MAC Adresse:
    Serial.println(central.address());

    // solange das Handy mit dem Arduino verbunden ist, arbeitet die Sturzerkennung und der Alarm:
    while (central.connected()) {
      // sobald der Alarm in die Merkmale reinschreibt,
      // wird der Wert benutzt um die Handy-App zu alarmieren:

      Serial.print(sjCharacteristic.value());
      Serial.println();

      Serial.print("1");
      Serial.println();

      // Entschaerfungsfenster
      Entschaerfung();

      Serial.print("2");
      Serial.println();
        
      // Alarm
      Alarm();

      Serial.print("3");
      Serial.println();

      // Taster
      Taster();

      Serial.print("4");
      Serial.println();

      // Sturzerkennung
      Sturzerkennung();
      
    }

    // Ausgabe wenn Verbindung zwischen Handy und Arduino verloren geht:
    Serial.print(F("Disconnected from central: "));
    Serial.println(central.address());
  }

  Serial.println("Kein Bluetooth ");
  Serial.println();

}




void Entschaerfung() {
  // Wenn ein Alarm vom System ausgeloest werden soll, wird zuerst ein Fast-Alarm ausgeloest, der bei nicht Entschaerfung in 45 sekunden den richtigen Alarm ausloest 
  if (alarm == true) {
    time_alarm = millis();
    alarm = false;
   }

  // Deaktivierung von Laerm und Licht, wenn kein Alarm vorhanden ist
  if (sjCharacteristic.value() == 0) {
    mosfetState = LOW;
  }

  // Wenn sowohl der Fast-Alarm noch aktiv ist und der Timer durchgelaufen ist, wird der richtige Alarm ausgeloest
  if (sjCharacteristic.value() == 3 && millis() - time_alarm >= intervaldefuse) {
    sjCharacteristic.writeValue(2);
  }   
}

void Alarm() {
  // Wenn das Value = 2 ist, liegt ein Alarm vor und der Timer fuer das Blinken des Alarms startet
  if (sjCharacteristic.value() == 2) {
    currentMillis = millis();
    Serial.println("Alarm "); 
    Serial.println();
  }

  // Wenn ein Intervall des Timers des Alarms verstrichen ist, wird der Intervall zurueckgesetzt
  if (currentMillis - previousMillis >= intervalAlarm) {
    previousMillis = currentMillis;

    // Ist der MOSFET-State HIGH wird er zu LOW und andersherum, Licht/Laerm geht an oder aus 
    if (mosfetState == HIGH) {
      mosfetState = LOW;
    } else {
      mosfetState = HIGH;
    }
  }

  // MOSFET-Pin wird entsprechend dem MOSFET-State geschaltet
  digitalWrite(mosfetPin, mosfetState);

}

void Taster() {
  // Auslesen des Tasterzustands (nicht gedrueckt/gedrueckt):
  buttonState = digitalRead(buttonPin);

  // Zeit faengt an zu messen,wenn keine Messung stattfindet und der Taster gedrückt wird
  if (tswitch == false && buttonState == HIGH) {  
    startTime = millis();
    tswitch = true;
  }

  // Zeit misst nicht mehr, wenn Taster nicht mehr gedrueckt wird und Messung stattfindet
  if (tswitch == true && buttonState == LOW) {  
    endTime = millis();
    tswitch = false;
    duration = endTime - startTime;
    done = true;
  }

  // Wenn kuerzer als 7 sekunden gedrueckt wurde, gibt es einen Fast-Alarm
  if (duration < 7000 && done == true) {  
    sjCharacteristic.writeValue(3);  
    alarm = true;
    done = false;
  }         

  // Wenn laenger als 7 sekunden gedrueckt wurde, gibt es keinen Alarm
  if (duration >= 7000 && done == true) {  
    sjCharacteristic.writeValue(0);
    alarm = false;
    done = false;
  }
      
}

void Sturzerkennung() {

  Serial.print("A");
  Serial.println();

  currentMillisSensor = millis(); // Timer start, der alle 10 ms den Sensor abfragt 

  Serial.print("B");
  Serial.println();

  if (currentMillisSensor - previousMillisSensor >= intervalSensor) { //Auslesen des Sensors alle 10 ms 

    Serial.print("C");
    Serial.println();

    previousMillisSensor = currentMillisSensor;

    Serial.print("D");
    Serial.println();

    IMU.readAcceleration(Ax, Ay, Az);  //Speichern der drei Achsen-Sensorwerten, Angabe in g also 1 g = 9,81 m/s^2

    Serial.print("E");
    Serial.println();

    tA = sqrt(Ax*Ax + Ay*Ay + Az*Az); //Gesamtbeschleunigung, da so Orientierung des Sensors unwichtig wird   

    if(millis() % 300000 < 100 && fall <= 15) {  //Zuruecksetzen für alle 5 Minuten sofern nicht ein Freier Fall stattfindet (nicht == 100, da der Zeitpunkt des Zuruecksetzen uebersprungen werden kann)
      fall = 0;
      hoch = 0;
    }

    // 1. Freier Fall 2. Aufschlag 3. Ruhe 
    // 1. Freier Fall
        
        
    if(tA < 0.4 ) { //Zaehler fuer freier Fall Erfassung; Sobald der niedrigste Wert unter 0,4 faellt, zaehlt fall hoch
      fall = fall + 1; //Auftreten eines Fallwertes (Schnitt 25-35 bei Fall auf Tisch)
    }

    //2. Aufschlag
    if(fall >= 15 and tA > 2) {
      hoch = hoch + 1; //Auftrenten eines extremen Wertes bei Aufprall (Schnitt 5-10 bei Fall auf Tisch)
    }
 
    //3. Ruhe
    if (fall >= 15 and hoch >= 4) {  //Sturz mit Aufschlag eingetreten
      time_now = millis(); //Timer starten
      fall = 0; //Zaehler zuruecksetzen damit man nicht nochmal den Timer startet
      hoch = 0;
      bew = 0; //Sturz auf Sturz und damit unendliche Verlaengerung des Timer verhindern 
      on = true; //Bewegungszaehler starten

    }

    if(on and (tA > 1.07)) {  //Bewegungserfassung nach Sturz und Aufschlag, Pruefung ob Person ohnmaechtig ist/sich nicht bewegen kann
      bew = bew + 1;
    }

    if (on){  //Angabe ob gerade eine Bewegungserfassung fuer das Ruhefenster stattfindet
      Serial.println("Am Zaehlen ");
      Serial.println();
    }

    if (on && millis() - time_now > period) {  //Timer und Bewegungserfassung gestoppt
      on = false;
      mch = true;   
    }
          
    if (mch and on == false and bew >= 50) {  //Kein Alarm wenn nach Sturz und Aufprall Bewegung festgestellt wird
      bew = 0;
      mch = false;
      sjCharacteristic.writeValue(0);  
      alarm = false;
            
    } else if (mch and on == false and bew < 50) {  //Alarm wenn keine Bewegung nach Sturz und Aufprall festgestellt wird
      bew = 0;
      mch = false;
      sjCharacteristic.writeValue(3);  
      alarm = true;  
    }
        
  }
  
}