/*
 * This ESP32 code is created by esp32io.com
 *
 * This ESP32 code is released in the public domain
 *
 * For more detail (instruction and wiring diagram), visit https://esp32io.com/tutorials/esp32-sound-sensor
 */

#define SENSOR_PIN 32 // ESP32 pin GPIO18 connected to the OUT pin of the sound sensor
#define LED 2

int lastState = HIGH;  // the previous state from the input pin
int currentState;      // the current reading from the input pin

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // initialize the ESP32's pin as an input
  pinMode(SENSOR_PIN, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  // read the state of the the ESP32's input pin
  currentState = digitalRead(SENSOR_PIN);

  if (lastState == HIGH && currentState == LOW){
    Serial.println("The sound has been detected");
    digitalWrite(LED, HIGH);
  }else if (lastState == LOW && currentState == HIGH){
    Serial.println("The sound has disappeared");
    digitalWrite(LED, LOW);
  }

  // save the the last state
  lastState = currentState;
}
