#include "WPILib.h"
#include <VictorSP.h>
//#include <AxisCamera.h>
#include <Constants.h>

const int LIFT_BUTTON_UP = 3;
const int LIFT_BUTTON_DOWN = 2;

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

	}

	void Autonomousupdate()
	{

	}

	void update()
	{
		if(liftbuttons.GetRawButton(LIFT_BUTTON_UP) == true)
		{
			//raises tape measure
		}
		else
		{
			if(liftbuttons.GetRawButton(LIFT_BUTTON_DOWN) == true)
			{
				//lower tape measure
			}

			else
			{
				//turn off tape measure motor
			}
		}

	}
};
