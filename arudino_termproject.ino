int motorA1 =  8;  //모터
int motorA2  = 7;  
int motorB1 =  10;
int motorB2 =  9; 
int collision1 = 2; //left 충돌 센서
int collision2 = 3; //right 충돌 센서
int trigPin = 4; //초음파 센서
int echoPin = 5;

void setup ( ) {  

  pinMode( motorA1 , OUTPUT);
  pinMode( motorA2 , OUTPUT);
  pinMode( motorB1 , OUTPUT);
  pinMode( motorB2 , OUTPUT);
  pinMode(collision1, INPUT);
  pinMode(collision2, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.begin(9600);
}

void loop ( )  {
  float duration, distance;
  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = ((float)(340 * duration) / 10000) / 2;
  
  if (!digitalRead(collision1) and !digitalRead(collision2)){
    digitalWrite( motorA1 , LOW);
    digitalWrite( motorA2 , HIGH);
    digitalWrite( motorB1 , LOW);
    digitalWrite( motorB2 , HIGH);
    Serial.println("후진 ");
  }else if (!digitalRead(collision1)){
    digitalWrite( motorA1 , LOW);
    digitalWrite( motorA2 , HIGH);
    digitalWrite( motorB1 , HIGH);
    digitalWrite( motorB2 , LOW);
    Serial.println("우회전");
  }else if(!digitalRead(collision2) or distance <= 10){
    digitalWrite( motorA1 , HIGH);
    digitalWrite( motorA2 , LOW);
    digitalWrite( motorB1 , LOW);
    digitalWrite( motorB2 , HIGH);
    Serial.println("좌회전");
  }else{
    digitalWrite( motorA1 , HIGH);
    digitalWrite( motorA2 , LOW);
    digitalWrite( motorB1 , HIGH);
    digitalWrite( motorB2 , LOW);
    Serial.println("전진");
  }
  delay(500);

}
