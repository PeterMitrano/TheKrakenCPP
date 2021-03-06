#include "Claw.h"
#include "../RobotMap.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

double Claw::PICKUP_DIST = -0.3;

Claw::Claw() :
		Subsystem("Claw") {
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	motor = RobotMap::clawMotor;
	leftClawLimit = RobotMap::clawLeftClawLimit;
	rightClawLimit = RobotMap::clawLightClawLimit;
	encoder = RobotMap::clawEncoder;
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
}

void Claw::InitDefaultCommand() {
}

void Claw::Open() {
	motor->Set(-1);
}

void Claw::Close() {
	motor->Set(1);
}

void Claw::Stop() {
	motor->Set(0);
}

bool Claw::IsOpen() {
	return encoder->GetDistance() < -0.3;
}

bool Claw::HitObject() {
	return leftClawLimit->Get() || rightClawLimit->Get();
}
