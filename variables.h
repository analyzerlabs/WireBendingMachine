byte lineButton[] = {46,50,75};
byte fondoPrincipal[] = {31,31,55};
byte letraSecundaria[] = {51,57,71};

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
