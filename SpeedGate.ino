
void setup() {
  
  Serial.begin(115200);
}

void loop() {

  bool bPinVal = true;

  unsigned long ulStartTime = 0;
  unsigned long ulStopTime = 0;

  bPinVal = digitalRead(2);

  if(!bPinVal)
  {
    ulStartTime = micros();
    ulStopTime = 0;

    while(!bPinVal)
    { 
      ulStopTime = micros();
      bPinVal = digitalRead(2);
    }

    if(ulStopTime > ulStartTime)
    {
      Serial.print(ulStopTime - ulStartTime);
      Serial.println(" us");
    }
  }
}
