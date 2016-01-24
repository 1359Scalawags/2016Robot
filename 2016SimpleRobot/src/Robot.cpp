#include "WPILib.h"


const int LEFT_MOTOR_ID = NULL;
const int RIGHT_MOTOR_ID = NULL;
const int RIGHT_CHANNEL_A = NULL;
const int RIGHT_CHANNEL_B = NULL;
const int LEFT_CHANNEL_A = NULL;
const int LEFT_CHANNEL_B = NULL;
const int LEFT_JOYSTICK_PORT = NULL;
const int RIGHT_JOYSTICK_PORT = NULL;
const int DRIVE_FORWARD = NULL;
const int DRIVE_REVERSE = NULL;



class Robot: public IterativeRobot
{

	RobotDrive chassis; // robot drive system
	Joystick leftstick;
	Joystick rightstick;
	bool driveforward;
	Encoder leftencoder;
	Encoder rightencoder;

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
