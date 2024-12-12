const int solarRef = A0; // Pin where the solar panel is connected
const int solarActual = A1;
const int vibratorPin = 1; // Pin to control the vibrator
const float referenceVoltage = 3.3; // ADC reference voltage (3.3V for many boards)
const int resolution = 1024; // 10-bit ADC (2^10 = 1024)
const float voltageThreshold = 0.7;

void setup() {
  pinMode(vibratorPin, OUTPUT); // Set vibrator control pin as OUTPUT
  digitalWrite(vibratorPin, LOW); // Turn vibrator off initially
  Serial.begin(9600);
}

void loop() {
  int analogValueRef = analogRead(solarRef); // Read raw ADC value
  float voltageRef = (analogValueRef / (float)resolution) * referenceVoltage; // Convert to voltage
  Serial.print("Reference Voltage: ");
  Serial.print(voltageRef);
  Serial.println(" V");

  int analogValueActual = analogRead(solarActual); // Read raw ADC value
  float voltageActual = (analogValueActual / (float)resolution) * referenceVoltage; // Convert to voltage
  Serial.print("Actual Voltage: ");
  Serial.print(voltageActual);
  Serial.println(" V");

  float voltageRatio = voltageActual / voltageRef;
  if (voltageRatio < voltageThreshold) {
    Serial.println("Should vibrate");
    digitalWrite(vibratorPin, HIGH); // Turn vibrator ON
  } else {
    digitalWrite(vibratorPin, LOW); // Turn vibrator OFF
  }
  delay(1000); // Read every second
}
