// RobotBuilder Version: 1.5
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "CloseClaw.h"

CloseClaw::CloseClaw() {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::claw);
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

// Called just before this Command runs the first time
void CloseClaw::Initialize() {
	SetTimeout(1);
}

// Called repeatedly when this Command is scheduled to run
void CloseClaw::Execute() {
	Robot::claw->Close();
}

/** If the contact sensor fails for some reason, the command will still time out after 1 second*/
bool CloseClaw::IsFinished() {
	return Robot::claw->HitObject() || IsTimedOut();
}

// Called once after isFinished returns true
void CloseClaw::End() {
	//don't stop in simulation, because that would lose all grip in the arms
	//We will be fixing this for next year, I promise!
#ifdef REAL
	Robot::claw->Stop();
#endif
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CloseClaw::Interrupted() {

}
