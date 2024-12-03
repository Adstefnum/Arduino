#include <Adafruit_ADS1X15.h>
#include<Wire.h>

Adafruit_ADS1115 ads; // Create an instance of the ADS1115

void setup() {
  Wire.begin();
  Serial.begin(9600);
  if (!ads.begin()) {
    Serial.println("Failed to initialize ADS1115!");
    while (1);
  }
  
  ads.setGain(GAIN_SIXTEEN); // Set gain to +/- 4.096V (1 bit = 0.125 mV)
  Serial.println("ADS1115 Differential Mode Example");
}

void loop() {
  int16_t rawValue = ads.readADC_Differential_0_1(); // Read A0 - A1
  Serial.print(rawValue);
  float voltage = rawValue * 0.125 / 1000.0; // Convert to voltage (in volts)

  Serial.print("Voltage (A0 - A1): ");
  Serial.print(voltage, 4); // Print with 4 decimal places
  Serial.println(" V");
  
  delay(10000); // Delay 1 second
}
