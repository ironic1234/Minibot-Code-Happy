#ifndef CHASSIS_TASK_H
#define CHASSIS_TASK_H
#include "robot.h"

typedef struct
{
    double vel1, vel2, vel3, vel4;
} motorSpeeds_t;

// Function prototypes
void Chassis_Task_Init(void);
void Chassis_Ctrl_Loop(void);
// float max(float, float, float, float);
// float max2(float, float);
// void mapping(Chassis_State_t, motorSpeeds_t*);
// void desaturation(motorSpeeds_t*);
void setMotors();

#endif // CHASSIS_TASK_H
