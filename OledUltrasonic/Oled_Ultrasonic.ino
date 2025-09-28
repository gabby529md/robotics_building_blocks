#include <Adafruit_SSD1306.h>
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

const int trigger = 10;
const int echo = 8;
const int greenLED = 3;
const int redLED = 2;

void setup(){
  // setting pins to input or output
  pinMode(trigger, OUTPUT);  
  pinMode(echo, INPUT);    
  pinMode(greenLED, OUTPUT);  
  pinMode(redLED, OUTPUT); 

  // setting up serial monitor
  Serial.begin(9600);

  // setting up OLED display
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
}
void loop(){
  // pulsing trigger
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(trigger);
  digitalWrite(trigger, LOW);
  
  // calculating distance
  int echotime = pulseIn(echo, HIGH);
  float distance = (0.034) * (echotime / 2);

  //leds
  if(distance <= 5) {
    // turning on red led
    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, LOW);
  }
  if(distance > 5) {
    // turning on green led
    digitalWrite(greenLED, HIGH);
    digitalWrite(redLED, LOW);   
  }
  
  // displaying distance
  Serial.println(distance);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.println(distance);
  display.display();
}