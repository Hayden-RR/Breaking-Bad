//god code
//holy crap im tired
#include <Servo.h>

// Create Servo objects
Servo waltServo;   // Servo for Walter (Interaction 1)
Servo rvServo;     // Servo for the RV (Interaction 2)
Servo jesseServo;  // Servo for Jesse (Interaction 4)

// ---- Pin Definitions ----
// Walter (Interaction 1)
const int waltServoPin = 9;   // Pin connected to Walter's servo
const int waltSwitchPin = 7;  // Pin connected to Walter's copper tape switch

// RV (Interaction 2)
const int rvSwitchPin = 8;    // Pin connected to the RV's copper tape switch
const int rvServoPin = 10;    // Pin connected to the RV's 360-degree servo

// TV (Interaction 3)
const int tvSwitchPin = 11;   // Pin connected to the TV's copper tape switch
const int tvLedPin = 12;      // Pin connected to the TV LED

// Jesse (Interaction 4)
const int jesseSwitchPin = 6; // Pin connected to Jesse's copper tape switch
const int jesseServoPin = 5;  // Pin connected to Jesse's servo

// Lab (Interaction 5)
const int labSwitchPin = 4;   // Pin connected to the lab's copper tape switch
const int labLedPin = 3;      // Pin connected to the lab LED

// ---- Interaction 6: Driving Away ----
const int driveAwaySwitchPin = 2;   // Pin connected to the driving away switch
bool isDrivingAway = false;          // State for driving away

// ---- State Variables ----
// RV state
bool rvActivated = false;

// TV state
bool switchActivated = false; // For Interaction 3
unsigned long switchPressTime = 0; // Time when the switch was pressed
const unsigned long ledDuration = 3000; // LED on duration (3 seconds)

// Smooth movement for Walter's servo
int waltServoPosition = 0;   // Current position of Walter's servo
int waltTargetPosition = 0;  // Target position of Walter's servo

void setup() {
  // Attach the servos to their respective pins
  waltServo.attach(waltServoPin);
  rvServo.attach(rvServoPin);
  jesseServo.attach(jesseServoPin);

  // Set up the switch pins as inputs with pull-up resistors
  pinMode(waltSwitchPin, INPUT_PULLUP);
  pinMode(rvSwitchPin, INPUT_PULLUP);
  pinMode(tvSwitchPin, INPUT_PULLUP);
  pinMode(jesseSwitchPin, INPUT_PULLUP);
  pinMode(labSwitchPin, INPUT_PULLUP);
  pinMode(driveAwaySwitchPin, INPUT_PULLUP); // Set up the switch pin for driving away

  // Set up the LED pins as outputs
  pinMode(tvLedPin, OUTPUT);
  pinMode(labLedPin, OUTPUT);

  // Initialize components to their starting states
  waltServo.write(0);    // Walter's servo starts at 0 degrees
  rvServo.write(90);     // RV's servo stationary position
  jesseServo.write(0);   // Jesse's servo starts at 0 degrees
  digitalWrite(tvLedPin, LOW); // Ensure the TV LED is initially off
  digitalWrite(labLedPin, LOW); // Ensure the lab LED is initially off
}

void loop() {
  // ---- Interaction 1: Walter Washing Car ----
  int waltSwitchState = digitalRead(waltSwitchPin); // Read Walter's switch state
  if (waltSwitchState == LOW) {
    waltTargetPosition = 0;  // Rotate to 0 degrees
  } else {
    waltTargetPosition = 20; // Return to 20 degrees
  }

  // Gradually move Walter's servo to the target position
  if (waltServoPosition < waltTargetPosition) {
    waltServoPosition++;
    waltServo.write(waltServoPosition);
    delay(15);  // Adjust speed
  } else if (waltServoPosition > waltTargetPosition) {
    waltServoPosition--;
    waltServo.write(waltServoPosition);
    delay(15);  // Adjust speed
  }
  
  // ---- Interaction 6: Driving Away ----
  int driveAwaySwitchState = digitalRead(driveAwaySwitchPin); // Read the driving away switch state
  if (driveAwaySwitchState == HIGH && !isDrivingAway) {
    isDrivingAway = true;             // Set the state to driving away
    rvActivated = true;               // Block Interaction 2 during driving away

    // Rotate the RV servo to simulate the "driving away" action
    for (int i = 0; i < 23; i++) { // Rotate the servo 24 times for a full "driving away" effect
      rvServo.write(180);    // Rotate the 360-degree servo
      delay(300);            // Wait for the servo to complete the rotation
      rvServo.write(90);     // Return to the stationary position
      delay(50);             // Wait for stability before the next rotation
    }

    // Reset the flag after the interaction is complete
    isDrivingAway = false;
    rvActivated = false; // Allow RV interactions again
  }

  // ---- Interaction 2: RV Opening ----
  int rvSwitchState = digitalRead(rvSwitchPin); // Read RV's switch state
  if (rvSwitchState == HIGH && !rvActivated && !isDrivingAway) {
    rvActivated = true;  // Set the activation flag
    for (int i = 0; i < 23; i++) { // Rotate the servo counterclockwise 6 times
      rvServo.write(0);   // Rotate the servo counterclockwise
      delay(300);         // Adjust for one full rotation
      rvServo.write(90);  // Stop the servo
      delay(50);          // Short delay between rotations
    }
  }

  // ---- Interaction 3: TV Lighting Up ----
  int tvSwitchState = digitalRead(tvSwitchPin); // Read TV's switch state
  if (tvSwitchState == HIGH && !switchActivated) {
    switchActivated = true; // Set the bool to true when the switch is pressed
    digitalWrite(tvLedPin, HIGH);  // Turn on the LED
    switchPressTime = millis();  // Record the time when the switch was pressed
  }

  // If the LED has been on for the set duration (3 seconds), turn it off
  if (switchActivated && (millis() - switchPressTime >= ledDuration)) {
    digitalWrite(tvLedPin, LOW);   // Turn off the LED
    switchActivated = false;       // Reset the flag
  }

  // ---- Interaction 4: Jesse Falling ----
  int jesseSwitchState = digitalRead(jesseSwitchPin); // Read Jesse's switch state
  if (jesseSwitchState == LOW) {
    jesseServo.write(80); // Rotate to 80 degrees
  } else {
    jesseServo.write(0); // Return to 0 degrees
  }

  // ---- Interaction 5: Lab Activity ----
  int labSwitchState = digitalRead(labSwitchPin); // Read Lab's switch state
  if (labSwitchState == LOW) {
    digitalWrite(labLedPin, LOW); // Turn on the lab LED
  } else {
    digitalWrite(labLedPin, HIGH);  // Turn off the lab LED
  }

  // Short delay for loop stability
  delay(50);
}
