#define LED1 LED_BUILTIN
#define LED2 4

void setup() {
  Serial.begin(9600);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
}

void on() {
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
}

void off() {
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
}

void loop() {
  Serial.print(".");
  on();
  delay(240);
  off();
  delay(720);
  Serial.print(".");
  on();
  delay(240);
  off();
  delay(720);
  Serial.print(".");
  on();
  delay(240);
  off();
  delay(720);
  Serial.print("-");
  on();
  delay(720);
  off();
  delay(720);
  Serial.print(" ");
  off();
  delay(1440);
  Serial.print(".");
  on();
  delay(240);
  off();
  delay(720);
  Serial.print(" ");
  off();
  delay(1440);
  Serial.print("-");
  on();
  delay(720);
  off();
  delay(720);
  Serial.print(".");
  on();
  delay(240);
  off();
  delay(720);
  Serial.print("-");
  on();
  delay(720);
  off();
  delay(720);
  Serial.print(".");
  on();
  delay(240);
  off();
  delay(720);
  Serial.print(" ");
  off();
  delay(1440);
  Serial.print("-");
  on();
  delay(720);
  off();
  delay(720);
  Serial.print(".");
  on();
  delay(240);
  off();
  delay(720);
  Serial.print("-");
  on();
  delay(720);
  off();
  delay(720);
  Serial.print(".");
  on();
  delay(240);
  off();
  delay(720);
  Serial.print(" ");
  off();
  delay(1440);
  Serial.print(".");
  on();
  delay(240);
  off();
  delay(720);
  Serial.print(".");
  on();
  delay(240);
  off();
  delay(720);
  Serial.print(".");
  on();
  delay(240);
  off();
  delay(720);
  Serial.print(".");
  on();
  delay(240);
  off();
  delay(720);
  Serial.print(" ");
  off();
  delay(1440);
  Serial.print(".");
  on();
  delay(240);
  off();
  delay(720);
  Serial.print(".");
  on();
  delay(240);
  off();
  delay(720);
  Serial.print(" ");
  off();
  delay(1440);
  Serial.print(".");
  on();
  delay(240);
  off();
  delay(720);
  Serial.print("-");
  on();
  delay(720);
  off();
  delay(720);
  Serial.print(" ");
  off();
  delay(1440);
  Serial.print(".");
  on();
  delay(240);
  off();
  delay(720);
  Serial.print(".");
  on();
  delay(240);
  off();
  delay(720);
  Serial.print("-");
  on();
  delay(720);
  off();
  delay(720);
  Serial.print(".");
  on();
  delay(240);
  off();
  delay(720);
  Serial.print(" ");
  off();
  delay(1440);
  Serial.print(".");
  on();
  delay(240);
  off();
  delay(720);
  Serial.print("-");
  on();
  delay(720);
  off();
  delay(720);
  Serial.print(" ");
  off();
  delay(1440);
  Serial.print("-");
  on();
  delay(720);
  off();
  delay(720);
  Serial.print("-");
  on();
  delay(720);
  off();
  delay(720);
  Serial.print(" ");
  off();
  delay(1440);
  Serial.print(".");
  on();
  delay(240);
  off();
  delay(720);
  Serial.print("-");
  on();
  delay(720);
  off();
  Serial.println();

  delay(6000);
}
