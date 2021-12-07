#define joyX 34
#define joyY 35
#define PushButton 2
 
void setup() {
  Serial.begin(9600);
}
 
void loop() {
  // put your main code here, to run repeatedly:
 
  //print the values with to plot or view
  Serial.println(analogRead(joyX));
  //Serial.print("\t");
  //Serial.println(analogRead(joyY));
  delay(500);
}
