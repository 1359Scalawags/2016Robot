#include "WPILib.h"
#include <VictorSP.h>

const int LEFT_MOTOR_ID = NULL;
const int RIGHT_MOTOR_ID = NULL;
const int RIGHT_CHANNEL_A = NULL;
const int RIGHT_CHANNEL_B = NULL;
const int LEFT_CHANNEL_A = NULL;
const int LEFT_CHANNEL_B = NULL;
const int LEFT_JOYSTICK_PORT = NULL;
const int RIGHT_JOYSTICK_PORT = NULL;
const int TEST_MOTOR_ID_1 = NULL;
const int TEST_MOTOR_ID_2 = NULL;
const int BALL_HANDLER_MOTOR = NULL;
const int BALL_SENSOR = NULL;



class Robot: public IterativeRobot
{

	RobotDrive chassis; // robot drive system
	Joystick leftstick;
	Joystick rightstick;
	bool driveforward;
	Encoder leftencoder;
	Encoder rightencoder;
	VictorSP leftA;
	VictorSP leftB;
	VictorSP rightA;
	VictorSP rightB;
	LiveWindow *lw;
	int autoLoopCounter;

public:
	Robot() :
		chassis(LEFT_MOTOR_ID, RIGHT_MOTOR_ID),
		leftstick(LEFT_JOYSTICK_PORT),
		rightstick(RIGHT_JOYSTICK_PORT),	// these must be initialized in the same order
		leftencoder(LEFT_CHANNEL_A, LEFT_CHANNEL_B),
		rightencoder(RIGHT_CHANNEL_A, RIGHT_CHANNEL_B),


		lw(LiveWindow::GetInstance()),
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
			Wait(0.005) //wait for motor update time

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

	void getJoystickTransform(float input)
	{

	}


private:
	void AutonomousInit()
	{
		autoLoopCounter = 0;
	}

	void AutonomousPeriodic()
	{
		if(autoLoopCounter < 100) //Check if we've completed 100 loops (approximately 2 seconds)
		{
			chassis.Drive(-0.5, 0.0); 	// drive forwards half speed
			autoLoopCounter++;
			} else {
			chassis.Drive(0.0, 0.0); 	// stop robot
		}
	}

	void TeleopInit()
	{

	}

	void TeleopPeriodic()
	{
		chassis.TankDrive(leftstick, rightstick); // drive with arcade style (use right stick)
	}

	void TestPeriodic()
	{
		lw->Run();
	}
};


START_ROBOT_CLASS(Robot)
