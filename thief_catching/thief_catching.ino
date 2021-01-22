int LEDPin = 8;             
int lightSensorPin = A0; 
int lightIntensity;
int buzzer = 12;
void setup(){
  Serial.begin(9600);
  pinMode(LEDPin,OUTPUT);
  pinMode(buzzer,OUTPUT);
}
void loop(){
  lightIntensity = analogRead(lightSensorPin);
  Serial.println(lightIntensity);
  if(lightIntensity > 30){ 
     Serial.println("umujura araje");
     digitalWrite(buzzer,HIGH);
  }else{
    digitalWrite(buzzer,LOW);
  }
}
