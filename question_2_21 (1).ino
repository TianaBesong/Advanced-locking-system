#include <Servo.h>

int button1State = 0;  //The state of the button on pin 2
int button2State = 0;  // The State of the button on pin 3

Servo servo_9;

void setup() {
  pinMode(2, INPUT_PULLUP);   
  pinMode(3, INPUT_PULLUP);   
  pinMode(12, OUTPUT);        
  pinMode(13, OUTPUT);        
  
  servo_9.attach(9);          
  
  Serial.begin(9600);         
}

void loop() {
  // Read button states and invert logic for INPUT_PULLUP
  button1State = !digitalRead(2);  // Button 1: HIGH if pressed
  button2State = !digitalRead(3);  // Button 2: HIGH if pressed

  // LED feedback for button states
  digitalWrite(12, button1State);  // LED 12 on if button 1 is pressed
  digitalWrite(13, button2State);  // LED 13 on if button 2 is pressed

  // If both buttons are pressed, "open" the door by rotating continuously
  if (button1State && button2State) {
    servo_9.write(0);  // Continuous rotation in one direction (open door)
  } else {
    servo_9.write(90); // Stop servo when buttons are released (door closed)
  }

  delay(10);  // Small delay in order  to stabilize loop
}
