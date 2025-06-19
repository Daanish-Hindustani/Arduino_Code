#include <Servo.h>

int x_pin_1 = A9;
int y_pin_1 = A11;
int x_pin_2 = A13;
int y_pin_2 = A15;

int switch_button = 43;
int switch_button_2 = 45;

// Define servo objects
Servo servo1;  // Controlled by joystick 1
Servo servo2;  // Controlled by joystick 2

// Define servo pins
int servo1_pin = 6;
int servo2_pin = 9;

void setup() {
  Serial.begin(9600);

  pinMode(x_pin_1, INPUT);
  pinMode(y_pin_1, INPUT);
  pinMode(x_pin_2, INPUT);
  pinMode(y_pin_2, INPUT);

  pinMode(switch_button, INPUT_PULLUP);
  pinMode(switch_button_2, INPUT_PULLUP);

  // Attach servos to pins
  servo1.attach(servo1_pin);
  servo2.attach(servo2_pin);
}

void loop() {
  int xVal1 = analogRead(x_pin_1);
  int yVal1 = analogRead(y_pin_1);
  int xVal2 = analogRead(x_pin_2);
  int yVal2 = analogRead(y_pin_2);

  int buttonState1 = digitalRead(switch_button);
  int buttonState2 = digitalRead(switch_button_2);

  // Map analog joystick values (0–1023) to servo angles (0–180)
  int angle1 = map(xVal1, 0, 1023, 0, 180);
  int angle2 = map(xVal2, 0, 1023, 0, 180);

  // Only move servos when buttons are pressed
  if (buttonState1 == LOW) {
    servo1.write(angle1);
  }

  if (buttonState2 == LOW) {
    servo2.write(angle2);
  }

  // Debug output
  Serial.print("Joystick 1 - X: ");
  Serial.print(xVal1);
  Serial.print(" | Y: ");
  Serial.print(yVal1);

  Serial.print(" || Joystick 2 - X: ");
  Serial.print(xVal2);
  Serial.print(" | Y: ");
  Serial.print(yVal2);

  Serial.print(" || Button 1: ");
  Serial.print(buttonState1 == LOW ? "Pressed" : "Released");

  Serial.print(" | Button 2: ");
  Serial.println(buttonState2 == LOW ? "Pressed" : "Released");

  delay(200);
}
