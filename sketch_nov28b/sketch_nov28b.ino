#include<ADS1115_WE.h> 
#include<Wire.h>
#define I2C_ADDRESS 0x48

ADS1115_WE adc = ADS1115_WE(I2C_ADDRESS);

void setup() {
  Wire.begin();
  Serial.begin(9600);
  if(!adc.init()){
    Serial.println("ADS1115 not connected!");
  }

  adc.setVoltageRange_mV(ADS1115_RANGE_6144);
  Serial.println("ADS1115 Example Sketch - Single Shot Mode");
  Serial.println("Channel / Voltage [V]: ");
  Serial.println();
}

void loop() {
  float voltage = 0.0;
  Serial.print("0: ");
  adc.setCompareChannels(ADS1115_COMP_0_1); 
  
  // Read the voltage
  voltage = adc.getResult_V(); // Returns voltage in volts

  Serial.print("AIN0 Voltage: ");
  Serial.println(voltage);
  delay(10000);
}