void setup() {
  // setting motor pins to output
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);

}

void loop() {
  // anticlockwise
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);

  // wait for 1 second
  delay(1000);

  // clockwise
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);

  // wait for 1 second
  delay(1000);
}
