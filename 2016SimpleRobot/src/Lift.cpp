#include "WPILib.h"
#include <VictorSP.h>
//#include <AxisCamera.h>
#include <Constants.h>


class Lift
{

private:
	VictorSP lift;
	bool iflift;
	//Servo ratchet;

public:
	Lift() : lift(LIFT_MOTOR),
		iflift(false)
	{

	}

	void Autonomousupdate()
	{

	}

	void update()
	{

	}
};
