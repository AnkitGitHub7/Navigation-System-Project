/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : main.cpp
* Author          :	ANKIT ANKIT
* Description     :	Source file for implementation of main
*
*
****************************************************************************/
#include <iostream>
#include <stdlib.h>

#include "CNavigationSystem.h"
#include "CJsaonPersistence.h"
#include "CDatabaseTemplate.h"
using namespace std;

int main (void)
{
#if 0
	/*Test case for four different object creation from class Waypoint */
	CWaypoint amsterdam("amsterdam",52.37,4.89);
	cout << "Printing waypoint for amsterdam : " << endl;
	amsterdam.print(DEGREE);
	CWaypoint darmstadt("darmstadt",49.87,8.64);
	cout << "Printing waypoint for darmstadt : " << endl;
	darmstadt.print(DEGREE);
	CWaypoint berlin("berlin",52.52,13.40);
	cout << "Printing waypoint for berlin : " << endl;
	berlin.print(MMSS);
	CWaypoint tokio("tokio",35.65,139.83);
	cout << "Printing waypoint for tokio : " << endl;
	tokio.print(MMSS);
	cout << endl;
	cout << " ================" << endl;
	cout << endl;

	/*Test case for class object without parameter */
	CWaypoint newWaypoint;
	cout << "Printing waypoint for newWaypoint object : " << endl;
	newWaypoint.print(DEGREE);
	cout << endl;
	cout << " ================" << endl;
	cout << endl;

	/*Test case for print function for input as macros i.e
	 * DEGREE (value 1) and MMSS (value 2)*/
	cout << "Printing waypoint for berlin : " << endl;
	berlin.print(DEGREE);
	berlin.print(MMSS);
	cout << endl;
	cout << " ================" << endl;
	cout << endl;

	/*Test case for checking functionality of getAllDataByReference function */
	cout << "Name returned by Berlin Object : " << berlin.getName() << endl;
	cout << "Latitude returned by Berlin Object : " << berlin.getLatitude()
		 << endl;;
	cout << "Longitude returned by Berlin Object : " << berlin.getLongitude()
		 << endl;
	cout << endl;
	cout << " ================" << endl;
	cout << endl;

	/* Test case for checking the functionality of getName(),
	 * getLatitude() and getLongitude() for berlin object */
	string name;
	double longitude,latitude;
	berlin.getAllDataByReference(name,latitude,longitude);
	cout << endl;
	cout << " ================" << endl;
	cout << endl;

	/*Test case for printing the distance between two waypoints */
	cout << "The distance between amsterdam and berlin : " <<
			amsterdam.calculateDistance(berlin) << " kms" << endl;

	cout << "The distance between berlin and tokio : " <<
			berlin.calculateDistance(tokio) << " kms" << endl;
	cout << endl;
	cout << " ================" << endl;
	cout << endl;

	/* Final Test for Navigation System*/
	CNavigationSystem Cnav;
	Cnav.run();
	cout << endl;
	cout << " ================" << endl;
	cout << endl;

#endif


	// Test cases for APT Task2 :
	CPoiDatabase m_PoiDatabase;
	CPOI tower(TOURISTIC,"EIFELTOWER","The tallest tower",10.45,20.65);
	CPOI uni(UNIVERSITY,"HDA","Best Technical University",11.12,22.32);
	CPOI far(TRADEFAIR,"DARMSTRADE","Trade fair in Darmstadt",24.88,22.31);
	CPOI restaurant(RESTAURANT,"LREPNB","Italian restaurant",55.56,65.89);
	CPOI hotel(RESTAURANT,"MOTEL","Business german hotel",37.11,78.99);
	CPOI towerpisa(TOURISTIC,"PISATOWER","Leaning Tower of Pisa",55.11,45.69);

	m_PoiDatabase.addPoi(tower);
	m_PoiDatabase.addPoi(uni);
	m_PoiDatabase.addPoi(far);
	m_PoiDatabase.addPoi(restaurant);
	m_PoiDatabase.addPoi(hotel);

	CWpDatabase m_WpDatabase;
	CWaypoint Frankfurt("Frankfurt",52.52,13.40);
	CWaypoint Hamburg("Hamburg",35.68,10.69);
	CWaypoint Heidelberg("Heidelberg",47.45,23.11);
	CWaypoint Darmfair("DARMSTRADE",36.23,21.88);
	CWaypoint Paderborn("Paderborn",77.77,10.22);
	CWaypoint Pisa("Pisa",88.67,32.51);

	m_WpDatabase.addWayPoint(Frankfurt);
	m_WpDatabase.addWayPoint(Hamburg);
	m_WpDatabase.addWayPoint(Heidelberg);
	m_WpDatabase.addWayPoint(Darmfair);
	m_WpDatabase.addWayPoint(Paderborn);


#if 1
	/* Template testcase for APT TASK 3 */

	CDatabaseTemplate<string,CPOI> ctemplatepoi1;
	ctemplatepoi1.addWayPointOrPoi(tower);
	ctemplatepoi1.addWayPointOrPoi(uni);
	ctemplatepoi1.addWayPointOrPoi(far);
	cout << "Printing the CPOI database using template" << endl;
	ctemplatepoi1.print();
	ctemplatepoi1.addWayPointOrPoi(tower);

	CDatabaseTemplate<string,CWaypoint> ctemplatecw1;
	ctemplatecw1.addWayPointOrPoi(Frankfurt);
	ctemplatecw1.addWayPointOrPoi(Hamburg);
	ctemplatecw1.addWayPointOrPoi(Heidelberg);
	cout << "Printing the WayPoint database using template" << endl;
	ctemplatecw1.print();
	ctemplatecw1.getPointerToWaypointOrPOi("Hamburg");
	ctemplatecw1.getPointerToWaypointOrPOi("India");

	CDatabaseTemplate<string,CWaypoint> ctemplatecw3;
	cout << "Printing the empty database using template" << endl;
	ctemplatecw3.print();
#endif

	CRoute m_route;
	m_route.connectToPoiDatabase(&m_PoiDatabase);
	m_route.connectToWpDatabase(&m_WpDatabase);
	m_route.addWaypoint("Frankfurt");
	m_route.addWaypoint("Hamburg");
	m_route.addWaypoint("Heidelberg");

	m_route.addPoi("EIFELTOWER","Frankfurt");
	m_route.addPoi("HDA","Heidelberg");
	//m_route.print();

#if 0
	CPersistanceComponent testing;
	testing.setMediaName("MediaFile");
	//testing.writeData(m_WpDatabase,m_PoiDatabase);
	testing.readData(m_WpDatabase,m_PoiDatabase,testing.MERGE);

	m_route.print();
#endif



#if 0
	/*TestCase for merge or replace database*/
	cout << "printing the waypoint database : " << endl;
	m_WpDatabase.print();
	cout << "printing the poi database : " << endl;
	m_PoiDatabase.print();
#endif

#if 0
	/* Test case for += operator overloading for CRoute */
	m_route+=("DARMSTRADE");
#endif

#if 0
	/* Test case for + operator overloading for CRoute */
	CRoute cr1,cr2,resRoute;

	cr1.connectToPoiDatabase(&m_PoiDatabase);
	cr1.connectToWpDatabase(&m_WpDatabase);

	cr2.connectToPoiDatabase(&m_PoiDatabase);
	cr2.connectToWpDatabase(&m_WpDatabase);

	cr1.addWaypoint("DARMSTRADE");
	cr1.addPoi("LREPNB","DARMSTRADE");
	cr2.addWaypoint("Paderborn");
	cr2.addPoi("MOTEL","Paderborn");

	resRoute = cr1 + cr2;
	cout << "printing route after adding two routes " << endl;
	resRoute.print();
#endif


#if 0
	/* Test case for << operator overloading for CWaypoint and CPOI */
	cout << "printing the cwaypoint and cpoi using << opeartor overloading"<< endl;
	cout << Darmfair << endl;
	cout << tower << endl;

#endif


#if 0
	// Testing for APT Task3
	CJsaonPersistence test;
	test.setMediaName("media name");
//	test.writeData(m_WpDatabase,m_PoiDatabase);
	test.readData(m_WpDatabase,m_PoiDatabase,test.REPLACE);
#endif


#if 0
	/*TestCase for merge or replace database*/
	m_PoiDatabase.addPoi(towerpisa);
	m_WpDatabase.addWayPoint(Pisa);

	test.readData(m_WpDatabase,m_PoiDatabase,test.MERGE);

	cout << "printing the waypoint database : " << endl;
	m_WpDatabase.print();
	cout << "printing the poi database : " << endl;
	m_PoiDatabase.print();
#endif



	return 0;
}

