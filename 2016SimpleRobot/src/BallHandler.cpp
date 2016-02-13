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
const int HANDLER_GRAB = 2;
const int HANDLER_UP_BUTTON = 3;
const int HANDLER_IN_BUTTON = 4;
const int ARM_LIMIT_OUT = 18;
const int ARM_LIMIT_IN = 19;
const int ARM_DRIVE_MOTOR = 23;
const int ARM_OUT_BUTTON = 33;
const int ARM_IN_BUTTON = 34;
const int SPIN_MOTOR = 35;

enum BallHandlerState{
	up_off = 0,
	goingup_off = 1,
	goingdown_off = 2,
	down_off = 3,
	down_in = 4,
	down_out = 5



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
	VictorSP flipper; //flips arm
	VictorSP arm;
	VictorSP handlerflip; //flips handler
	VictorSP spinmotor;
	Joystick ballhandlerstick;
	bool flipped = true;
	DigitalInput ballsensor; //used to enable/disable the ball handler automatically
	bool switched;
	bool handler_on_off;
	DigitalInput up_limit;
	DigitalInput down_limit;
	DigitalInput out_limit;
	DigitalInput in_limit;
	BallHandlerState handlerState;
	HandlerArmState armState;
public:

	BallHandler() :
				drive(LIFT_MOTOR),
				flipper(LIFT_FLIP),
				arm(LIFT_ARM),
				handlerflip(HANDLER_FLIPPER),
				spinmotor(SPIN_MOTOR),
				ballhandlerstick(LEFT_JOYSTICK_PORT),
				ballsensor(BALLSWITCH),
				switched(false),
				handler_on_off(false),
				up_limit(HANDLER_LIMIT_UP),
				down_limit(HANDLER_LIMIT_DOWN),
				out_limit(ARM_LIMIT_OUT),
				in_limit(ARM_LIMIT_IN),
				handlerState(up_off),
				armState(in)
	{

	}

	void update()
	{

		processHandlerState();
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

	void processHandlerState()
	{

//		switch((int)handlerState)
//		{
//		case BallHandlerState::up_off:
//			if(ballhandlerstick.Get(HANDLER_FLIP_DOWN) == true)
//			{
//
//			}
//			bre
//		}

		if(handlerState == BallHandlerState::up_off)
		{
			if(ballhandlerstick.GetRawButton(HANDLER_GRAB)  == true)
			{
				handlerState = BallHandlerState::goingdown_off;
				armState = HandlerArmState::folding_out;
			}
		}
		else if(handlerState == BallHandlerState::down_off)
		{
			//should never happen
			handlerState =  BallHandlerState::down_in;
			armState = HandlerArmState::folding_out; //may need changed
		}
		else if(handlerState == BallHandlerState::down_in)
		{
			if(ballhandlerstick.GetRawButton(HANDLER_UP_BUTTON) == true || ballsensor.Get() == true)
			{
				handlerState =  BallHandlerState::goingup_off;
				armState = HandlerArmState::folding_in;
			}
		}
		else if(handlerState == BallHandlerState::goingdown_off)
		{
			if(ballhandlerstick.GetRawButton(HANDLER_UP_BUTTON) == true)
			{
				handlerState = BallHandlerState::goingup_off;
				armState = HandlerArmState::folding_in;
			}
			if(down_limit.Get() == true)
			{
				handlerState = BallHandlerState::down_off;

			}
		}
		else if(handlerState == BallHandlerState::goingup_off)
		{
			if(ballhandlerstick.GetRawButton(HANDLER_GRAB) == true)
			{
				handlerState = BallHandlerState::down_in;
				armState = HandlerArmState::folding_out;
			}
			if(up_limit.Get() == true)
			{
				handlerState = BallHandlerState::up_off;
				armState = HandlerArmState::folding_in;
			}
		}

		processArmState();


	}
	void processArmState()
	{
	//if else tree for ArmState
		if(armState == HandlerArmState::folding_out)
		{
			if(out_limit.Get() == true)
			{
				armState = HandlerArmState::out;
			}
		}
		else if(armState == HandlerArmState::folding_in)
		{
			if(in_limit.Get() == true)
			{
				armState = HandlerArmState::in;
			}
		}

	}

	void setDriveMotors()
	{
		if(handlerState == BallHandlerState::up_off)
		{
			drive.Set(0);
		}
		else if(handlerState == BallHandlerState::down_in)
		{
			drive.Set(0.75f);
		}
		else if(handlerState == BallHandlerState::down_out)
		{
			drive.Set(-0.75f);
		}
		else if(handlerState == BallHandlerState::goingdown_off)
		{
			drive.Set(0);
		}
		else if(handlerState == BallHandlerState::goingup_off)
		{
			drive.Set(0);
		}
	}

	void setFlipMotor()
	{

		//set motors based on state
		if(handlerState == BallHandlerState::up_off)
		{
			handlerflip.Set(0);
			spinmotor.Set(0);
		}
		else if(handlerState == BallHandlerState::down_in)
		{
			handlerflip.Set(0);
			spinmotor.Set(0);

		}
		else if(handlerState == BallHandlerState::goingdown_off)
		{
			handlerflip.Set(-0.75f);
			spinmotor.Set(0.75f);
			flipper.Set(-0.75f);
		}
		else if(handlerState == BallHandlerState::goingup_off)
		{
			handlerflip.Set(0.75f);
			spinmotor.Set(-0.75f);
			flipper.Set(0.75f);
		}


	}
};
