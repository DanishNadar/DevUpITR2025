int MotorPin1 = 3;
int MotorPin2 = 4;
int speedPin = 0;
void setup() {
  pinMode(MotorPin1,OUTPUT);
  pinMode(MotorPin2,OUTPUT);
  pinMode(speedPin,OUTPUT);
 
}
 
void loop() {
  notReallyAMacro();
}

// Choose a speed and # of times to reiterate
// Possible speed range from 0 to 255
void theFast(int speed, int times = 1, int increaseValue = 50){
    for(int i = 0; i < times; i++){
      analogWrite(speedPin, speed);
      delay(500);
      if(increaseValue){
        speed += increaseValue;
      }
    }
  }
}

// Choose a rotation and # of times to reiterate
// Forward (1) -> High then Low
// Bakcward (-1) -> Low -> High
void theFurious(int rollDirection, int times = 1, swap flip = false){
  for(int i = 0; i < times; i++){
    if(rollDirection == 1){
      digitalWrite(MotorPin1,HIGH);
      digitalWrite(MotorPin2,LOW);
      delay(500);
    }
    if(rollDirection == -1){
      digitalWrite(MotorPin2,HIGH);
      digitalWrite(MotorPin1,LOW);
      delay(500);
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
  theFast(speed = 50, times = 1);
  theFast(speed = 50, times = 3);
  theFurious(roll = 1, times = 1);
  theFast(speed = 50, times = 5, increaseValue = 50)
  theFurious(roll = -1, times = 4, swap = true)
}

