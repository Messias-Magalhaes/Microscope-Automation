// Include the Arduino Stepper.h library:
#include <AccelStepper.h> //Include the AccelStepper library
 
// Define the motor pins:
#define MP1  4 // IN1 on the ULN2003
#define MP2  5 // IN2 on the ULN2003
#define MP3  6 // IN3 on the ULN2003
#define MP4  7 // IN4 on the ULN2003

#define MP5  8 // IN1 on the ULN2003
#define MP6  9 // IN2 on the ULN2003
#define MP7  10 // IN3 on the ULN2003
#define MP8  11 // IN4 on the ULN2003
 
#define MotorInterfaceType 8 // Define the interface type as 8 = 4 wires * step factor (2 for half step)

AccelStepper stepper1 = AccelStepper(MotorInterfaceType, MP1, MP3, MP2, MP4);//Define the pin sequence (IN1-IN3-IN2-IN4)
AccelStepper stepper2 = AccelStepper(MotorInterfaceType, MP5, MP7, MP6, MP8);//Define the pin sequence (IN1-IN3-IN2-IN4)

char c;
bool state1 = false;
bool state2 = false;
bool oldstate2 = false;
 
void setup() {
  Serial.begin(9600);
  stepper1.setMaxSpeed(1000);//Set the maximum motor speed in steps per second
  stepper1.setAcceleration(200);//Set the maximum acceleration in steps per second^2
  stepper2.setMaxSpeed(1000);//Set the maximum motor speed in steps per second
  stepper2.setAcceleration(200);//Set the maximum acceleration in steps per second^2
}

// Clear the serial buffer 
void serialFlush(){
  while(Serial.available() > 0) {
    char c = Serial.read();
  }
}
 
void loop() {

    c = Serial.read();

    // Start looping
    if(c == 'i'){
      if(oldstate2 == true){
        state1 = false;
        state2 = true;
      }
      else{
        state2 = false;
        state1 = true;
      }
    }

    // Stop looping
    if(c == 'p'){
      oldstate2 = state2;
      state1 = false;
      state2 = false;
    }

    if(state1 == true){
      stepper1.moveTo(10); // Set a target position to LEFT
      stepper1.runToPosition(); // Run the motor to the target position 
      stepper1.setCurrentPosition(0); // Reset a target position to start
    }

    if(state2 == true){
      stepper1.moveTo(-10); // Set a target position to RIGHT
      stepper1.runToPosition(); // Run the motor to the target position 
      stepper1.setCurrentPosition(0); // Reset a target position to start
    }

    // Step DOWN and reverse the direction of the steps 
    if(c == 't'){
      stepper2.moveTo(100); // Set a target position to DOWN
      stepper2.runToPosition(); // Run the motor to the target position 
      stepper2.setCurrentPosition(0); // Reset a target position to start
      state1 = !state1; // Reverse the direction of the steps
      state2 = !state2; // Reverse the direction of the steps
    }

     if (c == '8'){
      stepper2.moveTo(-10); // Set a target position to UP
      stepper2.runToPosition(); // Run the motor to the target position 
      stepper2.setCurrentPosition(0); // Reset a target position to start
      serialFlush(); // Clean the serial buffer    
    }

    if (c == '2'){
      stepper2.moveTo(10);  // Set a target position to DOWN
      stepper2.runToPosition(); // Run the motor to the target position 
      stepper2.setCurrentPosition(0); // Reset a target position to start
      serialFlush(); // Clean the serial buffer              
     }

    if (c == '4'){
      stepper1.moveTo(10); // Set a target position to LEFT
      stepper1.runToPosition(); // Run the motor to the target position 
      stepper1.setCurrentPosition(0); // Reset a target position to start
      serialFlush(); // Clean the serial buffer    
    }

    if (c == '6'){
      stepper1.moveTo(-10); // Set a target position to RIGHT
      stepper1.runToPosition(); // Run the motor to the target position 
      stepper1.setCurrentPosition(0); // Reset a target position to start
      serialFlush(); // Clean the serial buffer     
    }

}