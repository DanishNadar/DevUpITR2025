int MotorPin1 = 3;
int MotorPin2 = 4;
int speedPin = 0;
void setup() {
  pinMode(MotorPin1,OUTPUT);
  pinMode(MotorPin2,OUTPUT);
  pinMode(speedPin,OUTPUT);
}

// Choose a rotation and # of times to reiterate
// Forward (1) -> High then Low
// Bakcward (-1) -> Low -> High

// Choose a speed and # of times to reiterate
// Possible speed range from 0 to 255

void driverControl(int speed, int increaseValue, int rollDirection, int times, bool swap){
  for(int i = 0; i < times; i++){
    analogWrite(speedPin, speed);
    digitalWrite(MotorPin1,HIGH);
    digitalWrite(MotorPin2,LOW);

    if(increaseValue){
      speed += increaseValue;
    }

    if(swap == true && rollDirection == 1){
      rollDirection = -1; 
    } else{
      rollDirection = 1;
    }

    delay(500);
  }
}

void notReallyAMacro(){
  driverControl(50, 50, 1, 4, true);
}

void loop() {
  notReallyAMacro();
}
