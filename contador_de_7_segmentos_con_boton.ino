//declaracion
const int a = 2;
const int b = 3;
const int c = 4;
const int d = 5;
const int e = 6;
const int f = 7;
const int g = 8;
const int botonIncremento =9;
const int ledEntrada = 10;
const int buzzPin =11;
const int botonDecremento =12;
const int ledSalida = 13;

const int tiempoAntirebote = 10;
int cuenta = 0;
int estadoBotonIncremento;
int estadoBotonAnteriorIncremento;
int estadoBotonDecremento;
int estadoBotonAnteriorDecremento;
int  buzzDelay = 1;

//funciones de ayuda
boolean antirebote(int pin)
 {
     int contador = 0;
     boolean estado;
     boolean estadoAnterior;

   do
   {
        estado = digitalRead(pin);
    if(estado != estadoAnterior)
     {
      contador = 0;
      estadoAnterior = estado;
    }
    else
     {
      contador = contador + 1;
    }
    delay(1);
  }
   while(contador < tiempoAntirebote);
  return estado;
}

void actualizarNumero() {
  switch(cuenta) {
    case 0:
  digitalWrite(a, HIGH); // NUMERO 0
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, LOW);
  break;
 case 1:
  digitalWrite(a, LOW); // NUMERO 1
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  break;
  case 2:
  digitalWrite(a, HIGH); // NUMERO 2
  digitalWrite(b, HIGH);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, LOW);
  digitalWrite(g, HIGH);
  break;
  case 3:
  digitalWrite(a, HIGH); // NUMERO 3
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, HIGH);
  break;
  case 4:
  digitalWrite(a, LOW); // NUMERO 4
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  break;
  case 5:
  digitalWrite(a, HIGH); // NUMERO 5
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  break;
  case 6:
  digitalWrite(a, HIGH); // NUMERO 6
  digitalWrite(b, LOW);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  break;
  case 7:
  digitalWrite(a, HIGH); // NUMERO 7
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  break;
  case 8:
  digitalWrite(a, HIGH); // NUMERO 8
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  break;
  case 9:
  digitalWrite(a, HIGH); // NUMERO 9
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, LOW);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
  break;
  }
}

void  buzzerErrorSonido (){
    digitalWrite(buzzPin, HIGH);
    digitalWrite(buzzPin, HIGH);
    delayMicroseconds(buzzDelay *2);
    digitalWrite(buzzPin, LOW);
    delayMicroseconds(buzzDelay *2);
}

void  activarBuzzer(){
   digitalWrite(buzzPin, HIGH);
    delayMicroseconds(buzzDelay);
    digitalWrite(buzzPin, LOW);
    delayMicroseconds(buzzDelay);
}

void  activarLedEntrada(){
    digitalWrite(ledEntrada,HIGH);
     delay(50);
     digitalWrite(ledEntrada,LOW);
}

void activarLedSalida() {
    digitalWrite(ledSalida,HIGH);
    delay(50);
    digitalWrite(ledSalida,LOW);
}

void setup() {
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(botonIncremento, INPUT);
  pinMode(botonDecremento, INPUT);
  pinMode(buzzPin, OUTPUT);
  pinMode (ledEntrada, OUTPUT);
  pinMode (ledSalida, OUTPUT);
}

void loop() {
  estadoBotonIncremento = digitalRead(botonIncremento);
  if(estadoBotonIncremento !=estadoBotonAnteriorIncremento) {
    if(antirebote(botonIncremento)) {
       activarBuzzer();
      activarLedEntrada();
      cuenta++;
      if(cuenta > 9) {
        cuenta = 9;
         buzzerErrorSonido();
      }
    }
  }
  estadoBotonAnteriorIncremento = estadoBotonIncremento;

  estadoBotonDecremento = digitalRead(botonDecremento);
  if(estadoBotonDecremento !=estadoBotonAnteriorDecremento) {
    if(antirebote(botonDecremento)) {
      activarBuzzer();
      activarLedSalida();
      cuenta--;
      if(cuenta < 0) {
        cuenta = 0;
        buzzerErrorSonido();
      }
    }
  }
  estadoBotonAnteriorDecremento = estadoBotonDecremento;
   actualizarNumero();
}