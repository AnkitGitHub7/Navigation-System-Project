/***************************************************************************
 *============= Copyright by Darmstadt University of Applied Sciences =======
 ****************************************************************************
 * Filename        : CWpDatabase.cpp
 * Author          :	ANKIT ANKIT
 * Description     :	Source file for implementation of CWaypoint class
 *
 *
 ****************************************************************************/

/* System Include Files */
#include <iostream>
using namespace std;

/* Own Include Files */
#include "CWpDatabase.h"

/*Method Implementations */
CWpDatabase::CWpDatabase() {

}
void CWpDatabase::addWayPoint(CWaypoint const & wp) {

	strMapWp.insert(pair<string, CWaypoint>(wp.getName(), wp));
}
CWaypoint* CWpDatabase::getPointerToWaypoint(std::string name){

	for (map<string, CWaypoint>::iterator ii = strMapWp.begin();
			ii != strMapWp.end(); ++ii) {
		if ((*ii).first == name) {
			return &((*ii).second);
		}
	}

	cout << "ERROR : Could not find waypoint in the pool" << endl;
	return (NULL);
}
void CWpDatabase::print() {

	map<string, CWaypoint>::iterator it;
	for (it = strMapWp.begin(); it != strMapWp.end(); it++) {
		it->second.print(MMSS);
	}

}
