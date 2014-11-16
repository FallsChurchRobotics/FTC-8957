#pragma debuggerWindows("joystickSimple");
#include "JoystickDriver.c"

task main()
{






	int threshold = 10; //Set threshold for joystick values, must be above 10 to register

	while(true) //loops constantly
	{
		getJoystickSettings(joystick);
		if(abs(joystick.joy1_y2) > threshold)
		{
			motor[motorD] = joystick.joy1_y2;
		}
		else
		{
			motor[motorD] = 0;


		if(abs(joystick.joy1_y1) > threshold)
		 {
			motor[motorE] = joystick.joy1_y1;
		}
		else
		{
			motor[motorE] = 0;


}
