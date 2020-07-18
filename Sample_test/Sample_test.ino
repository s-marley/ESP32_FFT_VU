#define AUDIO_IN_PIN 35

int analogValue;
unsigned long newTime;

void setup() {
  Serial.begin(115200);
}

void loop() {
  newTime = micros();
  
  // Do 1 million reads and record time taken
  for (int i = 0; i < 1000000; i++) {
    analogValue = analogRead(AUDIO_IN_PIN);
  }

  float conversionTime = (micros() - newTime) / 1000000.0;

  Serial.print("Conversion time: ");
  Serial.print(conversionTime);
  Serial.println(" uS");

  Serial.print("Max sampling frequency: ");
  Serial.print((1.0 / conversionTime) * 1000000);
  Serial.println(" Hz");
}
