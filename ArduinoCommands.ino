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
    // setting speed (user & after increment)
    analogWrite(speedPin, speed);
    
    // rollDirection functionality (if 1 -> forward) (if 2 -> backward)
    if(rollDirection == 1){
      digitalWrite(MotorPin1,HIGH);
      digitalWrite(MotorPin2,LOW);
    } else{
      digitalWrite(MotorPin1,LOW);
      digitalWrite(MotorPin2,HIGH);
    }

    // Increments speed value for each iteration if a value > 0 is provided
    if(increaseValue){
      speed += increaseValue;
    }

    // Swaps direction from forward to backward (vice-versa) if 'swap' argument is given as true
    if(swap == true && rollDirection == 1){
      rollDirection = -1; 
    } else{
      rollDirection = 1;
    }

    // Delay of 300 ms, creating a gap to see visible change in the next iteration 
    delay(300);
  }
}

// Where the students will write their driverControl commands by calling methods with their specified parameters
void notReallyAMacro(){
  // Sample command (for testing)
  driverControl(50, 50, 1, 4, true);
}

// Similar to arduino's main function, which in our case will just call the function with a list of commands to execute. 
void loop() {
  notReallyAMacro();
}
