#ifndef __CONTROL_DATA_H_
#define __CONTROL_DATA_H_

#include "stm32f4xx.h"
#include "remote.h"
#include "math2.h"

enum controlDevice
{
	mouse_keyboard_device_ENUM = 1u, ///< 操作设备为键鼠
	remote_controller_device_ENUM    ///< 操作设备为遥控器
};

enum rcMotionMode
{
	rc_chassis_follow_mode_ENUM = 1u,		  ///< 底盘跟随+手动瞄准
	rc_chassis_gyro_mode_ENUM,				  ///< 底盘小陀螺+手动瞄准
	rc_autoaim_chassis_follow_mode_ENUM = 1u, ///< 底盘跟随+自动瞄准
	rc_autoaim_chassis_gyro_mode_ENUM,		  ///< 底盘小陀螺+自动瞄准
	rc_special_mode_ENUM					  ///< 特殊模式
};

enum mouseKeyboardChassisMode
{
	mk_chassis_follow_mode_ENUM = 1u, ///< 底盘跟随
	mk_chassis_gyro_mode_ENUM,		  ///< 底盘小陀螺
	mk_chassis_special_mode_ENUM	  ///< 底盘特殊模式
};

enum mouseKeyboardAimMode
{
	mk_manual_aim_mode_ENUM = 1u, ///< 手动瞄准
	mk_auto_aim_mode_ENUM,		  ///< 自动瞄准
	mk_special_aim_mode_ENUM	  ///< 云台特殊模式
};

enum gyroDirection
{
	gyro_positive_ENUM = 1,  ///< 陀螺正向
	gyro_negative_ENUM = -1  ///< 陀螺反向
};

enum fricCoverMode
{
	fric_cover_off_mode_ENUM = 0u, ///< 摩擦轮关闭，弹舱盖关闭
	fric_adaptive_speed_mode_ENUM, ///< 摩擦轮自适应速度，弹舱盖关闭
	fric_high_speed_mode_ENUM,	   ///< 摩擦轮最高速度速度，弹舱盖关闭
	cover_on_ENUM				   ///< 摩擦轮关闭，弹舱盖开启
};

enum shooterMode
{
	on_shoot_mode_ENUM = 1u, ///< 单发
	rapid_fire_max_mode_ENUM ///< 高速连发
};

typedef struct
{
	struct
	{
		uint8_t control_device;				 ///< 控制设备 1键鼠模式(rc) 2遥控器模式(mouse_key)
		uint8_t rc_motion_mode;				 ///< 底盘云台模式 1底盘跟随 2小陀螺 3自瞄 底盘跟随 4自瞄小陀螺 5特殊
		uint8_t mouse_keyboard_chassis_mode; ///< 1跟随 2小陀螺 3特殊
		uint8_t mouse_keyboard_gimbal_mode;	 ///< 1手动 2自瞄 3特殊
		int8_t gyro_direction;              ///< -1陀螺反向 1陀螺正向
		uint8_t fric_cover_mode;			 ///< 摩擦轮模式 0关闭 1自适应 2最高速 3开舱盖
		uint8_t shoot_mode;					 ///< 射击模式 1单发 2连发（最大速度）
		uint8_t shoot_key;                   ///< 射击开关 0关闭
	} mode;

	struct
	{
		//鼠标最大速度
		int16_t mouse_x_max_value;
		int16_t mouse_y_max_value;

		//鼠标数据倍率(灵敏度)
		float mouse_x_sensitivity;
		float mouse_y_sensitivity;

		//底盘加速度
		int16_t chassis_acceleration;
		//底盘最大速度
		int16_t chassis_max_speed; //虚拟摇杆最大值
	}parameter;

	struct
	{
		int16_t ch0; //鼠标
		int16_t ch1; //鼠标
		int16_t ch2; //左右 键盘WS
		int16_t ch3; //前后 键盘AD
	} virtual_rocker;

	//ctrl按下切换
	//陀螺开关、正反-1 0 1
	//归入地盘模式
	//或者单独一个小陀螺 正反	
	
}Robot_control_data_t;

void Control_Data_Init(Robot_control_data_t* robot_control_data);
void Parse_Robot_Control_Data(Rc_Ctrl_t* rc_data, Rc_Ctrl_t* last_rc_data, Robot_control_data_t* robot_control_data);

#endif // __CONTROL_DATA_H_
