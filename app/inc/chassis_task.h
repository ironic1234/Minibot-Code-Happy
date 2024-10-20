#ifndef CHASSIS_TASK_H
#define CHASSIS_TASK_H

typedef struct
{
    double vel1, vel2, vel3, vel4;
} motorSpeeds_t;

#define FOR_EACH_MOTOR_SPEED(motor, speed, id)                        \
    for (int id = 0, _count = sizeof(motorSpeeds_t) / sizeof(double), \
             _i = 0;                                                  \
         id < _count && (_i++, 1); ++id)                              \
        for (double speed = *(((double *) &(motor)) + id); _i == 1; _i = 0)

// Function prototypes
void Chassis_Task_Init(void);
void Chassis_Ctrl_Loop(void);
// float max(float, float, float, float);
// float max2(float, float);
// void mapping(Chassis_State_t, motorSpeeds_t*);
// void desaturation(motorSpeeds_t*);
void setMotors();

#endif // CHASSIS_TASK_H
