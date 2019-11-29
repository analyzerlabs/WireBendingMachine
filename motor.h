void motorInit(){
      pinMode(dirPin,OUTPUT);
      pinMode(stepPin,OUTPUT);
      digitalWrite(stepPin,LOW);
      digitalWrite(enablePin,HIGH);
  }

// funcion para hacer funcionar al motor a paso en su
// forma mas basica , speed representa el numero de pasos por segundo

void stepMotor(int speed){
    int t = 4500/speed;
    if(t<1000) t = 1000;
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(600);
    digitalWrite(stepPin,LOW);
    delayMicroseconds(t);
  }
  
void moveMotor(int dir,int vueltas , int speed){
  digitalWrite(dirPin,dir);
  digitalWrite(enablePin,LOW);
  for(int i=0;i<200*vueltas;i++){
      stepMotor(speed);
    }
  
  digitalWrite(enablePin,HIGH);  
}
