#include "WPILib.h"
#include <VictorSP.h>
#include <Constants.h>

const int HANDLER_FLIP_UP = 3;
const int HANDLER_FLIP_DOWN = 2;
const int HANDLER_BALL_IN = 4;
const int HANDLER_BALL_OUT = 5;
const int HANDLER_ON_OFF = 1;
const int BALLSWITCH = 7;
const int HANDLER_FLIPPER = 21;
const int HANDLER_LIMIT_UP = 23;
const int HANDLER_LIMIT_DOWN = 24;

enum BallHandlerState{
	goingup_off = 1,
	goingdown_off = 2,
	down_on=3,
	down_off=4,
	up_off=5

};

enum HandlerArmState
{
	folding_in,
	folding_out,
	in,
	out
};
class BallHandler
{
private:

	VictorSP drive;
	VictorSP flipper; //use left joystick for ball handling buttons
	VictorSP arm;
	VictorSP handlerflip;
	Joystick ballhandlerstick;
	bool flipped = true;
	DigitalInput ballsensor; //used to enable/disable the ball handler automatically
	bool switched;
	bool handler_on_off;
	DigitalInput up_limit;
	DigitalInput down_limit;
	BallHandlerState handlerState;
	HandlerArmState armState;
public:

	BallHandler() :
				drive(LIFT_MOTOR),
				flipper(LIFT_FLIP),
				arm(LIFT_ARM),
				handlerflip(HANDLER_FLIPPER),
				ballhandlerstick(LEFT_JOYSTICK_PORT),
				ballsensor(BALLSWITCH),
				switched(false),
				handler_on_off(false),
				up_limit(HANDLER_LIMIT_UP),
				down_limit(HANDLER_LIMIT_DOWN),
				handlerState(up_off),
				armState(in)
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
		if(ballhandlerstick.GetRawButton(HANDLER_FLIP_UP) == true && flipped != true)
		{
			//flip ball handler up only if it is already down
			flipup();
			flipped = true;

		}
		else if(ballhandlerstick.GetRawButton(HANDLER_FLIP_DOWN) == true && flipped != false)
		{
			//flip ball handler down only if it is already up
			flipdown();
			flipped = false;

		}
		return flipped;
	}

	void enableHandlerDrive()
	{
		if(ballhandlerstick.GetRawButton(HANDLER_ON_OFF) == true && flipped == false)
		{
			//if ballhandler is enabled while flipped up it will automatically flip down
			flipdown();
			handleron();

		}
		else if(ballhandlerstick.GetRawButton(HANDLER_ON_OFF) == true && flipped == true)
		{
			handleron();
		}

	}
	void fire()
	{

		//control ball firing
		if(ballhandlerstick.GetRawButton(HANDLER_BALL_IN) == true && ballsensor.Get() == false)
		{
			//Allow the Handler to be turned on to take a ball in



			disablehandler();
		}

		else if(ballhandlerstick.GetRawButton(HANDLER_BALL_OUT) && ballsensor.Get() == true)
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
		if(up_limit.Get() == false)
		{
			handlerflip.Set(0.75f);
		}

	}

	void flipdown()
	{
		//flip ball handler down only if it is already up
		if(down_limit.Get() == false)
		{
			handlerflip.Set(-0.75f);
		}
	}

	void handleron()
	{
		//powers on the ballhandler's belts
		if(ballsensor.Get() != true)
		{
			drive.Set(0.75f);
		}
	}

	void disablehandler()
	{
		//Disables the ballhandler when a ball is present
		if(ballsensor.Get() == true)
		{
			drive.Set(0);
		}
	}

	void processUserInput()
	{

		switch(handlerState)
		{
		case BallHandlerState.up_off :
			if(ballhandlerstick.Get(HANDLER_FLIP_DOWN) == true)
			{

			}
			break;
		}


	}
};
