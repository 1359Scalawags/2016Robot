#include "WPILib.h"
#include <VictorSP.h>
//#include <AxisCamera.h>
#include <Constants.h>

class BallHandler
{
private:
	bool ballsensor; //used to enable/disable the ball handler automatically
	VictorSP drive;
	VictorSP flip;
	VictorSP arm;

public:

	BallHandler() : ballsensor(BALL_SENSOR),
				drive(LIFT_MOTOR),
				flip(LIFT_FLIP),
				arm(LIFT_ARM)
				{

				}



	void Autonomousupdate()
	{

	}

	void update()
	{

	}
};
