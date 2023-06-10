/*
  Programa de prueba de un pulsador KY-004
*/
int pinBoton = 2; // Definir el pin del pulsador
int valor; // Definir una variable numerica

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(pinBoton, INPUT);
}

void loop() {
  // comprobar el estado de boton
  valor = digitalRead(pinBoton);
  // si el boton es presionado escribe botón prendido //enciende el LED
  if (valor == 1) {
    Serial.println("botón apagado");
    //digitalWrite(LED_BUILTIN,HIGH);
  }
  else {
    Serial.println("botòn prendido");
    //digitalWrite(LED_BUILTIN,LOW);
  }
}
