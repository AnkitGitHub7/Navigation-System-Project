/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : CGPSSensor.cpp
* Author          :	ANKIT ANKIT
* Description     :	Source file for implementation of CGPSSensor class
*
*
****************************************************************************/

/*System Include Files */
#include <iostream>
using namespace std;

/*Own Include Files */
#include "CGPSSensor.h"

/*Method Implementations */
CGPSSensor :: CGPSSensor(){
}
CWaypoint CGPSSensor::getCurrentPosition(){

	cout << "Enter the latitude and longitude of current position :"
		 << endl;
	double lat_in, long_in;
	string name_in;
	cout << "GPS_POSITON" << endl;
	cout << "Enter the latitude : " <<endl;
	cin >> lat_in;
	cout << "Enter the longitude : " <<endl;
	cin >> long_in;
	/*The constructor is called with above defined values. */
	CWaypoint c3("default position", lat_in, long_in);
	return c3;

}
