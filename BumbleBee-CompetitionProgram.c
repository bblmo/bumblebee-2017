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

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks
  // running between Autonomous and Driver controlled modes. You will need to
  // manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

	// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
	// used by the competition include file, for example, you might want
	// to display your team name on the LCD in this function.
	// bDisplayCompetitionStatusOnLcd = false;

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task autonomous()
{
	// Step 1: go forward 4 sec and stop
	motor[rightMotor] = 128;		  // Motor on port2 is run at full power forward
	motor[leftMotor]  = 128;		  // Motor on port3 is run at full power forward
	wait1Msec(4000);			        // Robot runs previous code for 4000 milliseconds before moving on
  motor[rightMotor] = 0; 				// Stop motor
	motor[leftMotor] = 0;					// Stop motor

}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
task usercontrol()
{
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.
    // ........................................................................
  while (true)
  {
    //Driving Motor Control
    motor[leftMotor] = vexRT[Ch3] / 2;
    motor[rightMotor] = vexRT[Ch2] / 2;

		// Raise, lower or stop the arm
		if(vexRT[Btn5U] == 1)       	//If button 5U is pressed...
		{
			motor[armMotor] = 40;    	//...raise the arm.
		}
		else if(vexRT[Btn5D] == 1)  	//Else, if button 5D is pressed...
		{
			motor[armMotor] = -40;   	//...lower the arm.
		}
		else                      		//Else (neither button is pressed)...
		{
			motor[armMotor] = 0;      	//...stop the arm.
		}

		// Open, close or stop the claw
		if(vexRT[Btn6U] == 1)       	//If Button 6U is pressed...
		{
			motor[clawMotor] = 40;  		//...open the gripper.
		}
		else if(vexRT[Btn6D] == 1)  	//Else, if button 6D is pressed...
		{
			motor[clawMotor] = -40; 		//...close the gripper.
		}
		else                      		//Else (neither button is pressed)...
		{
			motor[clawMotor] = 0;    		//...stop the gripper.
		}

		//open, Close Forklift
		if(vexRT[Btn8U] == 1)
    {
    	motor[forkliftMotor] = -40;  		//...Open Forklift.
	  }
    else if(vexRT[Btn8D] == 1)  	//Else, if button 8D is pressed...
    {
     	motor[forkliftMotor] = 40;  		//...Close Forklift  }
    }
     	else
    {
    	motor[forkliftMotor] = 0;    		//...stop the Forklift.
    }
    //Raise, Lower forklift
    if(vexRT[Btn8L] == 1)
    {
     	motor[forklift2Motor] = -40;  		//...lower Forklift.
	  }
    else if(vexRT[Btn8R] == 1)  	//Else, if button 8L is pressed...
    {
     	motor[forklift2Motor] = 40;  		//...raise Forklift.
    }
    else
    {
    	motor[forklift2Motor] = 0;    		//...stop the Forklift.
    }

  } // End of While

}// End of task user control
