// Define pin numbers for sensors
const int REF_SENSOR_PIN = A0;
const int ARRAY_SENSOR_PIN = A1; 
const float THRESHOLD_RATIO = 0.7;  

void setup() {
  Serial.begin(9600);
  pinMode(REF_SENSOR_PIN, INPUT);
  pinMode(ARRAY_SENSOR_PIN, INPUT);
}

void loop() {
  float refVoltage = analogRead(REF_SENSOR_PIN);
  float arrayVoltage = analogRead(ARRAY_SENSOR_PIN);

    float ratio = arrayVoltage / refVoltage;

  if (ratio < THRESHOLD_RATIO) {
    Serial.println("Cleaning triggered! Array output below 90% of reference.");

  } else {
    Serial.println("Cleaning not needed.");
  }

  delay(5000);
}
