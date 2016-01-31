#include "WPILib.h"
#include <VictorSP.h>
//#include <AxisCamera.h>
#include <Constants.h>

class Robot: public SampleRobot
{

	RobotDrive chassis; // robot drive system
	Joystick leftstick;
	Joystick rightstick;
	bool driveforward;
	Encoder leftencoder;
	Encoder rightencoder;
	VictorSP leftA;
	//VictorSP leftB;
	VictorSP rightA;
	//VictorSP rightB;
	LiveWindow *lw;
	int autoLoopCounter;

public:
	Robot() : chassis(LEFT_MOTOR_ID, RIGHT_MOTOR_ID),
		leftstick(LEFT_JOYSTICK_PORT),
		rightstick(RIGHT_JOYSTICK_PORT),
		driveforward(true),
		leftencoder(LEFT_CHANNEL_A, LEFT_CHANNEL_B),
		rightencoder(RIGHT_CHANNEL_A, RIGHT_CHANNEL_B),
		leftA(LEFT_MOTOR_ID),
		rightA(RIGHT_MOTOR_ID),
		lw(NULL),
		autoLoopCounter(0)
		{
		chassis.SetExpiration(0.1);
		}

	void OperatorControl()
	{
		chassis.SetSafetyEnabled(true);

		while(IsOperatorControl())
		{
			setDriveSpeed();
			Wait(0.005); //wait for motor update time

		}


	}

	void setDriveSpeed()
	{
		float leftstickvalue = -getJoystickTransform(leftstick.GetY());
		float rightstickvalue = -getJoystickTransform(rightstick.GetY());

		if(driveforward==true)
			chassis.TankDrive(leftstickvalue, rightstickvalue);
		else
			chassis.TankDrive(-leftstickvalue, -rightstickvalue);
	}

	float getJoystickTransform(float input)
	{
		return input;
	}

	void RobotInit()
		{
			lw = LiveWindow::GetInstance();
		}

	void Autonomous()
	{
		while(IsAutonomous() && IsEnabled())
		{
			Wait(0.005);
		}
	}


};

START_ROBOT_CLASS(Robot);
