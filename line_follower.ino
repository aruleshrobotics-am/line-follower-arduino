// IR sensor pins
int leftIR = 2;
int rightIR = 3;

// Motor driver pins
int ENA = 9;
int IN1 = 8;
int IN2 = 7;

int ENB = 10;
int IN3 = 6;
int IN4 = 5;

void setup() {
  pinMode(leftIR, INPUT);
  pinMode(rightIR, INPUT);

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int left = digitalRead(leftIR);
  int right = digitalRead(rightIR);

  if (left == 1 && right == 0) {
    // Turn right
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENA, 150);
    analogWrite(ENB, 255);
  }

  else if (left == 0 && right == 1) {
    // Turn left
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(ENA, 255);
    analogWrite(ENB, 150);
  }

  else {
    // Move straight
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENA, 255);
    analogWrite(ENB, 255);
  }

  Serial.print("Left IR: ");
  Serial.print(left);
  Serial.print(" | Right IR: ");
  Serial.println(right);

  delay(100);
}
