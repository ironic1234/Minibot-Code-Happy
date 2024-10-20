#include "chassis_task.h"
#include "robot.h"

#define RADIUS 0.035
#define WHEEL_BASE 0.26
#define MAX_SPEED 0.5

#define SIN45 0.70710678818
#define COS45 0.70710678818

float max(float, float);

void mapping(Chassis_State_t, motorSpeeds_t *);
void desaturation(motorSpeeds_t *);
