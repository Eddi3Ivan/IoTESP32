// Este programa enciende una barra de leds dependiendo del voltaje administrado por un potenciometro
//A traves de una conversion analogo-digital por el ADC del pin 32 al que se conectara el potenciometro

//Definicion de variables y pines a ocupar de la tarjeta ESP32
const int pinPot = 32;
const int PinLedUno = 33;
const int PinLedDos = 25;
const int PinLedTres = 26;
const int PinLedCuatro = 27;
const int PinLedCinco = 14;
int iAnalog; 
int estado;

void setup() {
  // Configuración de monitor serial y de pines de los leds como salida
  Serial.begin(9600);
  pinMode (PinLedUno, OUTPUT);
  pinMode (PinLedDos, OUTPUT);
  pinMode (PinLedTres, OUTPUT);
  pinMode (PinLedCuatro, OUTPUT);
  pinMode (PinLedCinco, OUTPUT);
}

void loop() {
  //codigo main:
  iAnalog = analogRead(pinPot); //lectura del valor de voltaje del potenciomentro

  //Sentencias para asignarle un estado a la entrada iAnalog 
  if (iAnalog == 0){ estado = 0; }
  if ((iAnalog >= 1) && (iAnalog <= 818)){ estado = 1; }
  if ((iAnalog >= 819) && (iAnalog <= 1638)){ estado = 2; }
  if ((iAnalog >= 1639) && (iAnalog <= 2458)){ estado = 3; }
  if ((iAnalog >= 2459) && (iAnalog <= 3278)){ estado = 4; }
  if ((iAnalog >= 3279) && (iAnalog <= 4095)){ estado = 5; }

  //dependiendo del estado se prenderan los leds
  switch (estado) {
    case 0:
      digitalWrite(PinLedUno,LOW);
      digitalWrite(PinLedDos,LOW);
      digitalWrite(PinLedTres,LOW);
      digitalWrite(PinLedCuatro,LOW);
      digitalWrite(PinLedCinco,LOW);
      Serial.println("0 leds encendidos");
      break;
    case 1:
      digitalWrite(PinLedUno,HIGH);
      digitalWrite(PinLedDos,LOW);
      digitalWrite(PinLedTres,LOW);
      digitalWrite(PinLedCuatro,LOW);
      digitalWrite(PinLedCinco,LOW);
      Serial.println("1 leds encendidos");
      break;
    case 2:
      digitalWrite(PinLedUno,HIGH);
      digitalWrite(PinLedDos,HIGH);
      digitalWrite(PinLedTres,LOW);
      digitalWrite(PinLedCuatro,LOW);
      digitalWrite(PinLedCinco,LOW);
      Serial.println("2 leds encendidos");
      break;
    case 3:
      digitalWrite(PinLedUno,HIGH);
      digitalWrite(PinLedDos,HIGH);
      digitalWrite(PinLedTres,HIGH);
      digitalWrite(PinLedCuatro,LOW);
      digitalWrite(PinLedCinco,LOW);
      Serial.println("3 leds encendidos");
      break;
    case 4:
      digitalWrite(PinLedUno,HIGH);
      digitalWrite(PinLedDos,HIGH);
      digitalWrite(PinLedTres,HIGH);
      digitalWrite(PinLedCuatro,HIGH);
      digitalWrite(PinLedCinco,LOW);
      Serial.println("4 leds encendidos");
      break;
    case 5:
      digitalWrite(PinLedUno,HIGH);
      digitalWrite(PinLedDos,HIGH);
      digitalWrite(PinLedTres,HIGH);
      digitalWrite(PinLedCuatro,HIGH);
      digitalWrite(PinLedCinco,HIGH);
      Serial.println("5 leds encendidos");
      break;
    default:
      Serial.println("Aún no hay nada");
      break;
  }
  Serial.println(iAnalog);
  delay(1000);
}
