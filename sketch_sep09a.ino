#define le 13

#define ld 10

#define pinMotD1 2
#define pinMotD2 3
#define pinMotE1 4
#define pinMotE2 5

#define velocMax 255
#define velocMin 128

int e = A8;
int d = A14;

void setup() {
  Serial.begin(9600);
  pinMode(e,INPUT);
  pinMode(d,INPUT);
  // put your setup code here, to run once:
  for (int i = 10; i <= 13; i++) {
    pinMode(i, INPUT);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  int distanciaSensor = 13;//Pegar o valor do ultrasonco
  if (distanciaSensor < 7) {

  } else {
    int vLe = analogRead(le);
    int vE = analogRead(e);
    int vD = analogRead(d), vLd = analogRead(ld);
        Serial.print(vE);
        Serial.print(" - ");
    Serial.print(vD);
    Serial.print(" - ");
    
    double m = (-vE + vD);
    Serial.print(m);
    Serial.print(" - ");
    controlaMotor(pinMotE1, pinMotE2, -m); // move pra esquerda
    Serial.print(" - ");
    controlaMotor(pinMotD1, pinMotD2, m); // move pra direita
    Serial.println(".");
    }}  
void controlaMotor(int pin1, int pin2, double valor) {
  valor = map(valor, -1024, 1024, -512, 512);
  double velocFinal = velocMax + valor;

  velocFinal = abs(velocFinal) > velocMax ? velocFinal>0?velocMax:-velocMax : velocFinal;
  analogWrite(pin1, velocFinal);
  Serial.print(velocFinal);
  if (velocFinal >= 0) {
    digitalWrite(pin2, HIGH);
  } else {
    digitalWrite(pin2, LOW);
  }

}
