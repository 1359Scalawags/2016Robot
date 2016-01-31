#include "WPILib.h"
#include <VictorSP.h>
//#include <AxisCamera.h>
#include <Constants.h>

const int HANDLER_FLIP_UP = 3;
const int HANDLER_FLIP_DOWN = 2;
const int HANDLER_BALL_IN = 4;
const int HANDLER_BALL_OUT = 5;
const int HANDLER_ON_OFF = 1;


class BallHandler
{
private:
	bool ballsensor; //used to enable/disable the ball handler automatically
	VictorSP drive;
	VictorSP flipper; //use left joystick for ball handling buttons
	VictorSP arm;
	Joystick ballhandler;
	bool flipped = true;

public:

	BallHandler() : ballsensor(BALL_SENSOR),
				drive(LIFT_MOTOR),
				flipper(LIFT_FLIP),
				arm(LIFT_ARM),
				ballhandler(LEFT_JOYSTICK_PORT)

	{

	}

	void update()
	{

		flip();
		fire();

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

	void fire()
	{

		//control ball firing
		if(ballhandler.GetRawButton(HANDLER_BALL_IN) == true && ballsensor == false)
		{
			//Allow the Handler to be turned on to take a ball in
		}

		else if(ballhandler.GetRawButton(HANDLER_BALL_OUT) && ballsensor == true)
		{
			//Allow the ball to be fired only if a ball is present in the Handler
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
};
