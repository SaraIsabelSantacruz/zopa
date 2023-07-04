#define STEP 3
#define DIR 2

void setup() {
  Serial.begin (9600);
  pinMode (STEP, OUTPUT);
  pinMode (DIR, OUTPUT);
}

void loop() {
  int maped = map(ADC0_promedio(20), 160, 600, 0, 80);
  digitalWrite (DIR, LOW);
  Serial.println(maped);
  if (maped <= 3) {
    digitalWrite (STEP, LOW);
    digitalWrite (STEP, LOW);
  }

  else if (maped > 3 && maped <= 20) {
    digitalWrite (STEP, LOW);
    delay (8);
    digitalWrite (STEP, HIGH);
    delay (8);
  }

  else if (maped > 20 && maped <= 80) {
    int delayValue = 8;
    digitalWrite (DIR, HIGH);
    if(maped > 40) {
      delayValue = 15;
    } else {
      delayValue = 8;
    }
    digitalWrite (STEP, HIGH);
    delay (delayValue);
    digitalWrite (STEP, LOW);
    delay (delayValue);
  }
}

int ADC0_promedio(int n) {
  long suma=0;
  for(int i=0;i<n;i++) {
    suma=suma+analogRead(A0);
  }  
  return(suma/n);
}
