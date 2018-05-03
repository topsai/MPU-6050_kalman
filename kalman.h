 /*
 卡尔曼滤波
 */
#ifndef _Kalman_h_
#define _Kalman_h_  
  
  
class Kalman {  
public:  
    Kalman();  
  
  
    float getAngle(float newAngle, float newRate, float dt);  
  
  
    void setAngle(float angle);  
    float getRate();  
  
  
    void setQangle(float Q_angle);  
    void setQbias(float Q_bias);  
    void setRmeasure(float R_measure);  
  
  
    float getQangle();  
    float getQbias();  
    float getRmeasure();  
  
  
private:  
    float Q_angle;  
    float Q_bias;  
    float R_measure;  
  
  
    float angle;  
    float bias;  
    float rate;  
  
  
    float P[2][2];  
};  
  
#endif  
