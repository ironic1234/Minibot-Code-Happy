#include "gimbal_task.h"

#include "remote.h"
#include "robot.h"
#include "user_math.h"

extern Robot_State_t g_robot_state;
extern Remote_t g_remote;

const float YAW_KP = 0.0f;
const float YAW_KI = 0.0f;
const float YAW_KD = 0.0f;
const float YAW_CAN_ID = 0;
const float YAW_CONTROLLER_ID = 0;

DJI_Motor_Handle_t *yawMotor;

void Gimbal_Task_Init() {
  Motor_Config_t yaw_speed_config = {.can_bus = YAW_CAN_ID,
                                     .speed_controller_id = YAW_CONTROLLER_ID,
                                     .offset = 0,
                                     .control_mode = POSITION_CONTROL,
                                     .motor_reversal = MOTOR_REVERSAL_NORMAL,
                                     .angle_pid = {
                                         .kp = YAW_KP,
                                         .ki = YAW_KI,
                                         .kd = YAW_KD,
                                         .output_limit = M2006_MAX_CURRENT,
                                         .integral_limit = 0.00f,
                                     }};

  yawMotor = DJI_Motor_Init(&yaw_speed_config, M2006);
}

void Gimbal_Ctrl_Loop() { DJI_Motor_Set_Angle(yawMotor, 0); }
