const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;   //constantes de los pines para el control de la pantalla LCD16x2
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);                //inicializacion de la pantalla lcd 16X2
SHCSR04 hcsr04;           //Inicializacion del sensor HCSR04
Servo iris;
const byte interruptPin = 20;    //constante para el control de interrupciones del pulsador
boolean control = true;     //variable asignada al pulsador
int distance=0;      //variable para medir distancia
int anterior=0;      //variable auxiliar de distancia
unsigned long t=0;     //variable de tiempo
boolean flag = false;   //variable bandera para el control del juego
int calibrationPin= 19;
int angle=0;
unsigned long t_iris =0;
int dirPin= 15;
int stepPin = 14;
int enablePin = 16;
int iris_state=0;
boolean calibrationFlag = true;
int maxSteps = 8200;
int pelotas = 0;    //variable de conteo de pelotas
byte heart[8] =     //variable para generar el caracter Corazon
{
0b00000,
0b00000,
0b01010,
0b11111,
0b11111,
0b01110,
0b00100,
0b00000
};

byte R1[8] =
{
0b11111,
0b11111,
0b11111,
0b11111,
0b11111,
0b11111,
0b11111,
0b11111,
};

byte happy[8] ={   //variable para generar el caracter carita feliz
0b00000,
0b01010,
0b01010,
0b00000,
0b00001,
0b01110,
0b00000,
0b00000,
};

byte sad[8] =     //variable para generar el caracter carita triste
{
0b00000,
0b01010,
0b01010,
0b00000,
0b00000,
0b01110,
0b00001,
0b00000,
};

byte pong1[8] =     //variable para generar el caracter pelota arriba
{
0b00000,
0b00000,
0b01110,
0b11111,
0b11111,
0b11111,
0b01110,
0b00000,
};

byte pong2[8] =     //variable para generar el caracter pelota abajo
{
0b00000,
0b01110,
0b11111,
0b11111,
0b11111,
0b01110,
0b00000,
0b00000,
};

byte reloj1[8] =    //variable para generar el caracter reloj de arena lleno
{
0b11111,
0b10001,
0b01110,
0b00100,
0b01010,
0b10001,
0b10001,
0b11111,
};

byte reloj2[8] =     //variable para generar el caracter reloj de arena vacio
{
0b11111,
0b10001,
0b01110,
0b00100,
0b01010,
0b10001,
0b11111,
0b11111,
};

//Funcion para generar retraso de tiempo
void wait(int tiempo){      
  unsigned long T = millis();
  while(millis()<T+tiempo){}
}
