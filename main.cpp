#include <RGBLed.h>
#include <Arduino.h>

RGBLed led(2, 3, 4, RGBLed::COMMON_CATHODE);
char rawRead;

void setup() {
  Serial.begin(9600);
 }

void loop() {
while (Serial.available() == 0) {
  switch (rawRead) {
      case '1':
      // connecting
        led.fadeIn(RGBLed::GREEN, 10, 1000); // Fade out with 5 steps during 100ms
        led.fadeOut(RGBLed::GREEN, 10, 1000); // Fade out with 5 steps during 100ms
        break;
      case '2':
        // connected
        led.setColor(RGBLed::BLUE);
        break;    
      case '3':
        // triggering
        led.flash(RGBLed::YELLOW, 100); // Interval 100ms
        break;
      case '4':
        // triggered
        led.setColor(RGBLed::MAGENTA);
        break; 
      case '5':
        led.setColor(RGBLed::CYAN);
        break;
    }
  }

rawRead = Serial.read();
}
