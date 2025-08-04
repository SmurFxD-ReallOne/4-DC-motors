# 4-DC-Motors Control System

A comprehensive Arduino-based control system for 4 DC motors with obstacle avoidance capabilities using L293D motor drivers, ultrasonic sensor, and servo motor.

## Overview

This project implements a complete motor control system that can:
- Control 4 DC motors simultaneously
- Perform forward and backward movements
- Execute turning maneuvers
- Detect obstacles using ultrasonic sensor
- Automatically change direction when obstacles are detected
- Control servo motor for additional functionality

## Demo

![4-DC-Motors Control System Demo](dc.gif)

*Demonstration of the 4-DC-motors control system in action*

## Hardware Requirements

### Components
- Arduino Uno R3
- 2x L293D Motor Driver ICs
- 4x DC Motors
- 1x HC-SR04 Ultrasonic Sensor
- 1x Servo Motor
- Breadboard
- Jumper Wires
- Power Supply (5V and 12V)



## Features

### Movement Patterns
1. **Forward Movement**: 30 seconds duration
2. **Backward Movement**: 1 minute duration
3. **Alternating Turns**: Right and left turns for 1 minute
4. **Obstacle Avoidance**: Automatic direction change when obstacles detected within 10cm

### Safety Features
- Automatic motor stop when obstacles detected
- Direction reversal capability
- Continuous monitoring of surroundings
- Serial output for debugging and monitoring

## Installation

1. Clone this repository:
```bash
git clone https://github.com/SmurFxD-ReallOne/4-DC-motors.git
```

2. Open the Arduino IDE

3. Load the `dc_motor_control.ino` file

4. Connect the hardware according to the detailed wiring guide in PIN_CONNECTIONS.txt

5. Upload the code to your Arduino Uno

## Usage

After uploading the code:

1. Power on the system
2. The servo motor will move to center position (90°)
3. The system will start the movement sequence automatically
4. Monitor the Serial Monitor for status updates
5. The system will continuously cycle through the movement patterns

## Serial Output

The system provides real-time feedback through the Serial Monitor:
- Distance measurements from ultrasonic sensor
- Movement status updates
- Obstacle detection alerts
- Direction change notifications

## Technical Specifications

- **Motor Speed**: 200 PWM (0-255 range)
- **Obstacle Detection Range**: 10cm
- **Servo Position**: 90° center position
- **Serial Communication**: 9600 baud rate
- **Power Requirements**: 5V for logic, 12V for motors

## Troubleshooting

### Common Issues
- **Motors not moving**: Check power connections and enable pins
- **Wrong motor direction**: Swap motor terminal connections
- **Ultrasonic not working**: Verify TRIG and ECHO connections
- **Servo not responding**: Check signal wire connection to Pin A0

### Testing
Use the Serial Monitor to verify:
- Distance readings from ultrasonic sensor
- Motor movement commands
- System status messages

## Project Structure

```
4-DC-motors/
├── dc_motor_control.ino          # Main Arduino code
├── README.md                     # This file
├── PIN_CONNECTIONS.txt           # Detailed wiring guide
└── dc.gif                        # Demonstration GIF
```

## Author

**Muaad Al-Ghashmari**

Repository: [https://github.com/SmurFxD-ReallOne/4-DC-motors](https://github.com/SmurFxD-ReallOne/4-DC-motors)

## License

This project is open source and available under the MIT License.

## Contributing

Feel free to submit issues and enhancement requests.

---

For detailed wiring instructions, see `PIN_CONNECTIONS.txt`
