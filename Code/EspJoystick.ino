#define joyX 34
#define joyY 35
#define PushButton 2
 
void setup() {
  Serial.begin(9600);
}
 
void loop() {
  Serial.println(analogRead(joyX));
  //Serial.print("\t");
  //Serial.println(analogRead(joyY));
  delay(500);
}
