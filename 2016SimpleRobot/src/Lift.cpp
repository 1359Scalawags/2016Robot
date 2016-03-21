#include "WPILib.h"
#include <VictorSP.h>
#include <Constants.h>



class Lift
{

private:
	Joystick liftbuttons;
	Talon liftmotor;
	bool iflift;
	bool liftup;
	bool liftdown;
	//Servo ratchet;


public:
	Lift() : liftbuttons(RIGHT_JOYSTICK_PORT),
		liftmotor(LIFT_MOTOR),
		iflift(false),
		liftup(false),
		liftdown(false)
	{
		liftmotor.SetInverted(false);
	}

	inline void update()
	{
		if(liftbuttons.GetRawButton(LIFT_BUTTON_UP) == true)
		{
			//raises tape measure
			liftmotor.Set(LIFT_MOTOR_SPEED);
		}
		else if(liftbuttons.GetRawButton(LIFT_BUTTON_DOWN) == true)
		{
			//lower tape measure
			liftmotor.Set(-LIFT_MOTOR_SPEED);
		}
		else
		{
			//turn off tape measure motor
			liftmotor.Set(0);
		}


	}
};
