#include "gimbal_task.h"

#include "remote.h"
#include "robot.h"
#include "user_math.h"

extern Robot_State_t g_robot_state;
extern Remote_t g_remote;

DJI_Motor_Handle_t *yawMotor;

void Gimbal_Task_Init() {
  Motor_Config_t yaw_speed_config = {
    .can_bus = 1,
    .speed_controller_id = 1,
    .offset = 0,
    .control_mode = POSITION_CONTROL,
    .motor_reversal = MOTOR_REVERSAL_NORMAL,
    .velocity_pid = 
      {
        .kp = 0.00f;
        .ki = 0.00f, 
        .kd = 0.00f, 
        .output_limit = M2006_MAX_CURRENT,
      }
    .angle_pid = 
      {
	.kp = 0.00f,
	.ki = 0.00f,
	.kd = 0.00f,
	.output_limit = M2006_MAX_CURRENT,
	.integral_limit = 0.00f,
      }
  };

  yawMotor = DJI_Motor_Init(&yaw_speed_config, M2006);
}

void Gimbal_Ctrl_Loop() {
  // Control loop for gimbal
}
