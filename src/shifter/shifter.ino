#include <Joystick.h>

// Define the analog input pins
const int analogPin = 27;
const int analogPin2 = 26;
const int digitalPin = 22;

void setup() {
  // Initialize serial communication
  Serial.begin(115200);
  Joystick.begin();
}

void loop() {
  int y = analogRead(analogPin);
  int x = analogRead(analogPin2);
  int reverse = digitalRead(digitalPin);
  String gear_string;
  int gear = calculateGear(y, x, reverse);

  if (gear == 0) {
    Joystick.button(0, true);
    gear_string = "N";
  } else {
    Joystick.button(0, false);
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



  // switch (calculateGear(y, x, reverse)) {
  //   case 0:
  //     Joystick.button(0, true);
  //     gear_string = "N";
  //     break;
  //   case 1:
  //     Joystick.button(1, true);
  //     gear_string = "1";
  //     break;
  //   case 2:
  //     Joystick.button(2, true);
  //     gear_string = "2";
  //     break;
  //   case 3:
  //     Joystick.button(3, true);
  //     gear_string = "3";
  //     break;
  //   case 4:
  //     Joystick.button(4, true);
  //     gear_string = "4";
  //     break;
  //   case 5:
  //     Joystick.button(5, true);
  //     gear_string = "5";
  //     break;
  //   case 6:
  //     Joystick.button(6, true);
  //     gear_string = "6";
  //     break;
  //   case 7:
  //     Joystick.button(7, true);
  //     gear_string = "R";
  //     break;
  // }
  Serial.println(gear_string);
  Joystick.send_now();
  delay(100);
}

int calculateGear(int y, int x, int reverse) {
  if (reverse == 1 && 650 < x && y < 150) {
    return 7;
  } else {
    if (y > 750 && y < 1023) {
      if (x > 0 && x < 400) {
        return 1;
      } else if (x > 450 && x < 600) {
        return 3;
      } else if (x > 650 && x < 1023) {
        return 5;
      }
    } else if (y > 0 && y < 150) {
      if (x > 0 && x < 400) {
        return 2;
      } else if (x > 450 && x < 600) {
        return 4;
      } else if (x > 650 && x < 1023) {
        return 6;
      }
    }
  }
  return 0;
}
