#pragma config(Hubs,  S1, HTMotor,  HTServo,  none,     none)
#pragma config(Sensor, S2,     gyro,           sensorI2CHiTechnicGyro)
#pragma config(Sensor, S3,     accel,          sensorI2CHiTechnicAccel)
#pragma config(Sensor, S4,     ir,             sensorHiTechnicIRSeeker1200)
#pragma config(Motor,  mtr_S1_C1_1,     rightMotor,    tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     leftMotor,     tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Servo,  srvo_S1_C2_1,    servo1,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_6,    servo6,               tServoNone)
#pragma config(Sensor, S1,     HTIRS2,              sensorI2CCustom)
#include "hitechnic-irseeker-v2.h"
#include "hitechic-accelerometer.h"
#include "hitechnic-gyro.h"

task initializeRobot(){
	nMotorEncoder = 0;
	nMotorEncoder = 0;
}
HTIRS2setDSPMode(1,-DSP_1200);

task main(){
	initializeRobot;
	
	while(true){
		int IRSensorDir = IRHTIRS2readACDir(1);
		//Displays the Encoder Values + IR Sensor Direction on the NXT's screen
		nxtDisplayTextLine(1,"%d",nMotorEncoder[rightMotor]);
		nxtDisplayTextLine(2,"%d",nMotorEncoder[leftMotor]);
		nxtDisplayTextLine(3,"%d",IRSensorDir);
		//Reseting Motor Encoders	
		nMotorEncoder[rightMotor] = 0;
		nMotorEncoder[leftMotor] = 0;
		//First Robot Movement - Down the ramp
		while(nMotorEncoder[rightMotor]<(1440)){
			motor[rightMotor] = 100;
			motor[leftMotor] = 100;
		}
		//Reseting Motor Encoders
		nMotorEncoder[rightMotor] = 0;
		nMotorEncoder[leftMotor] = 0;
		//Seccon Robot Movement - Turing to face the field
		while(nMotorEncoder[rightMotor]<(1440*2)){
			motor[rightMotor] = 50;
			motor[leftMotor] = -50;
		}
		//Robot Third Movement - IRSensor fine adjustments
		while(SensorValue[IR1] != 5){
		IR1value = SensorValue[IR1];
		nxtDisplayCenteredTextLine(5,"%d",IR1value);
		motor[rightMotor] = 20;
		motor[rightMotor] = -20;
		}
		//Reseting Motor Encoders
		nMotorEncoder[rightMotor] = 0;
		nMotorEncoder[leftMotor] = 0;
		//Robot Fourth Movement - Movement towards central dispenser
		while(nMotorEncoder[rightMotor]<(1440*5)){
			motor[rightMotor] = 100;
			motor[leftMotor] = 100;
		}
		//Spin in place / placeholder
		motor[rightMotor] = 50;
		motor[leftMotor] = -50;
	}
}
