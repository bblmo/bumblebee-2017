#pragma config(Motor,  port2,           rightMotor,        tmotorNormal, openLoop)
#pragma config(Motor,  port3,           leftMotor,  		   tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port6,           armMotor,    			 tmotorNormal, openLoop)
#pragma config(Motor,  port7,           clawMotor,    		 tmotorNormal, openLoop)
#pragma config(Motor,  port8,           forkliftMotor,     tmotorNormal, openLoop)
#pragma config(Motor,  port9,           forklift2Motor,    tmotorNormal, openLoop)
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// This code is for the VEX cortex platform
#pragma platform(VEX2)


task main()
{

	// Step 1: go forward 2.500 sec and stop
	motor[rightMotor] = 128;		  // Motor on port2 is run at full power forward
	motor[leftMotor]  = 128;		  // Motor on port3 is run at full power forward
	wait1Msec(2300);			        // Robot runs previous code for 4000 milliseconds before moving on
  motor[rightMotor] = 0; 				// Stop motor
	motor[leftMotor] = 0;					// Stop motor

	//step 2:wait for 200
	wait1Msec(200);

	// Step 2: open claw for 500
	motor[clawMotor] = 128;
	wait1Msec(500);
	motor[clawMotor] = 0;


}
