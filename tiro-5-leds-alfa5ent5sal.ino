#include <TimerOne.h>

int PULD1 = 11;
int PULD2 = 2;
int PULD3 = 3;
int PULD4 = 4;
int PULD5 = 5;
int LEDD1 = 6;
int LEDD2 = 7;
int LEDD3 = 8;
int LEDD4 = 9;
int LEDD5 = 10;
int PULMARCHA = 12;
int LED7SG = 13;
boolean ACTIVACION = false;     //cuando vale true acepta aciertos (solo durante los 10sg)
boolean VPULD1 = false;         //defino 5 variables booleanas + marcha para
boolean VPULD2 = false;         //trabajar los pulsadores en los if
boolean VPULD3 = false;
boolean VPULD4 = false;
boolean VPULD5 = false;
boolean VPULMARCHA = false;
int ciclos = 0;                 //inicializo ciclos para multiplicar hasta 10sg

void setup() {  
  pinMode(PULMARCHA, INPUT);    //pin 12 como entrada
  pinMode(LED7SG, OUTPUT);      //pin 13 como salida led aviso bloqueo
  pinMode(LED_BUILTIN, OUTPUT); //initialize digital pin LED_BUILTIN as an output.
  pinMode(PULD1, INPUT);        //pin11 como pulsador de diana 1
  pinMode(PULD2, INPUT);        //pin 2 como pulsador de diana 2
  pinMode(PULD3, INPUT);        //pin 3 como pulsador de diana 3
  pinMode(PULD4, INPUT);        //pin 4 como pulsador de diana 4
  pinMode(PULD5, INPUT);        //pin 5 como pulsador de diana 5
  pinMode(LEDD1, OUTPUT);       //establecer los pines de salida como tales
  pinMode(LEDD2, OUTPUT);       //o podría iluminarse tenue debido a la resistencia interna
  pinMode(LEDD3, OUTPUT);
  pinMode(LEDD4, OUTPUT);
  pinMode(LEDD5, OUTPUT);       
}
  
void loop() {
  VPULMARCHA = digitalRead(PULMARCHA);
  if (VPULMARCHA == true){
    digitalWrite(LED7SG, HIGH);
    delay(7000);
    digitalWrite(LED7SG, LOW);
    ACTIVACION = true;
    Timer1.initialize(1000); //un milisegundo para ser multiplicado
    Timer1.attachInterrupt( incrementaCiclo );
  }
  VPULD1 = digitalRead(PULD1);
  if (VPULD1 == true && ACTIVACION == true){
    digitalWrite(LEDD1, HIGH);
  }
  VPULD2 = digitalRead(PULD2);
  if (VPULD2 == true && ACTIVACION == true){
    digitalWrite(LEDD2, HIGH);
  }
  VPULD3 = digitalRead(PULD3);
  if (VPULD3 == true && ACTIVACION == true){
    digitalWrite(LEDD3, HIGH);
  }
  VPULD4 = digitalRead(PULD4);
  if (VPULD4 == true && ACTIVACION == true){
    digitalWrite(LEDD4, HIGH);
  }
  VPULD5 = digitalRead(PULD5);
  if (VPULD5 == true && ACTIVACION == true){
    digitalWrite(LEDD5, HIGH);
  }
  if (ciclos >= 10000){  //aqui multiplico el milisegundo para convertirlo en 10sg
    desactivar();        //pondrá la variable ACTIVACION a false para no aceptar mas aciertos
  }
}

void incrementaCiclo(){
  ciclos ++;
}

void desactivar(){
  ACTIVACION = false;
  digitalWrite(LED7SG, HIGH);
}
