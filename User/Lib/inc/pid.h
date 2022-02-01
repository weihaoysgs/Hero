#ifndef __PID_H
#define __PID_H

#include "stm32f4xx.h"
// static Pid_Position_t motor_yaw_speed_pid = NEW_POSITION_PID(1800, 0.8, 0.2, 5000, 30000, 0, 1000, 500); //yaw电机速度PID

#define NEW_POSITION_PID(p, i, d, limit_i, limit_out, is_i_spare, begin_i, stop_grow_i) \
	{                                                                                   \
		.kp = p,                                                                        \
		.ki = i,                                                                        \
		.kd = d,                                                                        \
		.tar = 0,                                                                       \
		.cur = 0,                                                                       \
		.err = 0,                                                                       \
		.old_err = 0,                                                                   \
		.err_integral = 0,                                                              \
		.is_integral_spare = is_i_spare,                                                \
		.begin_integral = begin_i,                                                      \
		.stop_grow_integral = stop_grow_i,                                              \
		.p_out = 0,                                                                     \
		.i_out = 0,                                                                     \
		.d_out = 0,                                                                     \
		.output = 0,                                                                    \
		.max_err_integral = limit_i,                                                    \
		.max_out = limit_out                                                            \
	}

#define NEW_INCREMENT_PID(p, i, d, limit) \
	{                                     \
		.kp = p,                          \
		.ki = i,                          \
		.kd = d,                          \
		.tar = 0,                         \
		.cur = 0,                         \
		.err = 0,                         \
		.old_err = 0,                     \
		.old_old_err = 0,                 \
		.p_out = 0,                       \
		.i_out = 0,                       \
		.d_out = 0,                       \
		.output = 0,                      \
		.max_out = limit                  \
	}

typedef struct
{
	float kp;
	float ki;
	float kd;

	float tar;
	float cur;

	float err;
	float old_err;
	float err_integral;

	uint8_t is_integral_spare;

	float begin_integral;
	float stop_grow_integral;

	float max_err_integral;
	float max_out;

	float p_out;
	float i_out;
	float d_out;
	float output;

} Pid_Position_t;

typedef struct
{

	float kp;
	float ki;
	float kd;

	float tar;
	float cur;

	float err;
	float old_err;
	float old_old_err;

	float max_out;

	float p_out;
	float i_out;
	float d_out;

	float output;

	float angle_output;
	///<这里参照其他学校的PID结构体，看要不要做成包含双环所有参数，使用时各调用各的

} Pid_Increment_t;

float Pid_Position_Calc(Pid_Position_t *pid, float tar, float cur);
float Pid_Increment_Calc(Pid_Increment_t *pid, float tar, float cur);

#endif
