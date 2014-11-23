#pragma config(Hubs,  S1, HTMotor,  HTServo,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     gyro,           sensorI2CHiTechnicGyro)
#pragma config(Sensor, S3,     accel,          sensorI2CHiTechnicAccel)
#pragma config(Sensor, S4,     ir,             sensorHiTechnicIRSeeker1200)
#pragma config(Motor,  mtr_S1_C1_1,     rightMotor,    tmotorTetrix, PIDControl, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     leftMotor,     tmotorTetrix, PIDControl, reversed, encoder)
#pragma config(Servo,  srvo_S1_C2_1,    servo1,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_6,    servo6,               tServoNone)

#include "JoystickDriver.c"

task main()
{
	int threshold = 20;	

	while(true)
	{
		getJoystickSettings(joystick); //Gets the joystick object's variables

		if(abs(joystick.joy1_y1) > threshold && abs(joystick.joy1_x1) <= threshold) //Forward/Reverse Code for left stick
		{
			motor[motorD] = joystick.joy1_y1;
			motor[motorE] = joystick.joy1_y1;
		}	
		else if(abs(joystick.joy1_y1) > threshold && abs(joystick.joy1_x1) >= threshold) //In-motion turns using left stick
		{
			motor[motorD] = joystick.joy1_y1;
			motor[motorE] = joystick.joy1_x1;
		}	
		else if(joystick.joy1_x2 >= threshold) //Point turn in the right direction
		{
			motor[motorD] = -50;
			motor[motorE] = 50;
		}
		else if(joystick.joy1_x2 < threshold) //Point turn in the left direction
		{
			motor[motorD] = 50;
			motor[motorE] = -50;
		}
		else //No movement in motors
		{
			motor[motorD] = 0;
			motor[motorE] = 0;
		}
	}
}
