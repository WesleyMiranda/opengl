const int PINO_IN1 = 5; 
const int PINO_IN2 = 6;
const int PINO_IN3 = 9;
const int PINO_IN4 = 10;

const int TEMPO_ESPERA = 5000;

void setup() {

  pinMode(PINO_IN1, OUTPUT);
  pinMode(PINO_IN2, OUTPUT);
  pinMode(PINO_IN3, OUTPUT);
  pinMode(PINO_IN4, OUTPUT);

  digitalWrite(PINO_IN1, LOW); 
  digitalWrite(PINO_IN2, LOW);
  digitalWrite(PINO_IN3, LOW);
  digitalWrite(PINO_IN4, LOW);
}

void loop() {

  digitalWrite(PINO_IN1, LOW); 
  digitalWrite(PINO_IN2, HIGH);
  digitalWrite(PINO_IN3, LOW);
  digitalWrite(PINO_IN4, HIGH);

  delay(TEMPO_ESPERA);

  digitalWrite(PINO_IN1, LOW); 
  digitalWrite(PINO_IN2, LOW);
  digitalWrite(PINO_IN3, LOW);
  digitalWrite(PINO_IN4, LOW);

  delay(TEMPO_ESPERA);
}
