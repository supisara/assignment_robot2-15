int LeftSensor;
int RightSensor;
int Ref=500;
void setup(){
pinMode(3,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(9,OUTPUT);
}
void Forward(int speed){
analogWrite(3,speed);
digitalWrite(5,LOW);
analogWrite(6,speed);
digitalWrite(9,LOW);
}
void Spin_Left(int speed){
analogWrite(5,speed);
digitalWrite(3,LOW);
analogWrite(6,speed);
digitalWrite(9,LOW);
}
void Spin_Right(int speed){
analogWrite(3,speed);
digitalWrite(5,LOW);
analogWrite(9,speed);
digitalWrite(6,LOW);
}
void loop(){
LeftSensor = analogRead(3);
RightSensor = analogRead(1);
if ((LeftSensor>Ref)&&(RightSensor>Ref))
{
  Forward(175);
}
  if ((LeftSensor<Ref)&&(RightSensor>Ref)){
    Spin_Left(150);delay(50);
  }
  if ((LeftSensor>Ref)&&(RightSensor<Ref)){
    Spin_Right(150);delay(50);
  }
}


