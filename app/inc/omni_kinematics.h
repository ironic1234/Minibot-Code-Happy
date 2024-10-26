#include "chassis_task.h"
#include "robot.h"

#define RADIUS 0.035
#define WHEEL_BASE 0.26
#define MAX_SPEED 10
#define MAX_SPEED_RPS 5 / 3.1415

#define SIN45 0.70710678818
#define COS45 0.70710678818

float max(float x, float y);

void mapping(Chassis_State_t speeds, motorSpeeds_t *mSpeeds);
void desaturation(motorSpeeds_t *mSpeeds);
