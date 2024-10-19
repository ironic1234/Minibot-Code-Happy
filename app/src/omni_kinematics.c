#include <math.h>
#include "robot.h"

#define THETA M_PI
#define RAD 0
#define DIST 0
#define MAX_SPEED 0

typedef struct motorSpeeds{
    double vel1, vel2, vel3, vel4;
} motorSpeeds_t;

void mapping(Chassis_State_t speeds, motorSpeeds_t* mSpeeds){
    (*mSpeeds).vel1 = -1*sin(THETA)*speeds.x_speed + cos(THETA)*speeds.y_speed + DIST*speeds.omega;
    (*mSpeeds).vel2 = -1*cos(THETA)*speeds.x_speed - sin(THETA)*speeds.y_speed + DIST*speeds.omega;
    (*mSpeeds).vel3 = sin(THETA)*speeds.x_speed - cos(THETA)*speeds.y_speed + DIST*speeds.omega;
    (*mSpeeds).vel4 = cos(THETA)*speeds.x_speed + sin(THETA)*speeds.y_speed + DIST*speeds.omega;
}

void desaturation(motorSpeeds_t* mSpeeds){
    float bigSpeed = max((*mSpeeds).vel1, (*mSpeeds).vel2, (*mSpeeds).vel3, (*mSpeeds).vel4);

    if (bigSpeed > MAX_SPEED){
        float ratio = MAX_SPEED/bigSpeed;

        (*mSpeeds).vel1 *= ratio;
        (*mSpeeds).vel2 *= ratio;
        (*mSpeeds).vel3 *= ratio;
        (*mSpeeds).vel4 *= ratio;
    }
}

float max(float a, float b, float c, float d){
    float m = max2(a, b);
    m = max2(m, c);
    m = max2(m, d);

    return m;
}

float max2(float a, float b){
    if (a > b) return a;
    return b;
}