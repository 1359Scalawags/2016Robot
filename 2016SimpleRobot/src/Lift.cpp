#include "WPILib.h"
#include <VictorSP.h>
#include <Constants.h>



class Lift
{

private:
	Joystick liftbuttons;
	Talon lift;
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
			lift.Set(LIFT_MOTOR_SPEED);
		}
		else if(liftbuttons.GetRawButton(LIFT_BUTTON_DOWN) == true)
		{
			//lower tape measure
			lift.Set(-LIFT_MOTOR_SPEED);
		}
		else
		{
			//turn off tape measure motor
			lift.Set(0);
		}


	}
};
