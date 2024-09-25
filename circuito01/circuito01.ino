const int ledPinU = 32;
const int PinBtnU = 33;
const int PinBtnD = 25;
const int PinBtnT = 26;
const int PinBtnCu = 27;
const int PinBtnCi = 14;

void setup() {
  Serial.begin(9600);
  pinMode (PinBtnU, INPUT);
  pinMode (PinBtnD, INPUT);
  pinMode (PinBtnT, INPUT);
  pinMode (PinBtnCu, INPUT);
  pinMode (PinBtnCi, INPUT);
  pinMode (ledPinU, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  while ((digitalRead(PinBtnU) && digitalRead(PinBtnT) && digitalRead(PinBtnCi)) != HIGH);
  {
    digitalWrite(ledPinU,HIGH); Serial.println("Abierto");
  }
  while ((digitalRead(PinBtnU) || digitalRead(PinBtnT) || digitalRead(PinBtnCi)) != LOW);
  {
    digitalWrite(ledPinU,LOW); Serial.println("Cerrado");
  }
}
/*
  while ((digitalRead(PinBtnU) && digitalRead(PinBtnT) && digitalRead(PinBtnCi)) != HIGH);
  {
    digitalWrite(ledPinU,HIGH); Serial.println("Abierto");
  }
  while ((digitalRead(PinBtnU) || digitalRead(PinBtnT) || digitalRead(PinBtnCi)) != LOW);
  {
    digitalWrite(ledPinU,LOW); Serial.println("Cerrado");
  }
  
  while ((digitalRead(PinBtnU) || digitalRead(PinBtnD) || digitalRead(PinBtnT) || digitalRead(PinBtnCu) || digitalRead(PinBtnCi)) != LOW);
  {
    digitalWrite(ledPinU,LOW); Serial.println("Cerrado");
  }
  //delay(1000);
  while ((digitalRead(PinBtnU) && digitalRead(PinBtnT) && digitalRead(PinBtnCi)) != HIGH);
  {
    digitalWrite(ledPinU,HIGH); Serial.println("Abierto");
  }
  
  if(digitalRead(PinBtnD) || digitalRead(PinBtnCu)){
    digitalWrite(ledPinU,LOW); Serial.println("Cerrado");
  }else{
    if(digitalRead(PinBtnU) && digitalRead(PinBtnT) && digitalRead(PinBtnCi)){ 
      digitalWrite(ledPinU,HIGH); Serial.println("Abierto"); 
    }else{
      digitalWrite(ledPinU,LOW); Serial.println("Cerrado*");
    }
  }
*/
