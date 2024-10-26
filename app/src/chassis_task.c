#include "chassis_task.h"
#include "dji_motor.h"
#include "omni_kinematics.h"

#include "robot.h"
#include "remote.h"

#define KP 500.0f
#define KI 0.0f
#define KF 0.0f

extern Robot_State_t g_robot_state;
extern Remote_t g_remote;

motorSpeeds_t mSpeeds = {0, 0, 0, 0};

DJI_Motor_Handle_t *motors[4] = {NULL, NULL, NULL, NULL};
int motor_ids[4] = {1, 2, 3, 4};

void Chassis_Task_Init()
{
    // Init chassis hardware

    for (int i = 0; i < 4; i++)
    {
        Motor_Config_t config = {
            .can_bus = 1,
            .speed_controller_id = motor_ids[i],
            .offset = 0,
            .control_mode = VELOCITY_CONTROL,
            .motor_reversal = MOTOR_REVERSAL_NORMAL,
            .velocity_pid = {
                .kp = KP,
                .ki = KI,
                .kf = KF,
                .output_limit = M2006_MAX_CURRENT,
            }};
        motors[i] = DJI_Motor_Init(&config, M2006);
    }
}

void Chassis_Ctrl_Loop()
{
    g_robot_state.chassis.x_speed = g_robot_state.input.vx / 660 * MAX_SPEED_RPS * 8191;
    g_robot_state.chassis.y_speed = g_robot_state.input.vy / 660 * MAX_SPEED_RPS * 8191;
    g_robot_state.chassis.omega = g_robot_state.input.vomega / 660 * 10;

    

    // Control loop for the chassis
    // mapping(g_robot_state.chassis, &mSpeeds);
    // desaturation(&mSpeeds);
    setMotors();
}

void setMotors()
{
    DJI_Motor_Set_Velocity(motors[0], mSpeeds.vel1);
    DJI_Motor_Set_Velocity(motors[1], mSpeeds.vel2);
    DJI_Motor_Set_Velocity(motors[2], mSpeeds.vel3);
    DJI_Motor_Set_Velocity(motors[3], mSpeeds.vel4);
}

// void mapping(Chassis_State_t speeds, motorSpeeds_t *mSpeeds)
// {
//     (*mSpeeds).vel1 = -1 * sin(THETA) * speeds.x_speed + cos(THETA) * speeds.y_speed + DIST * speeds.omega;
//     (*mSpeeds).vel2 = -1 * cos(THETA) * speeds.x_speed - sin(THETA) * speeds.y_speed + DIST * speeds.omega;
//     (*mSpeeds).vel3 = sin(THETA) * speeds.x_speed - cos(THETA) * speeds.y_speed + DIST * speeds.omega;
//     (*mSpeeds).vel4 = cos(THETA) * speeds.x_speed + sin(THETA) * speeds.y_speed + DIST * speeds.omega;
// }
//
// void desaturation(motorSpeeds_t *mSpeeds)
// {
//     float bigSpeed = max((*mSpeeds).vel1, (*mSpeeds).vel2, (*mSpeeds).vel3, (*mSpeeds).vel4);
//
//     if (bigSpeed > MAX_SPEED)
//     {
//         float ratio = MAX_SPEED / bigSpeed;
//
//         (*mSpeeds).vel1 *= ratio;
//         (*mSpeeds).vel2 *= ratio;
//         (*mSpeeds).vel3 *= ratio;
//         (*mSpeeds).vel4 *= ratio;
//     }
// }
//
// float max(float a, float b, float c, float d)
// {
//     float m = max2(a, b);
//     m = max2(m, c);
//     m = max2(m, d);
//
//     return m;
// }
//
// float max2(float a, float b)
// {
//     if (a > b) return a;
//     return b;
// }
