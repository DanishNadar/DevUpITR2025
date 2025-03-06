int MotorPin1 = 3;
int MotorPin2 = 4;
int speedPin = 0;
void setup() {
  pinMode(MotorPin1,OUTPUT);
  pinMode(MotorPin2,OUTPUT);
  pinMode(speedPin,OUTPUT);
 
}
 
// void loop() {
//   // put your main code here, to run repeatedly:
//   digitalWrite(MotorPin1,HIGH);
//   digitalWrite(MotorPin2,LOW);
 
//   analogWrite(speedPin,(255/2));
//   delay(1000);
 
//   digitalWrite(MotorPin1,LOW);
//   digitalWrite(MotorPin2,HIGH);
 
//   analogWrite(speedPin,(255/2));
//   delay(1000);
// }

// Choose a speed and # of times to reiterate
// Possible speed range from 0 to 255
void theFastAndTheFurious(int speed, int tiems = 1){

    for(int i = 0; i < times; i++){
      analogWrite(speedPin, speed);
      delay(500);
    }
  }
}

// Choose a rotation and # of times to reiterate
// Forward (1) -> High then Low
// Bakcward (-1) -> Low -> High
void theRollyPolly(int rollDirection, int times = 1, swap = false){
  for(int i = 0; i < times; i++){
    if(rollDirection == 1){
      digitalWrite(MotorPin1,HIGH);
      digitalWrite(MotorPin2,LOW);
      delay(500)
    }
    if(rollDirection == -1){
      digitalWrite(MotorPin2,HIGH);
      digitalWrite(MotorPin1,LOW);
      delay(500)
    }
  }
}

void notReallyAMacro(){
  // Include whatever function calls you want
  /*
  theRollyPolly(1, 3);
  theFastAndTheFurious(50,1);
  theFastAndTheFurious(100,1);
  theFastAndTheFurious(150,1);
  theFastAndTheFurious(200,1);
  theRollyPolly(-1,3);
  theFastAndTheFurious(255,1);
  */ 
}

