# Arduino Pomodoro Timer

A physical pomodoro timer built with an Arduino to make me more likely to study because I built it myself.

## Features
- 25-minute work timer
- 5-minute break timer
- LCD display showing time elapsed (after 25 min, 5 min rest starts automatically)
- LED status indicators
- Button controls for start and pause

## Hardware Components
- Arduino UNO
- 16x2 LCD Display
- Push button
- LED indicators (Blue for rest, Green for clock ticking, Red for clock paused)
- Breadboard
- Resistors
- Potentiometer to control brightness of LCD display

## Circuit Setup
[Coming Soon]

## Code Overview
The main program uses:
- `LiquidCrystal` library for LCD control
- Timer interrupts for accurate timing
- Debounced button inputs
- State machine for timer logic

## Future Improvements
- Add custom time settings
- Add Stop Feature to totally end session 
- Add sound control to signal end of timers


## Demo
https://github.com/user-attachments/assets/fb140f88-5138-4912-9a79-5188392e2b7f
