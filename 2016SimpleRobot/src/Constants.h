/*
 * Constants.h
 *
 *  Created on: Jan 30, 2016
 *      Author: Bradley
 */

#ifndef SRC_CONSTANTS_H_
#define SRC_CONSTANTS_H_

#include <String>

//DIO
	//Encoders for the Drive System
	const int RIGHT_CHANNEL_A = 21; //extender board
	const int RIGHT_CHANNEL_B = 22; //extender board
	const int LEFT_CHANNEL_A = 23; //extender board
	const int LEFT_CHANNEL_B = 24; //extender board

	//limit switches
	const int HANDLER_LIMIT_UP = 2;
	const int HANDLER_LIMIT_DOWN = 1;
	const int BALLSWITCH = 0; //this is the BallSensor
	const int ARM_LIMIT_OUT = 3;
	const int ARM_LIMIT_IN = 4;
	const int LIFT_SENSOR = 5;


//PWM
	//Drive System motors
	const int LEFTA_MOTOR_ID = 0;
	const int LEFTB_MOTOR_ID = 1;
	const int RIGHTA_MOTOR_ID = 2;
	const int RIGHTB_MOTOR_ID = 3;
	const int LIFT_MOTOR = 6; //Talon
	const int ARM_POSITION_MOTOR = 4;
	const int SPIN_MOTOR = 5; //the motor the spins the grabber roller
	//Servo that may be on the lift
	const int SERVO_MOTOR_ID = 17;

//Relay
	const int BALL_HANDLER_MOTOR = 1; //relay
	const int HANDLER_POSITION = 0; //this is HandlerFlip




//Speed Limits
	const float LIFT_MOTOR_SPEED = 0.1f; //controls speed for LIFT_MOTOR




//joysticks
	const int LEFT_JOYSTICK_PORT = 0;
	const int RIGHT_JOYSTICK_PORT = 1;
	const int TEST_JOYSTICK_PORT = 2;




//buttons to make the Lift go up and down
	const int LIFT_BUTTON_UP = 3;
	const int LIFT_BUTTON_DOWN = 2;



	const bool IFLIFT = true;






//buttons for Handler
	//controls the direction of the Handler's belts
		const int HANDLER_BALL_IN = 4;
		const int HANDLER_BALL_OUT = 5;


	//buttons for controlling the Handler's position
		const int HANDLER_UP_BUTTON = 11;
		const int HANDLER_IN_BUTTON = 4;
		const int HANDLER_DOWN_BUTTON = 10;
		const int HANDLER_GRAB = 2; //puts the handler in grab mode
		const int HANDLER_SHOOT =3; //fires the ball
	//Buttons for moving Arm in and out
		const int ARM_OUT_BUTTON = 7;
		const int ARM_IN_BUTTON = 6;












const int TEST_MODE_BUTTON = 9;

const bool PRESSED = false;
const bool NOT_PRESSED = true;

const std::string BallHandlerStateDescriptions[] = {"Up & Off", "Raise & Off", "Lower & Off", "Down & Off", "Down & In", "Down & Out"};
const std::string HandlerArmStateDescriptions[] = {"Folding In", "Folding Out", "In", "Out"};


#endif /* SRC_CONSTANTS_H_ */
