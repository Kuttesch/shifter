# G29 Shifter PI Pico
This is a project to convert a Logitech G29 shifter to USB using a Raspberry Pi Pico. For everyone that has a G29 shifter and wants to use it on a PC without the wheel, this is the project for you.

## Table of Contents
- [G29 Shifter PI Pico](#g29-shifter-pi-pico)
  - [Table of Contents](#table-of-contents)
  - [Idea/Why](#ideawhy)
  - [Requirements](#requirements)
  - [Hardware](#hardware)
  - [Software](#software)
  - [Usage](#usage)
  - [Contributing](#contributing)
    - [Using VSCode](#using-vscode)
  - [License](#license)

## Idea/Why
I personally do not like the idea of constraining the user to have to buy another product to use one that is pretty good and useful on it's own. The G29 shifter is a great shifter and it is a shame that it is not usable on it's own. This project aims to fix that.

## Requirements
You will need the following to complete this project:
- Logitech G29 Shifter
- Raspberry Pi Pico
- Soldering Iron
- Ambition

## Hardware
To convert the Shifter to USB, you will need to solder the wires from the shifter to the Raspberry Pi Pico. Forward I would like to provide a PCB that will make this process easier, but for now, you will have to solder the wires directly to the Pico.

You will need to completely remove the PCB from the shifter, because we intercept the wires from the components directly. The shifter has 7 wires that we need to connect the pico as follows:

Black & Black -> GND  
Yellow & Yellow -> 3.3V  
Brown (Y-Axis) -> GP27  
Red (X-Axis) -> GP26  
Orange (Reverse Manipulator) -> GP22

![Fritzing Diagram](/doc/src/fritzing.png)

After that you will have to flash the firmware to the Pico how it is described in the [Software](#software) section.

After that you can hide the pico in the shifter where the old PCB was and close the shifter up.

## Software
The software is written in C++ and uses the [Pico Libary]() and the [Joystick Library](). The software is pretty simple and should describe itself. If you have any questions, feel free to ask.

To flash the firmware you can use the [Arduino IDE](https://www.arduino.cc/en/software) or [VSCode](https://code.visualstudio.com/) with the [Arduino Plugin](https://marketplace.visualstudio.com/items?itemName=vsciot-vscode.vscode-arduino). The firmware is located in the `src\shifter` folder.

To flash the firmware you can follow the following steps:

1. Install the Arduino IDE or VSCode with the Arduino Plugin
2. Install the Pico Libary and the Joystick Library
3. Open the `shifter.ino` file
4. Connect the Pico to your PC while holding the BOOTSEL button
5. Select the Pico as the target device
6. Click on the upload button
7. Done

After that you can connect the shifter to your PC and it should work as a normal USB Gamecontroller.

## Usage
The shifter will be recognized as a normal USB Gamecontroller named `pico`.
It should be picked up by all games with controller support. If you have any issues, feel free to ask.

The buttons are mapped as follows:
- Button 1: 1st Gear
- Button 2: 2nd Gear
- Button 3: 3rd Gear
- Button 4: 4th Gear
- Button 5: 5th Gear
- Button 6: 6th Gear
- Button 7: Reverse Gear

## Contributing
If you have any ideas or want to contribute to this project, feel free to open an issue or a pull request. I am happy about any help I can get.

### Using VSCode
I have provided the .vscode folder with the settings that work for me, because it's a bit of a struggle to get the Pico SDK to work with VSCode. Simply edit the Usernames in the `c_cpp_properties.json` and the `settings.json` file and you should be good to go.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.