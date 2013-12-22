/* Huseyin KELES
 * http://whosayin.com
 * 22.12.2013
 */

int motor2Pin1 = 8;    // pin 2 on L293D
int motor2Pin2 = 9;    // pin 7 on L293D
int enablePin2 = 5;    // pin 1 on L293D

int motor1Pin1 = 10;    // pin 2 on L293D
int motor1Pin2 = 11;    // pin 7 on L293D
int enablePin1 = 3;    // pin 1 on L293D

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
      case 49:
          solIleri(200);
        break;
      case 50:
          sagIleri(200);
        break;
      case 51:
          solGeri(200);
        break;
      case 52:
          sagGeri(200);
        break;
      case 53:
          solDur();
        break;
      case 54:
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
