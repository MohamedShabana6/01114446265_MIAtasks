#include <stdio.h>
#include <stdlib.h>
/**
*@brief Function used to calculate the weighted accuracy using Kalman filter
*@param mpuValue copied data from array mpu6050
*@param bnoValue copied data from array bno55
*@return a simplified equation instead of (1-KalmanGainConstant)* bnoValue + KalmanGainConstant * mpuValue resulting in weighted value
**/
float KalmanFilter(float mpuValue, float bnoValue, float mpuAccuracy, float bnoAccuracy )
{
    float KalmanGainConstant=(mpuAccuracy)/(mpuAccuracy+bnoAccuracy);
    return bnoValue + KalmanGainConstant *(mpuValue-bnoValue);
}
int main()
{
    float mpu6050[10]= {0.0,11.68,18.95,23.56,25.72,25.38,22.65,18.01,10.14,-0.26};
    float bno55[10]= {0.0,9.49,16.36,21.2,23.16,22.8,19.5,14.85,6.79,-2.69};
    float averageMeasurment[10];
    int i ;
    int size = sizeof(mpu6050)/sizeof(mpu6050[0]);//if size is not known
    printf("Average Measurments: ");
    for(i=0; i<size; i++)
    {
        averageMeasurment[i]=KalmanFilter(mpu6050[i],bno55[i],78,92);

    }
    for(i=0; i<size; i++)
    {
        printf("%.2f ",averageMeasurment[i]);
    }


    return 0;
}
