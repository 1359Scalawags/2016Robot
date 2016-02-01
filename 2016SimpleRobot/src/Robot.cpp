#include "WPILib.h"
#include <VictorSP.h>
#include <Constants.h>
#include <BallHandler.cpp>
#include <Lift.cpp>

class Robot: public SampleRobot
{

	RobotDrive chassis; // robot drive system

	//joysticks for control
	Joystick leftstick;
	Joystick rightstick;

	//controls whether or not the robbot can go forward
	bool driveforward;

	//encoders
	Encoder leftencoder;
	Encoder rightencoder;

	//speed controllers
	VictorSP leftA;
	//VictorSP leftB;
	VictorSP rightA;
	//VictorSP rightB;

	//variables for camera
	LiveWindow *lw;
	int autoLoopCounter;

	//objects for the other systems on the robot
	BallHandler ballhandler;
	Lift lift;

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
		autoLoopCounter(0),
		ballhandler(),
		lift()
		{
		chassis.SetExpiration(0.1);
		}

	void OperatorControl()
	{
		chassis.SetSafetyEnabled(true);

		while(IsOperatorControl() && IsEnabled())
		{
			setDriveSpeed();
			ballhandler.update();
			lift.update();
			Wait(0.005); //wait for motor update time

		}
	}

	void setDriveSpeed() //take input from the joysticks and sets the drive speed
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
		//for adjustment of speed profile
		//for now does nothing only passes code through
		return input;
	}

	void RobotInit()
		{
			//camera stuff
			lw = LiveWindow::GetInstance();
		}

	void Autonomous() //controls autonomous
	{
		while(IsAutonomous() && IsEnabled())
		{
			Wait(0.005);
		}
	}


};

START_ROBOT_CLASS(Robot);
