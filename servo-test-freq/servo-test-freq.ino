#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
#define SERVOMIN  80 // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  505 // This is the 'maximum' pulse length count (out of 4096)
#define USMIN  600 // This is the rounded 'minimum' microsecond length based on the minimum pulse of 150
#define USMAX  2400 // This is the rounded 'maximum' microsecond length based on the maximum pulse of 600
#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates
uint8_t servonum = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("8 channel Servo test!");
  pwm.begin();
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates
  delay(10);
}

void loop() {
  for (uint16_t pulselen = 0; pulselen < 360; pulselen++) {
    int pulso = map(pulselen, 0 , 360 , 80, 300) ;
    Serial.println(pulso);
    pwm.setPWM(0, 0, pulso);
  }
  delay(1000);
  for (uint16_t pulselen = 360; pulselen > 0; pulselen--) {
    int pulso = map(pulselen, 0 , 360 , 300, 500) ;
    Serial.println(pulso);
    pwm.setPWM(0, 0, pulso);
  }
  delay(1000);
}
