void setup() {
  Serial.begin(9600);  // Start the Serial Monitor and XBee communication
  pinMode(13,OUTPUT);
  delay(1000);         // Delay to stabilize connection
}

void loop() {
  if (Serial.available()) {
    char incomingData = Serial.read();
    //Serial.print("Received: ");
    Serial.println(incomingData);  // Display received data
    if(incomingData == '1')
    {
      digitalWrite(13,HIGH);
    }
    else if(incomingData == '0')
    {
      digitalWrite(13,LOW);
    }
  }
}
