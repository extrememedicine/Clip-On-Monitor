## Extreme Medicine Hackathon
# Clip-On-Monitor
 
---
 
### Contributors
 
* Matthew Wellings
 
---
 
Clip on respiration &amp; heart rate monitor. Clips on to the nose and sounds alarm when resperation or heart rate goes outside preset parameters (set by connecting to a pc or phone).
Costs ~ £5-£10
Possible 3D printable mounting clip.
Very Small (Main board less than 20mmx10mm)
Currently able to plot pulse and respiration on connected pc and display BPM demonstrating .
 
---
 
### How to run
Currently uses Arduino, connect an SE95 to the Arduino I2C pins and ground the SE95's address pins.
Connect an analogue pulse sensor to pin 14 of the Arduino.
Connect a piezo buzzer to pin 2.
Load firmware using Arduino software.
Compile pc app using qmake then make.

---
 
### Improvements
* Rewrite firmware for reliability.
* Use an 8 lead DFN PIC micro-controller e.g. PIC12F1840 (3mm x 3mm x 0.9 mm)
* Use 4 SE95s (two under nose and two over or in mouth.)
* Design printable clip.
* Make a wireless version that transmits data to pc and a native pc/tablet app that shows results on many patients at once (No internet connection required).
* Design circuit board (two versions - one for pick and place auto assembly and another for hand soldering (slightly larger))
* Add battery alarm code.
