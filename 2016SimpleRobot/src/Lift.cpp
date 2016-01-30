#include "WPILib.h"
#include <VictorSP.h>
//#include <AxisCamera.h>
#include <Constants.h>


class Lift
{
private:
	VictorSP lift;

public:
	Lift()
	{
		lift = new VictorSP()
	}

	void update()
	{

	}
};
