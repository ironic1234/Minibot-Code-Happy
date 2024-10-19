#include "chassis_task.h"

#include "remote.h"
#include "robot.h"

extern Robot_State_t g_robot_state;
extern Remote_t g_remote;

float chassis_rad;

const float FRONT_LEFT_KP = 0.0f;
const float FRONT_LEFT_KD = 0.0f;
const float FRONT_LEFT_KF = 0.0f;
const float FRONT_LEFT_CAN_ID = 0;
const float FRONT_LEFT_CONTROLLER_ID = 0;

const float FRONT_RIGHT_KP = 0.0f;
const float FRONT_RIGHT_KD = 0.0f;
const float FRONT_RIGHT_KF = 0.0f;
const float FRONT_RIGHT_CAN_ID = 0;
const float FRONT_RIGHT_CONTROLLER_ID = 0;

const float BACK_LEFT_KP = 0.0f;
const float BACK_LEFT_KD = 0.0f;
const float BACK_LEFT_KF = 0.0f;
const float BACK_LEFT_CAN_ID = 0;
const float BACK_LEFT_CONTROLLER_ID = 0;

const float BACK_RIGHT_KP = 0.0f;
const float BACK_RIGHT_KD = 0.0f;
const float BACK_RIGHT_KF = 0.0f;
const float BACK_RIGHT_CAN_ID = 0;
const float BACK_RIGHT_CONTROLLER_ID = 0;

DJI_MOTOR_HANDLE_t *frontLeftMotor;
DJI_MOTOR_HANDLE_t *frontRightMotor;
DJI_MOTOR_HANDLE_t *backLeftMotor;
DJI_MOTOR_HANDLE_t *backRightMotor;


void Chassis_Task_Init()
{
    // Init chassis hardware
    Motor_Config_t front_left_speed_config = {
        .can_bus = FRONT_LEFT_CAN_ID,
        .speed_controller_id = FRONT_LEFT_CONTROLLER_ID,
        .offset = 0,
        .control_mode = VELOCITY_CONTROL,
        .motor_reversal = MOTOR_REVERSAL_NORMAL,
        .velocity_pid = 
            {
                .kp = FRONT_LEFT_KP,
                .kd = FRONT_LEFT_KD,
                .kf = FRONT_LEFT_KF,
                .output_limit = M2006_MAX_CURRENT,
            }
    };

    Motor_Config_t front_right_speed_config = {
        .can_bus = FRONT_RIGHT_CAN_ID,
        .speed_controller_id = FRONT_RIGHT_CONTROLLER_ID,
        .offset = 0,
        .control_mode = VELOCITY_CONTROL,
        .motor_reversal = MOTOR_REVERSAL_NORMAL,
        .velocity_pid = 
            {
                .kp = FRONT_RIGHT_KP,
                .kd = FRONT_RIGHT_KD,
                .kf = FRONT_RIGHT_KF,
                .output_limit = M2006_MAX_CURRENT,
            }
    };

    Motor_Config_t back_left_speed_config = {
        .can_bus = BACK_LEFT_CAN_ID,
        .speed_controller_id = BACK_LEFT_CONTROLLER_ID,
        .offset = 0,
        .control_mode = VELOCITY_CONTROL,
        .motor_reversal = MOTOR_REVERSAL_NORMAL,
        .velocity_pid = 
            {
                .kp = BACK_LEFT_KP,
                .kd = BACK_LEFT_KD,
                .kf = BACK_LEFT_KF,
                .output_limit = M2006_MAX_CURRENT,
            }
    };

    Motor_Config_t back_right_speed_config = {
        .can_bus = BACK_RIGHT_CAN_ID,
        .speed_controller_id = BACK_RIGHT_CONTROLLER_ID,
        .offset = 0,
        .control_mode = VELOCITY_CONTROL,
        .motor_reversal = MOTOR_REVERSAL_NORMAL,
        .velocity_pid = 
            {
                .kp = BACK_RIGHT_KP,
                .kd = BACK_RIGHT_KD,
                .kf = BACK_RIGHT_KF,
                .output_limit = M2006_MAX_CURRENT,
            }
    };

    frontLeftMotor = DJI_Motor_Init(&front_left_speed_config, M2006);
    frontRightMotor = DJI_Motor_Init(&front_right_speed_config, M2006);
    backLeftMotor = DJI_Motor_Init(&back_left_speed_config, M2006);
    backRightMotor = DJI_Motor_Init(&back_right_speed_config, M2006);
}

void Chassis_Ctrl_Loop() {
    // Control loop for the chassis
    double xTargetVel = 0;    //Somehow get inputs???
    double yTargetVel = 0;    //Somehow get inputs???\


}
