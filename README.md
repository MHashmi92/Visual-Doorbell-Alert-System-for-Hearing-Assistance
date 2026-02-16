# Sound Reactive LED System (Arduino Leonardo + MAX9814)

This project implements a real-time sound-to-light system using an Arduino Leonardo, an Adafruit NeoPixel LED strip, and a MAX9814 microphone amplifier module with automatic gain control (AGC). The system continuously samples the analog audio signal and calculates peak-to-peak amplitude to estimate sound intensity. When the detected amplitude exceeds a defined threshold for a sustained duration, the LED strip activates.

## Hardware Used
- Arduino Leonardo
- MAX9814 Microphone Amplifier Module (with AGC)
- Adafruit NeoPixel LED strip (18 LEDs)
- External 5V power supply (recommended for LEDs)
- Jumper wires

## How It Works
1. The MAX9814 outputs an amplified analog audio signal.
2. The Arduino samples the signal multiple times per loop.
3. Peak-to-peak amplitude is calculated (max - min).
4. If amplitude exceeds a preset threshold consistently, LEDs turn ON.
5. Stability logic prevents flickering from short noise spikes.

## Key Concepts Demonstrated
- Embedded signal sampling
- Analog signal processing
- Peak-to-peak amplitude detection
- Threshold-based filtering
- Real-time LED control

## Demo Video

Watch the system detecting doorbell sound and activating the LED alert:
https://youtu.be/WfFuAvrzU5w
## Project Report

The complete ideation and technical report is available below:
[Download Full Report](Visual Doorbell alert ideation Report M1)

## Notes
- The MAX9814 includes automatic gain control (AGC), which helps maintain stable output levels.
- Threshold value may need adjustment depending on environment noise.
