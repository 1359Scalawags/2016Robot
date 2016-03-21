#include "WPILib.h"
#include <VictorSP.h>
#include <Constants.h>
#include <string>
#include <Lift.cpp>



enum BallHandlerState
{
	up_off = 0,
	goingup_off = 1,
	goingdown_off = 2,
	down_off = 3,
	down_in = 4,
	down_out = 5
};

enum HandlerArmState
{
	folding_in = 0,
	folding_out = 1,
	in = 2,
	out = 3
};

class BallHandler
{
private:

	Relay drive; //belts for the Handler
	Talon sweeper; //flips the arm
	Relay handlerposition; //flips handler
	Talon spinmotor; //spins the arm
	Joystick ballhandlerstick;
	bool flipped = true;
	DigitalInput ballsensor; //used to enable/disable the ball handler automatically
	//bool switched;
	bool handler_on_off;
	Lift lifter;
	DigitalInput up_limit;
	DigitalInput down_limit;
	DigitalInput out_limit;
	DigitalInput in_limit;
	BallHandlerState handlerState;
	HandlerArmState armState;

public:

	BallHandler() :
				drive(BALL_HANDLER_MOTOR),
				sweeper(ARM_POSITION_MOTOR),
				handlerposition(HANDLER_POSITION),
				spinmotor(SPIN_MOTOR),
				ballhandlerstick(BUTTONS_JOYSTICK_PORT),
				ballsensor(BALLSWITCH),
				//switched(false)
				handler_on_off(false),
				lifter(&ballhandlerstick),
				up_limit(HANDLER_LIMIT_UP),
				down_limit(HANDLER_LIMIT_DOWN),
				out_limit(ARM_LIMIT_OUT),
				in_limit(ARM_LIMIT_IN),
				handlerState(goingup_off),
				armState(folding_in)
	{

	}

	void update()
	{
		processHandlerState();
		setDriveMotors();
		setFlipMotor();
		updateDashboard(handlerState, armState);
	}

/*
bool flip()
	{
		//handler flipper
		if(ballhandlerstick.GetRawButton(HANDLER_UP_BUTTON) == true && flipped != true)
		{
			//flip ball handler up only if it is already down
			flipup();
			flipped = true;

		}
		else if(ballhandlerstick.GetRawButton(HANDLER_DOWN_BUTTON) == true && flipped != false)
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

	*/

inline void processHandlerState()
	{
	if(ballhandlerstick.GetRawButton(RESET_BUTTON) == true)
	{
		handlerState = BallHandlerState::goingup_off;
		armState = HandlerArmState::folding_in;
	}else
	{
	    if(handlerState == BallHandlerState::up_off)
		{
			if(ballhandlerstick.GetRawButton(HANDLER_GRAB) == true)
			{
				handlerState = BallHandlerState::goingdown_off;
				armState = HandlerArmState::folding_out;
			}
			else if(ballhandlerstick.GetRawButton(HANDLER_SHOOT) == true)
			{
				handlerState = BallHandlerState::goingdown_off;
				armState = HandlerArmState::in;
			}
		}
		else if(handlerState == BallHandlerState::down_off)
		{
			//should never happen
			if(ballhandlerstick.GetRawButton(HANDLER_SHOOT) == true)
			{
				handlerState = BallHandlerState::down_out;
				armState = HandlerArmState::folding_in;
			}
			else if(ballhandlerstick.GetRawButton(HANDLER_GRAB) == true)
			{
				handlerState =  BallHandlerState::down_in;
				armState = HandlerArmState::folding_out; //may need changed
			}
			else
			{
				//should do nothing
			}
		}
		else if(handlerState == BallHandlerState::down_in)
		{
			if(ballhandlerstick.GetRawButton(HANDLER_UP_BUTTON) == true || ballsensor.Get() == PRESSED)
			{
				handlerState =  BallHandlerState::goingup_off;
				armState = HandlerArmState::folding_in;
			}
		}
		else if(handlerState == BallHandlerState::down_out)
		{
			if(ballhandlerstick.GetRawButton(HANDLER_GRAB) == true)
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
			else if(down_limit.Get() == PRESSED)
			{
				handlerState = BallHandlerState::down_off;
			}
		}
		else if(handlerState == BallHandlerState::goingup_off)
		{
			if(ballhandlerstick.GetRawButton(HANDLER_GRAB) == true)
			{
				handlerState = BallHandlerState::goingdown_off;
				armState = HandlerArmState::folding_out;
			}
			if(up_limit.Get() == PRESSED)
			{
				handlerState = BallHandlerState::up_off;
				armState = HandlerArmState::folding_in;
			}
		}
	}
		processArmState();

	}
inline	void processArmState()
	{
	//if else tree for ArmState
		if(armState == HandlerArmState::folding_out)
		{
			if(out_limit.Get() == PRESSED)
			{
				armState = HandlerArmState::out;
			}
		}
		else if(armState == HandlerArmState::folding_in)
		{
			if(in_limit.Get() == PRESSED)
			{
				armState = HandlerArmState::in;
			}
		}
	}

inline	void setDriveMotors()
	{
		//cannot turn belts if the limit switch is pressed
		if(handlerState == BallHandlerState::up_off)
		{
			drive.Set(Relay::kOff);
			spinmotor.Set(0);
			handlerposition.Set(Relay::kOff);
		}
		else if(handlerState == BallHandlerState::down_in)
		{
			drive.Set(Relay::kReverse);
			spinmotor.Set(0.75);
			handlerposition.Set(Relay::kOff);
		}
		else if(handlerState == BallHandlerState::down_out)
		{
			drive.Set(Relay::kForward);
			spinmotor.Set(-0.75f);
			handlerposition.Set(Relay::kOff);
		}
		else if(handlerState == BallHandlerState::goingdown_off)
		{
			drive.Set(Relay::kReverse);
			spinmotor.Set(0);
			handlerposition.Set(Relay::kReverse);
		}
		else if(handlerState == BallHandlerState::goingup_off)
		{
			drive.Set(Relay::kOff);
			spinmotor.Set(0);
			handlerposition.Set(Relay::kForward);
		}
		else
		{
			spinmotor.Set(0);
			drive.Set(Relay::kOff);
			handlerposition.Set(Relay::kOff);
		}

	}
	void updateDashboard(BallHandlerState bhs, HandlerArmState has) {
		std::string bhs_string = "Ball: " + BallHandlerStateDescriptions[bhs];
		SmartDashboard::PutString("DB/String 0", bhs_string);

		std::string has_string = "Arm: " + HandlerArmStateDescriptions[has];
		SmartDashboard::PutString("DB/String 1", has_string);

		//SmartDashboard::PutString("DB/String 2", boolAsString(ballsensor.Get()));
		//SmartDashboard::PutString("DB/String 3", boolAsString(handlerposition.Get()));
	}

	inline std::string boolAsString(bool b) {
		return b ? "true" : "false";
	}

inline	void setFlipMotor()
	{
		//set motors based on state
		if(armState == HandlerArmState::in)
		{
			sweeper.Set(-0.008);
		}
		else if(armState == HandlerArmState::out)
		{
			sweeper.Set(0);
		}
		else if(armState == HandlerArmState::folding_in)
		{
			sweeper.Set(-0.35f);
		}
		else if(armState == HandlerArmState::folding_out)
		{
			sweeper.Set(0.35f);
		}
		else
		{
			sweeper.Set(0.0f);
		}
	}


};
