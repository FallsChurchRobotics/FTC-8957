task main()
{






	int threshold = 10; //Set threshold for joystick values, must be above 10 to register

	while(1==1) //loops constantly
	{
		getJoystickSettings(joystick);
		if(abs(joystick.joy1_y2) > threshold)
		{
			motor[rightMotor] = joystick.joy1_y2;
		}
		else
		{
			motor[rightMotor] = 0;


		if(abs(joystick.joy1_y1) > threshold)
		{
			motor[leftMotor] = joystick.joy1_y1;
		}
		else
		{
			motor[leftMotor] = 0;


}
