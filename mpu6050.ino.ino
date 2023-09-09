#include <Wire.h>
#define GYRO_XOUT_H 0x43
#define ACCEL_XOUT_H 0x3B
#define IMU_sensor 0x68
#define PWR_MGMT_1 0x6B
#define GYRO_CONFIG 0x1B
#define ACCEL_CONFIG 0x1C

int yaw_angle = 0;
int No_of_tests =3000;

int16_t gyro_x, gyro_y,gyro_z,accel_x,accel_y,accel_z;

int16_t gyro_offset_x = 0,gyro_offset_y = 0,gyro_offset_z = 0,accel_offset_x = 0,accel_offset_y = 0,accel_offset_z = 0;

 int current_time = 0 ,old_time ;

void MPU_init(void)
{
  Wire.beginTransmission(IMU_sensor);
  Wire.write(PWR_MGMT_1);
  Wire.write(0x00);
  Wire.endTransmission();
}
void AccelConfiguration(void)
{
  Wire.beginTransmission(IMU_sensor);
  Wire.write(ACCEL_CONFIG);
  Wire.write(0x08);
  Wire.endTransmission();
}
void GyroConfiguration(void)
{
  Wire.beginTransmission(IMU_sensor);
  Wire.write(GYRO_CONFIG);
  Wire.write(0x18);
  Wire.endTransmission();
}
void MPU_readGyro_XYZ()
 { 
   
  Wire.beginTransmission(IMU_sensor);
  Wire.write(GYRO_XOUT_H);
  Wire.endTransmission();

  Wire.requestFrom(IMU_sensor,6);
   while(Wire.available()<6);

  gyro_x = Wire.read() << 8 | Wire.read() - gyro_offset_x;
  gyro_y = Wire.read() << 8 | Wire.read() - gyro_offset_y;
  gyro_z = Wire.read() << 8 | Wire.read() - gyro_offset_z;

   
 }


 void MPU_readAccel_XYZ()
 { 
   
  Wire.beginTransmission(IMU_sensor);
  Wire.write(ACCEL_XOUT_H);
  Wire.endTransmission();

  Wire.requestFrom(IMU_sensor,6);
   while(Wire.available()<6);

  accel_x = Wire.read() << 8 | Wire.read() - accel_offset_x;
  accel_y = Wire.read() << 8 | Wire.read() - accel_offset_x;
  accel_z = Wire.read() << 8 | Wire.read() - accel_offset_x;

   
 }
 void MPU_readAllData()
 {
   Wire.beginTransmission(IMU_sensor);
  Wire.write(ACCEL_XOUT_H);
  Wire.endTransmission();

  Wire.requestFrom(IMU_sensor,14);
   while(Wire.available()<14);

  accel_x = Wire.read() << 8 | Wire.read() - accel_offset_x;
  accel_y = Wire.read() << 8 | Wire.read() - accel_offset_x;
  accel_z = Wire.read() << 8 | Wire.read() - accel_offset_x;
   
   Wire.read();
   Wire.read();

  gyro_x = Wire.read() << 8 | Wire.read() - gyro_offset_x;
  gyro_y = Wire.read() << 8 | Wire.read() - gyro_offset_y;
  gyro_z = Wire.read() << 8 | Wire.read() - gyro_offset_z;


 }
 void calibrate_IMU(void)
 {
  for(int i=0;i<No_of_tests;i++)
  {MPU_readAllData();
    gyro_offset_x+=gyro_x;
    gyro_offset_y+=gyro_y;
    gyro_offset_z+=gyro_z;
    accel_offset_x+=accel_x;
    accel_offset_y+=accel_y;
    accel_offset_z+=accel_z;
  }  
  gyro_offset_x/= No_of_tests;
  gyro_offset_y/= No_of_tests;
  gyro_offset_z/= No_of_tests;
  accel_offset_x/= No_of_tests;
  accel_offset_y/= No_of_tests;
  accel_offset_z/= No_of_tests;
 }


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Wire.begin();
  Wire.setClock(9600);
  MPU_init();
  AccelConfiguration();
  GyroConfiguration();
  calibrate_IMU();

}


void loop() {
  // put your main code here, to run repeatedly:
  
  old_time = current_time;
  
  MPU_readGyro_XYZ();
  MPU_readAccel_XYZ();
  
  
  //TrueValues
  accel_x =(accel_x)*(4*9.81/32786);
  accel_y =(accel_y)*(4*9.81/32786);
  accel_z =(accel_z)*(4*9.81/32786);
  gyro_x =(gyro_x)*(1.0 * 2000/32786);
  gyro_y =(gyro_y)*(1.0 * 2000/32786);  
  gyro_z =(gyro_z)*(1.0 * 2000/32786); 
current_time = millis();
   double Dtime = (current_time - old_time)/1000.0; 
  
  yaw_angle= gyro_z * Dtime ;
  Serial.print("Yaw Angle: ");
  Serial.println(yaw_angle); 
  // raw angle in degrees
delay(1000);
  
}
  


  
  
  
  



  
  
  
  
