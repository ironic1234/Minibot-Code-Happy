#include "chassis_task.h"
#include "omni_kinematics.h"
#include "robot.h"

float max(float x, float y)
{
    return x >= y ? x : y;
}

void mapping(Chassis_State_t speeds, motorSpeeds_t *mSpeeds)
{
    mSpeeds->vel1 = (-SIN45 * speeds.x_speed + COS45 * speeds.y_speed + WHEEL_BASE / 2.0 * speeds.omega) / RADIUS;
    mSpeeds->vel2 = (-COS45 * speeds.x_speed - SIN45 * speeds.y_speed + WHEEL_BASE / 2.0 * speeds.omega) / RADIUS;
    mSpeeds->vel3 = (SIN45 * speeds.x_speed - COS45 * speeds.y_speed + WHEEL_BASE / 2.0 * speeds.omega) / RADIUS;
    mSpeeds->vel4 = (COS45 * speeds.x_speed + SIN45 * speeds.y_speed + WHEEL_BASE / 2.0 * speeds.omega) / RADIUS;
}

void desaturation(motorSpeeds_t *mSpeeds)
{
    float maximum = max(max(mSpeeds->vel1, mSpeeds->vel2), max(mSpeeds->vel3, mSpeeds->vel4));

    if (maximum > MAX_SPEED)
    {
        mSpeeds->vel1 *= MAX_SPEED / maximum;
        mSpeeds->vel2 *= MAX_SPEED / maximum;
        mSpeeds->vel3 *= MAX_SPEED / maximum;
        mSpeeds->vel4 *= MAX_SPEED / maximum;
    }
}
