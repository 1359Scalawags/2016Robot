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
	const int LEFTA_MOTOR_ID = 1;
	const int RIGHTA_MOTOR_ID = 3;
	const int LEFTB_MOTOR_ID = 2;
	const int RIGHTB_MOTOR_ID = 4;

//Encoders for the Drive System
	const int RIGHT_CHANNEL_A = 5;
	const int RIGHT_CHANNEL_B = 6;
	const int LEFT_CHANNEL_A = 7;
	const int LEFT_CHANNEL_B = 8;

//joysticks
	const int LEFT_JOYSTICK_PORT = 7;
	const int RIGHT_JOYSTICK_PORT = 8;


	//const int TEST_MOTOR_ID_1 = 9;
	//const int TEST_MOTOR_ID_2 = 0;


//Motors for BallHandler
	const int BALL_HANDLER_MOTOR = 5; //relay

//Motor for the lift
	const int LIFT_MOTOR = 6; //Talon


//buttons to make the Lift go up and down
	const int LIFT_BUTTON_UP = 3;
	const int LIFT_BUTTON_DOWN = 2;

//Servo that may be on the lift
	const int SERVO_MOTOR_ID = 17;

	const bool IFLIFT = true;


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
		const int ARM_POSITION = 1;

//constants for Arm

	//limit switches
		const int ARM_LIMIT_OUT = 18;
		const int ARM_LIMIT_IN = 19;

	//Motors for the Arm
		const int SPIN_MOTOR = 35; //the motor the spins the grabber roller

	//Buttons for moving Arm in and out
		const int ARM_OUT_BUTTON = 4;
		const int ARM_IN_BUTTON = 5;







#endif /* SRC_CONSTANTS_H_ */
