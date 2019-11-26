/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : CNavigationSystem.cpp
* Author          :	ANKIT ANKIT
* Description     :	Source file for implementation of CNavigationSystem class
*
*
****************************************************************************/

/*System Include Files*/

#include <iostream>
using namespace std;

/*Own Include Files */
#include "CNavigationSystem.h"

/*Method Implementations */
CNavigationSystem :: CNavigationSystem(){

}
void CNavigationSystem :: enterRoute(){


}
void CNavigationSystem :: printRoute(){
	/* Printing all waypoints and poi present in route */
	m_route.print();
}
void CNavigationSystem :: printDistanceCurPosNextPoi(){
/*	CPOI cpoi1;
	double nextPosDistance;
	CWaypoint cw1;
	 Storing the current position
	cw1 = m_GPSSensor.getCurrentPosition();
	nextPosDistance = m_route.getDistanceNextPoi(cw1, cpoi1);
	 Checking for valid GPS input
	if (cw1.getName() == "INVALID_LOCATION"
			&& cpoi1.getName() != "Default Name")
	{
		cout << "Invalid input for GPS ...  Out of range !!!" << endl;
		cout << "Latitude must be between -90 to +90 " << "and " <<
				"Longitude must be between -180 to +180 .";
	}
	else
	{
		if ((int) nextPosDistance > 0 && nextPosDistance != ZERO_POI_COUNT)
		{
			cout << "Distance to next POI : " << nextPosDistance << " kms."
				 << endl;
			cpoi1.print();
		}
		Condition for no Poi in the route
		else if (nextPosDistance != ZERO_POI_COUNT)
		{
			cout << "Distance to next POI : " << (int) nextPosDistance << endl;
			cout << "You are at POI : " << cpoi1.getName() << endl;
		}
	}*/
}
void CNavigationSystem :: run(){

}
CNavigationSystem :: ~CNavigationSystem(){

}

