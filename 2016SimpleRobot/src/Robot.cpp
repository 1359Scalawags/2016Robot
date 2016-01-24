#include "WPILib.h"



const int RIGHT_CHANNEL_A = NULL;
const int RIGHT_CHANNEL_B = NULL;
const int LEFT_CHANNEL_A = NULL;
const int LEFT_CHANNEL_B = NULL;
const int LEFT_MOTOR_ID = NULL;
const int RIGHT_MOTOR_ID = NULL;
const int LEFT_JOYSTICK_PORT = NULL;
const int RIGHT_JOYSTICK_PORT = NULL;
const int DRIVE_FORWARD = NULL;
const int DRIVE_REVERSE = NULL;


class Robot: public IterativeRobot
{

	RobotDrive myRobot; // robot drive system
	Joystick stick; // only joystick
	LiveWindow *lw;
	int autoLoopCounter;

public:
	Robot() :
		myRobot(0, 1),	// these must be initialized in the same order
		stick(0),		// as they are declared above.
		lw(LiveWindow::GetInstance()),
		autoLoopCounter(0)
	{
		myRobot.SetExpiration(0.1);
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
			myRobot.Drive(-0.5, 0.0); 	// drive forwards half speed
			autoLoopCounter++;
			} else {
			myRobot.Drive(0.0, 0.0); 	// stop robot
		}
	}

	void TeleopInit()
	{

	}

	void TeleopPeriodic()
	{
		myRobot.ArcadeDrive(stick); // drive with arcade style (use right stick)
	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot)
