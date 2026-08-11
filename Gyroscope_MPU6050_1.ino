#include <Wire.h>
#include <MPU6050_tockn.h>

MPU6050 mpu(Wire); // starting point , using I2C


long timer = 0; // time controll

void setup() {
  Serial.begin(9600);
  Wire.begin();

  mpu.begin();
  
  Serial.println("Calibrating MPU6050... Do not move the sensor!");
  delay(1000);
  mpu.calcGyroOffsets(true); //  calculating starting offsets 
  Serial.println("Calibration complete! Ready for operation.");
}

void loop() {
  mpu.update();

  if(millis() - timer > 250) {
    // Readings
    Serial.print("angle X (Pitch): "); Serial.print(mpu.getAngleX());
    Serial.print("\angle Y (Roll): ");  Serial.print(mpu.getAngleY());
    Serial.print("\angle Z (Yaw): ");   Serial.println(mpu.getAngleZ());
    
    timer = millis();
  }
}