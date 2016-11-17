//to Test!!!!

/**
 * Rotates the robot on spot.
 * @param direction			right (1) or left (-1)
 * @param wheelDistance		distance of both wheels
 * @param wheelRadius		radius of a wheel
 * @param angle 			the angle of the rotation
*/
void rotateOnSpot(int direction, float wheelDistance, float wheelRadius, int angle)
{
	int wheelRotationAngle = angle * (int) ((wheelDistance / 2) / wheelRadius);

	RotateMotorEx(BOTH_DRIVE, SPEED, wheelRotationAngle, -direction*100, true, true);
}

/*
void rotateAroundWheel(int standingWheel, float wheelDistance, float wheelRadius, int angle)
{
	//todo
	//int wheelRotationAngle = angle * (wheeldistance / wheelRadius)
}

*/
