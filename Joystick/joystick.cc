int x_pin_1 = A9;
int y_pin_1 = A11;

int x_pin_2 = A13;
int y_pin_2 = A15;

int switch_button = 43;
int switch_button_2 = 45;

void setup() {
  Serial.begin(9600);

  pinMode(x_pin_1, INPUT);
  pinMode(y_pin_1, INPUT);
  pinMode(x_pin_2, INPUT);
  pinMode(y_pin_2, INPUT);

  pinMode(switch_button, INPUT_PULLUP);
  pinMode(switch_button_2, INPUT_PULLUP);
}

void loop() {
  int xVal1 = analogRead(x_pin_1);
  int yVal1 = analogRead(y_pin_1);
  int xVal2 = analogRead(x_pin_2);
  int yVal2 = analogRead(y_pin_2);

  int buttonState1 = digitalRead(switch_button);
  int buttonState2 = digitalRead(switch_button_2);

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
