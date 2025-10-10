#include <Stepper.h>
#include <Wire.h>
#include <MPU6050.h>
MPU6050 mpu;
// Number of steps per revolution (for 28BYJ-48)
const int stepsPerRevolution = 2048;
// Create Stepper object with pin sequence IN1-IN3-IN2-IN4
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 2);
void setup() {
  myStepper.setSpeed(10); // Set speed in RPM
  Serial.begin(9600);
  Serial.println("Stepper Motor Test Start");
  Wire.begin();
  mpu.initialize();
}
void loop() {
  int16_t ax, ay, az;
  mpu.getAcceleration(&ax, &ay, &az);
  Serial.print("X: ");
  Serial.print(ax);
  Serial.print(" | Y: ");
  Serial.print(ay);
  Serial.print(" | Z: ");
  Serial.println(az);
  if(ay > 500){
  Serial.println("Clockwise rotation");
  myStepper.step(stepsPerRevolution);  // 1 full rotation clockwise
  }
  else{
  Serial.println("Counterclockwise rotation");
  myStepper.step(-stepsPerRevolution); // 1 full rotation counterclockwise
  }
}