// Pin assignments
const int output_pin_white = 6;
const int output_pin_green = 7;
const int output_pin_red = 8;
const int input_pin = 9;

// Current state
int iter = 6;

void setup() {
  pinMode(output_pin_white, OUTPUT);
  pinMode(output_pin_green, OUTPUT);
  pinMode(output_pin_red, OUTPUT);
  pinMode(input_pin, INPUT);
}

void loop() {
  // Cycle iter from 6 to 8
  if (iter > 8) {
    iter = 6;
  }

  // Set LED output based on current iter value
  digitalWrite(output_pin_white, iter == 6 ? HIGH : LOW);
  digitalWrite(output_pin_green, iter == 7 ? HIGH : LOW);
  digitalWrite(output_pin_red, iter == 8 ? HIGH : LOW);

  // Check for input and increment iter with basic debounce
  if (digitalRead(input_pin) == HIGH) {
    delay(200); // Debounce delay
    while (digitalRead(input_pin) == HIGH); // Wait for button release
    iter++;
  }
}
