#include <Joystick.h>

const int analogPin = 27;
const int analogPin2 = 26;
const int digitalPin = 22;
String gear_string = "";

void setup() {
  Serial.begin(115200);
  Joystick.begin();
  pinMode(digitalPin, INPUT);
  Joystick.
}

void loop() {
  int y = analogRead(analogPin);
  int x = analogRead(analogPin2);
  int reverse = digitalRead(digitalPin);
  int gear = calculateGear(y, x, reverse);

  if (gear == 0) {
    gear_string = "N";
  }
  if (gear == 1) {
    Joystick.button(1, true);
    gear_string = "1";
  } else {
    Joystick.button(1, false);
  }
  if (gear == 2) {
    Joystick.button(2, true);
    gear_string = "2";
  } else {
    Joystick.button(2, false);
  }
  if (gear == 3) {
    Joystick.button(3, true);
    gear_string = "3";
  } else {
    Joystick.button(3, false);
  }
  if (gear == 4) {
    Joystick.button(4, true);
    gear_string = "4";
  } else {
    Joystick.button(4, false);
  }
  if (gear == 5) {
    Joystick.button(5, true);
    gear_string = "5";
  } else {
    Joystick.button(5, false);
  }
  if (gear == 6) {
    Joystick.button(6, true);
    gear_string = "6";
  } else {
    Joystick.button(6, false);
  }
  if (gear == 7) {
    Joystick.button(7, true);
    gear_string = "R";
  } else {
    Joystick.button(7, false);
  }

  Serial.println(gear_string);
  Joystick.send_now();
  delay(100);
}

int calculateGear(int y, int x, int reverse) {
  if (reverse == 1 && 650 < x && y < 150) {
    return 7;
  } else if (y > 750 && y < 1023) {
    return (x > 0 && x < 400) ? 1 : (x > 450 && x < 600) ? 3 : (x > 650 && x < 1023) ? 5 : 0;
  } else if (y > 0 && y < 150) {
    return (x > 0 && x < 400) ? 2 : (x > 450 && x < 600) ? 4 : (x > 650 && x < 1023) ? 6 : 0;
  }
  return 0;
}
