#include "WPILib.h"
#include <VictorSP.h>
#include <Constants.h>

//these are the constants specific to this class for global constants look in Constants.h

//buttons to make the Lift go up and down
	const int LIFT_BUTTON_UP = 3;
	const int LIFT_BUTTON_DOWN = 2;

//Servo that may be on the lift
	const int SERVO_MOTOR_ID = 17;

	const bool IFLIFT = true;


class Lift
{

private:
	Joystick liftbuttons;
	VictorSP lift;
	bool iflift;
	bool liftup;
	bool liftdown;
	//Servo ratchet;

public:
	Lift() : liftbuttons(RIGHT_JOYSTICK_PORT),
		lift(LIFT_MOTOR),
		iflift(false),
		liftup(false),
		liftdown(false)
	{
		lift.SetInverted(false);
	}

	void update()
	{
		if(liftbuttons.GetRawButton(LIFT_BUTTON_UP) == true)
		{
			//raises tape measure
			lift.Set(0.9f);
		}
		else if(liftbuttons.GetRawButton(LIFT_BUTTON_DOWN) == true)
		{
			//lower tape measure
			lift.Set(-0.9f);
		}

		else
		{
			//turn off tape measure motor
			lift.Set(0);
		}


	}
};
