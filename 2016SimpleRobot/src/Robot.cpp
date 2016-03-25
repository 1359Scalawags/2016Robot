#include "WPILib.h"
#include <VictorSP.h>
#include <Constants.h>
#include <BallHandler.cpp>
#include <Timer.h>


class Robot: public SampleRobot
{

	RobotDrive chassis; // robot drive system

	//joysticks for control
		Joystick leftstick;
		Joystick rightstick;
		//Joystick Three;

	//controls whether or not the robbot can go forward
		bool driveforward;

	//encoders
		Encoder leftencoder;
		Encoder rightencoder;

	//speed controllers
		VictorSP leftA;
		VictorSP leftB;
		VictorSP rightA;
		VictorSP rightB;

	//variables for camera
		LiveWindow *lw;
		int autoLoopCounter;

	//objects for the other systems on the robot
		BallHandler ballhandler;





public:
	Robot() : chassis(LEFTA_MOTOR_ID, LEFTB_MOTOR_ID, RIGHTA_MOTOR_ID, RIGHTB_MOTOR_ID),
		leftstick(LEFT_JOYSTICK_PORT),
		rightstick(RIGHT_JOYSTICK_PORT),
		driveforward(true),
		leftencoder(LEFT_CHANNEL_A, LEFT_CHANNEL_B),
		rightencoder(RIGHT_CHANNEL_A, RIGHT_CHANNEL_B),
		leftA(LEFTA_MOTOR_ID),
		leftB(LEFTB_MOTOR_ID),
		rightA(RIGHTA_MOTOR_ID),
		rightB(RIGHTB_MOTOR_ID),
		lw(NULL),
		autoLoopCounter(0),
		ballhandler()
		{
		chassis.SetExpiration(0.1);
		//leftencoder.SetDistancePerPulse(5);
		//rightencoder.SetDistancePerPulse(5);
		}

	void OperatorControl()
	{
		chassis.SetSafetyEnabled(true);

		while(IsOperatorControl() && IsEnabled())
		{

				setDriveSpeed();
				ballhandler.update();
				//lift.update();


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
		//chassis.SetSafetyEnabled(true)
		Timer* drivetimer = new Timer();
		drivetimer->Start();
		while(IsAutonomous() && IsEnabled())
		{
			if(drivetimer->Get() < AUTO_DRIVE_TIME)
			{
				chassis.TankDrive(0.5f, 0.5f);
			}
			else
			{
				chassis.TankDrive(0.0f, 0.0f);
			}

			Wait(0.005);
		}
		drivetimer->Stop();
		delete drivetimer;
	}


};

START_ROBOT_CLASS(Robot);
