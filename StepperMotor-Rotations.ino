#include <Stepper.h>
const int rotate_times = 30; // change this to fit the number of steps per revolution for your motor
const int steps_in_one_revolution = 200;
const int stepsPerRevolution = (steps_in_one_revolution * rotate_times); 
int motorSpeed = 500;
// initialize the stepper library on pins 2 and 3:
Stepper myStepper(stepsPerRevolution, 2, 3);

void setup() {
  
  myStepper.setSpeed(motorSpeed);
}

int count = 0; 
bool isClockwise = true; 

void loop() {
      //define the speed of the motor
  
  if (motorSpeed > 0) {
    myStepper.setSpeed(motorSpeed);
    
    if (isClockwise) {
      myStepper.step(stepsPerRevolution);
      ++count;
      
      if (count >=rotate_times) {
        isClockwise = false; // Change the direction to anticlockwise
        count = 0; // Reset count for the next set of rotations
      }
    } else {
      // Move in the anticlockwise direction for a complete rotation
      myStepper.step(-stepsPerRevolution);
      ++count;
      
      if (count >= rotate_times) {
        isClockwise = true; // Change the direction to clockwise
        count = 0; // Reset count for the next set of rotations
      }
    }
  }
}