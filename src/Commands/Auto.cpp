// RobotBuilder Version: 1->5
//
// This file was generated by RobotBuilder-> It contains sections of
// code that are automatically generated and assigned by robotbuilder->
// These sections will be updated in the future when you export to
// C++ from RobotBuilder-> Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update-> Deleting the comments indicating the section will prevent
// it from being updated in the future->

#include "Auto.h"

#include "../Subsystems/Elevator.h"
#include "CloseClaw.h"
#include "DriveStraightDistance.h"
#include "DriveStraightTillTote.h"
#include "OpenClaw.h"
#include "SetElevatorSetpoint.h"
#include "TurnThroughAngle.h"

Auto::Auto() {
	GrabToteAndBin();
}

void Auto::GrabToteAndBin() {
	AddParallel(new OpenClaw());
	AddParallel(new SetElevatorSetpoint(Elevator::getBin));
	AddSequential(new DriveStraightTillTote());
	AddSequential(new SetElevatorSetpoint(Elevator::liftBin)); // bin
															   // acquired

	AddSequential(new DriveStraightTillTote());
	AddSequential(new SetElevatorSetpoint(Elevator::getTote));
	AddParallel(new CloseClaw()); // tote acquired


	AddSequential(new TurnThroughAngle(90));
	AddSequential(new DriveStraightDistance(3));

	AddParallel(new OpenClaw());
	AddSequential(new DriveStraightDistance(-1)); // tote + bin + robot
													// scored!
}

/** simply turns and enters the auto zone */
void Auto::ScoreRobot() {
	AddSequential(new TurnThroughAngle(90));
	AddSequential(new DriveStraightDistance(7));
}
