/* Huseyin KELES
 * http://whosayin.com
 * 22.12.2013
 */

int motor1Pin1 = 8;
int motor1Pin2 = 9;
int enablePin1 = 5;

int motor2Pin1 = 10;
int motor2Pin2 = 11;
int enablePin2 = 3;

int received = 0;

void setup() {
  Serial.begin(9600);
  
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(enablePin1, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  pinMode(enablePin2, OUTPUT);
}

void solGeri(int hiz) {
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, HIGH);
    analogWrite(enablePin1, hiz);
}

void solIleri(int hiz) {
    digitalWrite(motor1Pin1, HIGH);
    digitalWrite(motor1Pin2, LOW);
    analogWrite(enablePin1, hiz);
}

void sagIleri(int hiz) {
    digitalWrite(motor2Pin1, HIGH);
    digitalWrite(motor2Pin2, LOW);
    analogWrite(enablePin2, hiz);
}

void sagGeri(int hiz) {
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, HIGH);
    analogWrite(enablePin2, hiz);
}

void solDur() {
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, LOW);
}

void sagDur() {
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, LOW);
}

void loop()
{
  if (Serial.available()) {
    received = Serial.read();
    Serial.println(received);
    
    switch (received) {
      case '1':
          solIleri(200);
        break;
      case '2':
          sagIleri(200);
        break;
      case '3':
          solGeri(200);
        break;
      case '4':
          sagGeri(200);
        break;
      case '5':
          solDur();
        break;
      case '6':
          sagDur();
        break;
      default:
          solDur();
          sagDur();
        break;
    }
    
    Serial.flush();
  }
}
