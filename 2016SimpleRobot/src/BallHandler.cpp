#include "WPILib.h"
#include <VictorSP.h>
//#include <AxisCamera.h>
#include <Constants.h>

const int HANDLER_FLIP_UP = 3;
const int HANDLER_FLIP_DOWN = 2;
const int HANDLER_BALL_IN = 4;
const int HANDLER_BALL_OUT = 5;
const int HANDLER_ON_OFF = 1;
const int BALLSWITCH = 7;


class BallHandler
{
private:

	VictorSP drive;
	VictorSP flipper; //use left joystick for ball handling buttons
	VictorSP arm;
	Joystick ballhandler;
	bool flipped = true;
	DigitalInput ballsensor; //used to enable/disable the ball handler automatically
	bool switched;

public:

	BallHandler() :
				drive(LIFT_MOTOR),
				flipper(LIFT_FLIP),
				arm(LIFT_ARM),
				ballhandler(LEFT_JOYSTICK_PORT),
				ballsensor(BALLSWITCH),
				switched(false)

	{

	}

	void update()
	{

		flip(); //controls flipping
		fire(); //controls firing

	}

	bool flip()
	{
		//handler flipper
		if(ballhandler.GetRawButton(HANDLER_FLIP_UP) == true && flipped != true)
		{
			//flip ball handler up only if it is already down
			flipup();
			flipped = true;

		}
		else if(ballhandler.GetRawButton(HANDLER_FLIP_DOWN) == true && flipped != false)
		{
			//flip ball handler down only if it is already up
			flipdown();
			flipped = false;

		}
		return flipped;
	}

	void enableHandlerDrive()
	{
		if(ballhandler.GetRawButton(HANDLER_ON_OFF) == true && flipped == false)
		{
			//if ballhandler is enabled while flipped up it will automatically flip down
			flipdown();
			handleron();

		}
		else if(ballhandler.GetRawButton(HANDLER_ON_OFF) == true && flipped == true)
		{
			handleron();
		}

	}
	void fire()
	{

		//control ball firing
		if(ballhandler.GetRawButton(HANDLER_BALL_IN) == true && ballsensor.Get() == false)
		{
			//Allow the Handler to be turned on to take a ball in



			disablehandler();
		}

		else if(ballhandler.GetRawButton(HANDLER_BALL_OUT) && ballsensor.Get() == true)
		{
			//Allow the ball to be fired only if a ball is present in the Handler
			if(ballsensor.Get() == true)
			{
				drive.Set(-0.75f);
			}
		}
	}

	void flipup()
	{
		//flip ball handler up only if it is already down
	}

	void flipdown()
	{
		//flip ball handler down only if it is already up
	}

	void handleron()
	{
		//powers on the ballhandler's belts
		drive.Set(0.75f);
	}
	void disablehandler()
	{
		//Disables the ballhandler when a ball is present
		if(ballsensor.Get() == true)
		{
			drive.Set(0);
		}
	}
};
