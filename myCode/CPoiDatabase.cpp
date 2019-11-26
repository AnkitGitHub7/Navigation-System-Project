/***************************************************************************
 *============= Copyright by Darmstadt University of Applied Sciences =======
 ****************************************************************************
 * Filename        : CPoiDatabase.cpp
 * Author          :	ANKIT ANKIT
 * Description     :	Source file for implementation of CPoiDatabase class
 *
 *
 ****************************************************************************/

/*System Include Files */
#include <iostream>
using namespace std;

/*Own Include Files */
#include "CPoiDatabase.h"

CPoiDatabase::CPoiDatabase() {

}
void CPoiDatabase::addPoi(CPOI const & poi) {
	strMapPoi.insert(pair<string, CPOI>(poi.getName(), poi));
}

CPOI* CPoiDatabase::getPointerToPoi(string name) {

	for (map<string, CPOI>::iterator ii = strMapPoi.begin();
			ii != strMapPoi.end(); ++ii) {
		if ((*ii).first == name) {
			return &((*ii).second);
		}
	}
	cout << "ERROR : Could not find poi in the pool" << endl;
	return (NULL);
}
void CPoiDatabase::print() {

	map<string, CPOI>::iterator it;
	for (it = strMapPoi.begin(); it != strMapPoi.end(); it++) {
		it->second.print(MMSS);
	}
}
