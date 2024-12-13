const int solarRef = A0;
const int solarActual = A1;

const int vibratorPin = 1;
unsigned long vibrationStartTime = 0; 
const unsigned long vibrationDuration = 1000;
bool isVibrating = false;

const float referenceVoltage = 3.3;
const int resolution = 1024; // 10-bit ADC (2^10 = 1024)
const float voltageThreshold = 0.5;
const unsigned long measurementDelay = 1000;

void setup() {
  pinMode(vibratorPin, OUTPUT);
  digitalWrite(vibratorPin, LOW);
  Serial.begin(9600);
}

void loop() {
  int analogValueRef = analogRead(solarRef); // Read raw ADC value
  float voltageRef = (analogValueRef / (float)resolution) * referenceVoltage;
  Serial.print("Reference Voltage: ");
  Serial.print(voltageRef);
  Serial.println(" V");

  int analogValueActual = analogRead(solarActual);
  float voltageActual = (analogValueActual / (float)resolution) * referenceVoltage;
  Serial.print("Actual Voltage: ");
  Serial.print(voltageActual);
  Serial.println(" V");

  float voltageDifference = voltageRef - voltageActual;
  Serial.print("Voltage Difference: ");
  Serial.print(voltageDifference);
  Serial.println(" V");

  // if (voltageDifference >= voltageThreshold && !isVibrating) {
    if(true){
    Serial.println("Should vibrate");
    isVibrating = true;
    vibrationStartTime = millis();
    digitalWrite(vibratorPin, HIGH);
  } 

  if (isVibrating && millis() - vibrationStartTime >= vibrationDuration) {
    isVibrating = false;
    digitalWrite(vibratorPin, LOW);
  }

  delay(measurementDelay);
}
