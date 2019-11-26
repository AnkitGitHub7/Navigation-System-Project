/***************************************************************************
 *============= Copyright by Darmstadt University of Applied Sciences =======
 ****************************************************************************
 * Filename        : CRoute.cpp
 * Author          :	ANKIT ANKIT
 * Description     :	Source file for implementation of CRoute class
 *
 *
 ****************************************************************************/

/*System Include Files */
#include <iostream>
#include<algorithm>
using namespace std;

/*Own Include Files */
#include "CRoute.h"

/*Method Implementations */
CRoute::CRoute() {

	m_pPoiDatabase = NULL;
	m_pWaypointDatabase = NULL;
	cntwp = 0;
	cntpoi = 0;

}
CRoute::CRoute(CRoute const & origin) {
	/* Copy normal attributes */

	m_pPoiDatabase = origin.m_pPoiDatabase;
	m_pWaypointDatabase = origin.m_pWaypointDatabase;
	cntwp = origin.cntwp;
	cntpoi = origin.cntpoi;

	/*Implementing deep copy*/
	list<CWaypoint*>::const_iterator i;
	for (i = origin.m_pListRoute.begin(); i != origin.m_pListRoute.end(); i++) {
		m_pListRoute.push_back(*i);
	}

}
CRoute::~CRoute() {

}
void CRoute::connectToPoiDatabase(CPoiDatabase* pPoiDB) {
	m_pPoiDatabase = pPoiDB;
}
void CRoute::connectToWpDatabase(CWpDatabase* pWpDB) {
	m_pWaypointDatabase = pWpDB;
}
void CRoute::addWaypoint(std::string name) {

	/* Check is done if m_pWaypointDatabase is having address or its NULL */
	if (m_pWaypointDatabase == NULL) {

		cout << "Error database is not connected " << endl;

	} else {

		/* Getting the address of corresponding POI and storing in
		 * the array m_pPoi */
		CWaypoint* adressWaypoint = m_pWaypointDatabase->getPointerToWaypoint(name);

		/* Check is done to verify if the address is not NULL */
		if (adressWaypoint != NULL) {
			/* Address is stored in list at the end*/
			m_pListRoute.push_back(adressWaypoint);
			/* Counter for Waypoint is incremented*/
			cntwp++;
		} else {
			cout << "ERROR : Could not find waypoint in the pool" << endl;
		}
	}
}
void CRoute::addPoi(string namePoi, string afterWp) {
	/* Check is done if PoiDatabase or m_pWaypointDatabase is having address or its NULL */
	if ((m_pPoiDatabase == NULL) || (m_pWaypointDatabase == NULL)) {
		cout << "Error database is not connected " << endl;
	}
	else{

		list<CWaypoint*>::reverse_iterator rit;

		/* Storing the address of WayPoint with name afterWp */
		CPOI* adressCpoi = m_pPoiDatabase->getPointerToPoi(namePoi);

		if(adressCpoi != NULL){
			/* Checking the list till the end*/
			for (rit = m_pListRoute.rbegin(); rit != m_pListRoute.rend(); ++rit)
			{

				if (adressCpoi != NULL)
				{
					m_pListRoute.insert(rit.base(), adressCpoi);
					cntpoi++;
					return;

				}

			}
			m_pListRoute.push_back(adressCpoi);
			cntwp++;
		}
		else{
			cout << "ERROR : POI not found " << endl;
		}


	}


}

void CRoute::operator +=(string name) {

	addWaypoint(name);
	addPoi(name,name);

}
CRoute CRoute::operator +(CRoute & cr) {

	CRoute res;
	list<CWaypoint*>::iterator i;
	if ((m_pPoiDatabase == cr.m_pPoiDatabase) &&
		(m_pWaypointDatabase == cr.m_pWaypointDatabase)) {

		for (i = m_pListRoute.begin(); i != m_pListRoute.end(); i++) {
			res.m_pListRoute.push_back(*i);
		}

		for (i = cr.m_pListRoute.begin(); i != cr.m_pListRoute.end(); i++) {
			res.m_pListRoute.push_back(*i);
		}

	} else {
		res.m_pListRoute.clear();
		cout << "Error in database connection for two CRoutes" << endl;
	}
	return res;
}

void CRoute::print() {
	cout << "Displaying the route" << endl;
	cout << "Our route has " << cntwp << " Waypoints and " << cntpoi
			<< " Points Of Interests" << endl;
	//Looping through all the waypoints and Poi and printing their values
	for (list<CWaypoint*>::iterator i = m_pListRoute.begin();
			i != m_pListRoute.end(); ++i) {

		/* This runs by calling print method of Cwaypoint as we didnt mention the type */
		//(*i)->print(MMSS);
		/* We are printing the cwaypoint object directly on console using cout.
		 * If we perform cout on *i , it will print the address. So we need to print
		 * the value at this address using ** calling on iterator i */

		//cout << (**i) << endl;
		/* Dynamic typecasting is needed to convert the cwaypoint into CPOI
		 * to call print method of CPOI */
		CPOI* poiTemp = dynamic_cast<CPOI*>(*i);

		if (poiTemp != NULL) {
			cout << *poiTemp << endl;
		} else {
			(*i)->print(MMSS);
			cout << endl;
		}
	}
}
const vector<const CWaypoint*> CRoute::getRoute(){

	vector<const CWaypoint*> v1;
	list<CWaypoint*>::iterator i;

	for (i = m_pListRoute.begin(); i != m_pListRoute.end(); i++) {
				v1.push_back(*i);
			}
	return v1;
}
