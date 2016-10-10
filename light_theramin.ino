int sensorValue;
int sensorLow = 1023;
int sensorHigh = 0;

//using on board LED to indicate when the sensor is finished calibrating
const int ledPin = 13;



void setup() { 
  //set the pinMode
  pinMode(ledPin, OUTPUT);

  //turn on the LED to indicate calibration is occurring
  digitalWrite(ledPin, HIGH);

  //sensor reads for 5 seconds and adjusts the sensorHigh and sensorLow values based on the light in the room
  while(millis() < 5000) {
    sensorValue = analogRead(A0);
    if (sensorValue > sensorHigh) {
      sensorHigh = sensorValue;
    }
    if (sensorValue < sensorLow) {
      sensorLow = sensorValue;
    }
  }

  //turn of LED after calibration
  digitalWrite(ledPin, LOW);

}

void loop() {
  //read the sensor value and store it
  sensorValue = analogRead(A0);
  
  //scale the sensor input into frequency range of 50-4000Hz
  int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 4000);

  //play the tone over the piezo on pin 8 for 20 ms
  tone(8, pitch, 20);

  //delay the loop to allow the tone to play
  delay(10);

}
