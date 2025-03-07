int MotorPin1 = 3;
int MotorPin2 = 4;
int speedPin = 0;
void setup() {
  pinMode(MotorPin1,OUTPUT);
  pinMode(MotorPin2,OUTPUT);
  pinMode(speedPin,OUTPUT);
 
}
 
// Choose a speed and # of times to reiterate
// Possible speed range from 0 to 255
void theFast(int speed = 20, int times = 1, int increaseValue = 50){
    for(int i = 0; i < times; i++){
      analogWrite(speedPin, speed);
      delay(100);
      if(increaseValue){
        speed += increaseValue;
      }
    }
  }

// Choose a rotation and # of times to reiterate
// Forward (1) -> High then Low
// Bakcward (-1) -> Low -> High
void theFurious(int rollDirection = 1, int times = 1, bool swap = false){
  for(int i = 0; i < times; i++){
    if(rollDirection == 1){
      digitalWrite(MotorPin1,HIGH);
      digitalWrite(MotorPin2,LOW);
      delay(100);
    }
    if(rollDirection == -1){
      digitalWrite(MotorPin2,HIGH);
      digitalWrite(MotorPin1,LOW);
      delay(100);
    }
    // Swaps rotation direction forward and backward
    if(swap == true && rollDirection == 1){
      rollDirection = -1; 
    } else{
      rollDirection = 1;
    }
  }
}

void notReallyAMacro(){
  // Include whatever function calls you want
  /*
  theFast(speed = 50, times = 1);
  theFast(speed = 50, times = 3);
  theFurious(roll = 1, times = 4, swap = true);
  theFast(speed = 50, times = 5, increaseValue = 50)
  */ 

  // Below is a test 'macro'

  //Initialized variables (default)
  int speed = 10;
  int times = 1;
  int increaseValue = 25;
  bool roll = false;
  bool swap = false;

  theFast(speed = 50, times = 1);
  theFast(speed = 50, times = 3);
  theFurious(roll = 1, times = 1);
  theFast(speed = 50, times = 5, increaseValue = 50);
  theFurious(roll = -1, times = 4, swap = true);
}

void loop() {
  notReallyAMacro();
}
