# reactive-target
Arduino 2 mode reactive target for steel plates shooting.

Designed to be attached by magnets or tape to the back of metal target with LEDs visible from the front.
Piezo element detects hits on the target.

Mode selection is done by turning device on in one of the swich positions.

## Mode 1: Static shooting
Each hit is sygnalized by blinking green LED

## Mode 2: Dynamic shooting
In random time between _waitmin_ and _waitmax_ the target will lit Green LED and wait for the hit for random time between _targettimemin_ and _targettimemax_.
If hit is registred in that time window, green LED will blink and the timers will reset. If the hit is not registret , the red LED will blink.

### Components:
- Arduino Digispark
- Piezo disk
- 2 position swich or jumper
- Red and Green LED
- 9V Battery (or other)

