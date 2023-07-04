#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
#define SERVOMIN  80 // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  505 // This is the 'maximum' pulse length count (out of 4096)
#define USMIN  600 // This is the rounded 'minimum' microsecond length based on the minimum pulse of 150
#define USMAX  2400 // This is the rounded 'maximum' microsecond length based on the maximum pulse of 600
#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates
uint8_t servonum = 0;

int pinBotonServo8 = 2;
int buttonPushCounter8 = 0;
int buttonState8 = 0;
int lastButtonState8 = 1;

int pinBotonServo11 = 4;
int buttonPushCounter11 = 0;
int buttonState11 = 0;
int lastButtonState11 = 1;

int pinBotonServo13 = 7;
int buttonPushCounter13 = 0;
int buttonState13 = 0;
int lastButtonState13 = 1;

int pinBotonServo15 = 8;
int buttonPushCounter15 = 0;
int buttonState15 = 0;
int lastButtonState15 = 1;

void setup() {
  Serial.begin(9600);
  pinMode(pinBotonServo8, INPUT_PULLUP);
  pinMode(pinBotonServo11, INPUT_PULLUP);
  pinMode(pinBotonServo13, INPUT_PULLUP);
  pinMode(pinBotonServo15, INPUT_PULLUP);
  pwm.begin();
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(SERVO_FREQ);
  pwm.setPWM(15, 0, 0);
  pwm.setPWM(13, 0, 0);
  pwm.setPWM(11, 0, 0);
  pwm.setPWM(8, 0, 0);
}

void loop() {
  Button8();
  Button11();
  Button13();
  Button15();
}

void Button8() {
  buttonState8 = digitalRead(pinBotonServo8);
  if (buttonState8 != lastButtonState8) {
    if (buttonState8 == 0) {
      buttonPushCounter8 = buttonPushCounter8 + 1;
      if(buttonPushCounter8 == 1) {
        pwm.setPWM(8, 0, 250);
      }
      else if (buttonPushCounter8 == 2) {
        pwm.setPWM(8, 0, 350);
      }
      else if (buttonPushCounter8 == 3) {
        pwm.setPWM(8, 0, 0);
        buttonPushCounter8 = 0;
      }
      delay(500);
    }
  }
}

void Button11() {
  buttonState11 = digitalRead(pinBotonServo11);
  if (buttonState11 != lastButtonState11) {
    if (buttonState11 == 0) {
      buttonPushCounter11 = buttonPushCounter11 + 1;
      if(buttonPushCounter11 == 1) {
        pwm.setPWM(11, 0, 250);
      }
      else if (buttonPushCounter11 == 2) {
        pwm.setPWM(11, 0, 350);
      }
      else if (buttonPushCounter11 == 3) {
        pwm.setPWM(11, 0, 0);
        buttonPushCounter11 = 0;
      }
      delay(500);
    }
  }
}

void Button13() {
  buttonState13 = digitalRead(pinBotonServo13);
  if (buttonState13 != lastButtonState13) {
    if (buttonState13 == 0) {
      buttonPushCounter13 = buttonPushCounter13 + 1;
      if(buttonPushCounter13 == 1) {
        pwm.setPWM(13, 0, 250);
      }
      else if (buttonPushCounter13 == 2) {
        pwm.setPWM(13, 0, 350);
      }
      else if (buttonPushCounter13 == 3) {
        pwm.setPWM(13, 0, 0);
        buttonPushCounter13 = 0;
      }
      delay(500);
    }
  }
}

void Button15() {
  buttonState15 = digitalRead(pinBotonServo15);
  if (buttonState15 != lastButtonState15) {
    if (buttonState15 == 0) {
      buttonPushCounter15 = buttonPushCounter15 + 1;
      if(buttonPushCounter15 == 1) {
        pwm.setPWM(15, 0, 250);
      }
      else if (buttonPushCounter15 == 2) {
        pwm.setPWM(15, 0, 350);
      }
      else if (buttonPushCounter15 == 3) {
        pwm.setPWM(15, 0, 0);
        buttonPushCounter15 = 0;
      }
      delay(500);
    }
  }
}
