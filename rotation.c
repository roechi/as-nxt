//to Test!!!!

/**
 * Rotiert den Roboter auf der Stelle (Drehung beider Räder) um den 
 * gewuenschten Winkel.
 * (siehe: AS-ueb3(Mindstorms-Block).pdf S.7)
 * @param direction			Links oder Rechts
 * @param wheelDistance		Radabstand
 * @param wheelRadius		Radius der Räder
 * @param angle 			Der gewünschte Winkel um den sich der 
 *							Roboter drehen soll.
*/
void rotateOnSpot(int direction, float wheelDistance, float wheelRadius, int angle)
{
	int wheeRotationAngle = angle * (int) ((wheelDistance / 2) / wheelRadius);

	RotateMotorEx(BOTH_DRIVE, SPEED, wheeRotationAngle, -direction*100, true, true);
}

/*
void rotateAroundWheel(int standingWheel, float wheelDistance, float wheelRadius, int angle)
{
	//todo
	//int wheelRotationAngle = angle * (wheeldistance / wheelRadius)
}

*/
