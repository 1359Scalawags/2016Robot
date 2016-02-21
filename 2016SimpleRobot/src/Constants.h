/*
 * Constants.h
 *
 *  Created on: Jan 30, 2016
 *      Author: Bradley
 */

#ifndef SRC_CONSTANTS_H_
#define SRC_CONSTANTS_H_

//constants used in more then one file can be found here

//Drive System motors
	const int LEFTA_MOTOR_ID = 0;
	const int LEFTB_MOTOR_ID = 1;
	const int RIGHTA_MOTOR_ID = 2;
	const int RIGHTB_MOTOR_ID = 3;

//Encoders for the Drive System
	const int RIGHT_CHANNEL_A = 21; //extender board
	const int RIGHT_CHANNEL_B = 22; //extender board
	const int LEFT_CHANNEL_A = 23; //extender board
	const int LEFT_CHANNEL_B = 24; //extender board

//joysticks
	const int LEFT_JOYSTICK_PORT = 0;
	const int RIGHT_JOYSTICK_PORT = 1;
	const int TEST_JOYSTICK_PORT = 2;


//Motors for BallHandler
	const int BALL_HANDLER_MOTOR = 1; //relay

//Motor for the lift
	const int LIFT_MOTOR = 6; //Talon
	const float LIFT_MOTOR_SPEED = 0.1f; //controls speed for LIFT_MOTOR


//buttons to make the Lift go up and down
	const int LIFT_BUTTON_UP = 3;
	const int LIFT_BUTTON_DOWN = 2;

//Servo that may be on the lift
	const int SERVO_MOTOR_ID = 17;

	const bool IFLIFT = true;

	const int LIFT_SENSOR = 5;


//constants for Handler

//buttons for Handler
	//controls the direction of the Handler's belts
		const int HANDLER_BALL_IN = 4;
		const int HANDLER_BALL_OUT = 5;
		const int HANDLER_ON_OFF = 1;

	//buttons for controlling the Handler's position
		const int HANDLER_UP_BUTTON = 3;
		const int HANDLER_IN_BUTTON = 4;
		const int HANDLER_DOWN_BUTTON = 2;
		const int HANDLER_GRAB = 2; //puts the handler in grab mode
		const int HANDLER_SHOOT =3; //fires the ball

	//limit switches
		const int HANDLER_LIMIT_UP = 2;
		const int HANDLER_LIMIT_DOWN = 1;
		const int BALLSWITCH = 0; //this is the BallSensor


	//motors for the Handler
		const int HANDLER_POSITION = 0; //this is HandlerFlip
		const int ARM_POSITION = 4;

//constants for Arm

	//limit switches
		const int ARM_LIMIT_OUT = 3;
		const int ARM_LIMIT_IN = 4;

	//Motors for the Arm
		const int SPIN_MOTOR = 5; //the motor the spins the grabber roller

	//Buttons for moving Arm in and out
		const int ARM_OUT_BUTTON = 4;
		const int ARM_IN_BUTTON = 5;

const int TEST_MODE_BUTTON = 9;

const bool PRESSED = true;
const bool NOT_PRESSED = false;


#endif /* SRC_CONSTANTS_H_ */
