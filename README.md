# Rain Sensor
# Description:
  It's a rain sensor made using mainly a IR photodiode and a phototransistor. For the control module, I used an ESP32-C3 Super Nano useful for the small form-factor of the PCB. It is powered at 10-30 VDC. For the detection of water the photodiode and the phototransistor should be placed at 45° facing eachother, as visual alarm it is used an led and a WEB interface running on the esp32.
# Hardware used:
* ESP32-C3 Super Nano
* SFH 4555-CWDW IR Photodiode
* BPW77NB Phototransistor
* 1xLED
* 2N2222A Transistor
* Capacitors: 2x100uF, 2x100nF
* Resistors: 1x220, 1x330, 1x1K, 1x10K 
* 1xLM7805T Voltage Regulator
# Schematic:
  It's the final one.
  The only problem I found is that you need to connect the ESP32 to 5V only to the 5V line of the USB-C. I removed the switch near the port and used a 28awg wire to connect it. I added a pad to be easier to connect the wire to the PCB.
# PCB:
  I tried doing it as small as possible still using the capacitor filtering. Added a pad for connecting the ESP32 to 5V.
# STLs:
  Still working on them, initially the PCB was made on a prototyping board so the case and the PCB were larger.
