/*
  Blink

Developer: Kiera McKimmy

Date: 17 February 2026

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://docs.arduino.cc/hardware/

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://docs.arduino.cc/built-in-examples/basics/Blink/
*/

// LED Pins
const int led1 = 9;
const int led2 = 10;

// Piezo Pin
const int speakerPin = 8;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(speakerPin, OUTPUT);
}

void loop() {

  // Wail UP
  for (int freq = 400; freq <= 2000; freq += 10) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    tone(speakerPin, freq);
    delay(5);
  }

  // Wail DOWN
  for (int freq = 2000; freq >= 400; freq -= 10) {
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    tone(speakerPin, freq);
    delay(5);
  }
}





