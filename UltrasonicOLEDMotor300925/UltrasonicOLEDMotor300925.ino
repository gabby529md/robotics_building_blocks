#include <Adafruit_SSD1306.h>
#include <Servo.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

const int trigPin = 10;
const int echoPin = 8;
const int ledPin = 7;

const int leftPinA = 5;
const int leftPinB = 7;

const int servoPin = 11;
Servo myServo;


void setup(){
  pinMode(trigPin, OUTPUT);   // trigger
  pinMode(echoPin, INPUT);    // echo
  pinMode(ledPin, OUTPUT);   // led
  pinMode(leftPinA, OUTPUT);
  pinMode(leftPinB, OUTPUT);

  myServo.attach(servoPin);
  myServo.write(0);

  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
}

void loop(){
  float distance = getDistance();

  if(distance <= 5) {
    myServo.write(0);
    digitalWrite(leftPinA, HIGH);
    digitalWrite(leftPinB, LOW);
  }
  else {
    myServo.write(90);
    digitalWrite(leftPinA, LOW);
    digitalWrite(leftPinB, HIGH);
  }

  Serial.println(distance);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,25);
  display.println(distance);
  display.display();
}
float getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  int echotime = pulseIn(echoPin, HIGH);
  float distance = (echotime/2) * 0.034;
  return distance;
}