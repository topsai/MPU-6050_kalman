#include "Wire.h"
#include "I2Cdev.h"
#include "MPU6050.h"
#include <Kalman.h>

#define AX_ZERO -630 //加速度计的0偏修正值  
#define GX_ZERO 290 //陀螺仪的0偏修正  


//  x = atan2(ax, az) * 180 / PI; // x角度
//  y = atan2(ay, az) * 180 / PI; // y角度
//  mgx = gx/130; // 角速度


Kalman kalman;
MPU6050 accelgyro;

int16_t ax, ay, az,gx, gy, gz; // 陀螺仪6个参数
double ax_angle = 0.0; //加速度计算得的角度
float gyro = 0.0, dt = 0.01; // dt采样时间间隔（秒）
float Angle = 0.0; //卡尔曼融合最终角度

void setup() {
  Wire.begin();
  Serial.begin(38400);
  Serial.println("Initializing I2C devices...");
  accelgyro.initialize();
  Serial.println("Testing device connections...");
  Serial.println(accelgyro.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");
}
void loop()
{

  accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  ax += AX_ZERO;
  ax_angle = atan2(ax, az) * 180 / PI; // x角度
  gy +=  GX_ZERO;
  gyro = gy / 131.0;
  Angle = kalman.getAngle(ax_angle, gyro, dt);
  delay(10); // 采样时间
  Serial.print(ax_angle); Serial.print(", ");
  Serial.println(Angle);
}
