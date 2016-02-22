#include "WPILib.h"
#include <VictorSP.h>
#include <Constants.h>



class MotorTest
{

private:



	//joysticks for control
		Joystick teststick;

	//
		Relay drive; //belts for the Handler
		Talon armflipper; //flips the arm
		Relay handlerposition; //flips handler
		Talon spinmotor; //spins the arm
		Talon lift;

		int motor = 0;

public:
	MotorTest() :teststick(TEST_JOYSTICK_PORT),
			drive(BALL_HANDLER_MOTOR),
			armflipper(ARM_POSITION_MOTOR),
			handlerposition(HANDLER_POSITION),
			spinmotor(SPIN_MOTOR),
			lift(LIFT_MOTOR_SPEED)
			{
			//leftencoder.SetDistancePerPulse(5);
			//rightencoder.SetDistancePerPulse(5);
			}

void update()
{
	float testval = teststick.GetY();

	if(teststick.GetRawButton(1) == true)
	{
		if(testval > 0.25f)
		{
			drive.Set(Relay::kForward);
		}
		else if(testval < -0.25f)
		{
			drive.Set(Relay::kReverse);
		}
		else
		{
			drive.Set(Relay::kOff);
		}

	}
	else if(teststick.GetRawButton(2) == true)
	{
		armflipper.Set(testval);
	}
	else if(teststick.GetRawButton(3) == true)
	{

		if(testval > 0.25f)
		{
			handlerposition.Set(Relay::kForward);
		}
		else if(testval < -0.25f)
		{
			handlerposition.Set(Relay::kReverse);
		}
		else
		{
			handlerposition.Set(Relay::kOff);
		}

	}
	else if(teststick.GetRawButton(4) == true)
	{
		spinmotor.Set(testval);
	}
	else if(teststick.GetRawButton(5) == true)
	{
		lift.Set(testval);
	}


}

};
