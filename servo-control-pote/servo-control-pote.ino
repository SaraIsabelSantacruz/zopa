#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver servos = Adafruit_PWMServoDriver();

unsigned int pos0=172; // ancho de pulso en cuentas para pocicion 0°
unsigned int pos180=565; // ancho de pulso en cuentas para la pocicion 180°
int posPote1, mapPosPote1, posPote2, mapPosPote2, posPote3, mapPosPote3, posPote4, mapPosPote4;

void setup() {
  Serial.begin(9600);
  servos.begin();  
  servos.setPWMFreq(60); //Frecuecia PWM de 60Hz o T=16,66ms
  (0, 0, 0);
  (3, 0, 0);
  (4, 0, 0);
  (15, 0, 0);
}


void loop() {
  posPote1 = analogRead(0);
  mapPosPote1 = map(posPote1, 0, 1000, 172, 565);
  servos.setPWM(0, 0, mapPosPote1);

  posPote2 = analogRead(1);
  mapPosPote2 = map(posPote2, 0, 1000, 172, 565);
  servos.setPWM(3, 0, mapPosPote2);

  posPote3 = analogRead(3);
  mapPosPote3 = map(posPote3, 0, 1000, 172, 565);
  servos.setPWM(4, 0, mapPosPote3);

  posPote4 = analogRead(2);
  Serial.println(posPote4);
  mapPosPote4 = map(posPote4, 0, 1000, 172, 565);
  servos.setPWM(15, 0, mapPosPote4);
}
