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
const int led1 = 9;    // PWM
const int led2 = 10;   // PWM
const int led3 = 5;    // PWM fade LED

// Piezo Pin
const int speakerPin = 8;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(speakerPin, OUTPUT);
}

void loop() {

  // -------- FAST WAIL UP --------
  for (float i = 0; i < 3.14; i += 0.04) {

    // Higher and sharper sweep (800–2200 Hz)
    float baseFreq = 800 + (sin(i) * 1400);

    // Stronger vibrato for urgency
    float vibrato = sin(millis() * 0.05) * 60;

    int finalFreq = baseFreq + vibrato;

    // FULL BRIGHT emergency LEDs
    analogWrite(led1, 255);
    analogWrite(led2, 0);

    tone(speakerPin, finalFreq);

    updateFade();
    delay(5);   // Faster sweep = more urgent
  }

  // -------- FAST WAIL DOWN --------
  for (float i = 3.14; i > 0; i -= 0.04) {

    float baseFreq = 800 + (sin(i) * 1400);
    float vibrato = sin(millis() * 0.05) * 60;
    int finalFreq = baseFreq + vibrato;

    analogWrite(led1, 0);
    analogWrite(led2, 255);

    tone(speakerPin, finalFreq);

    updateFade();
    delay(5);
  }
}


// -------- Bright Peaceful Fade (Never Fully Dim) --------
void updateFade() {

  // Fade between 120 and 255 (always bright)
  float brightness = (sin(millis() * 0.003) + 1) * 67.5 + 120;

  analogWrite(led3, brightness);
}






