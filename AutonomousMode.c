#pragma config(Hubs,  S1, HTMotor,  HTServo,  none,     none)
#pragma config(Sensor, S1, , sensorI2CMuxController)
#pragma config(Sensor, S2, gyro, sensorI2CHiTechnicGyro)
#pragma config(Sensor, S3, light, sensorLightActive)
#pragma config(Sensor, S4, sonar, sensorSONAR)
#pragma config(Motor, mtr_S1_C1_1, rightMotor, tmotorTetrix, openLoop, encoder)
#pragma config(Motor, mtr_S1_C1_2, leftMotor, tmotorTetrix, openLoop, reversed, encoder)
#pragma config(Servo, srvo_S1_C2_1, servo1, tServoNone)
#pragma config(Servo, srvo_S1_C2_2, servo2, tServoNone)
#pragma config(Servo, srvo_S1_C2_3, servo3, tServoNone)
#pragma config(Servo, srvo_S1_C2_4, servo4, tServoNone)
#pragma config(Servo, srvo_S1_C2_5, servo5, tServoNone)
#pragma config(Servo, srvo_S1_C2_6, servo6, tServoNone)

task main(){
	while(true){
	nxtDisplayTextLine(1,"%d",SensorValue[rightEncoder];
	nxtDisplayTextLine(1,"%d",SensorValue[leftEncoder];
	}
	SensorValue[rightEncoder] = 0;
	SensorValue[leftEncoder] = 0;

	while(SensorValue[rightEncoder]<(1440*3)){
		motor[motorD] = 100;
		motor[motorE] = 100;
	}
	SensorValue[rightEncoder] = 0;
	SensorValue[leftEncoder] = 0;

	while(SensorValue[rightEncoder]<(1440*2)){
		motor[motorD] = 50;
		motor[motorE] = -50;
	}
	/*while(SensorValue[IR1] != 5){
		IR1value = SensorValue[IR1];
		nxtDisplayCenteredTextLine(5,"%d",IR1value);
		motor[motorD] = 20;
		motor[motorE] = -20;
	}*/
	SensorValue[rightEncoder] = 0;
	SensorValue[leftEncoder] = 0;
	while(SensorValue[rightEncoder]<(1440*5)){
	motor[motorD] = 100;
	motor[motorE] = 100;
	}
	motor[motorD] = 50;
	motor[motorE] = -50;
}
