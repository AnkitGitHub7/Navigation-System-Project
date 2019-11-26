/*
 * CPrintTest.h
 *
 *  Created on: Jan 10, 2018
 *      Author: ANKIT
 */

#ifndef CCOUTOPEARATOROVERLOAD_H_
#define CCOUTOPEARATOROVERLOAD_H_

#include <cppunit/TestCaller.h>

#include <cppunit/TestSuite.h>

#include "../myCode/CRoute.h"
using namespace CppUnit;

class CPrintTest: public CppUnit::TestFixture{
private:
	CWaypoint* wp1;
	CWaypoint* wp2;
	CWaypoint* wp3;
	CPOI* poi1;
	CPOI* poi2;
	CPOI* poi3;
	CPoiDatabase* PoiDatabase;
	CWpDatabase* WpDatabase;
	CRoute* r1;

public:
	void setUp(){
		/*
		 * creating the wp and poi for test scenario
		 * */

		wp1 = new CWaypoint ("Frankfurt",52.52,13.40);
		wp2 = new CWaypoint ("Hamburg",35.68,10.69);
		wp3 = new CWaypoint ("DARMSTRADE",36.23,21.88);


		poi1 = new CPOI (TOURISTIC,"EIFELTOWER","The tallest tower",10.45,20.65);
		poi2 = new CPOI (UNIVERSITY,"HDA","Best Technical University",11.12,22.32);
		poi3 = new CPOI (TRADEFAIR,"JOBFAIR","Trade fair in Darmstadt",24.88,22.31);

		WpDatabase = new CWpDatabase;
		WpDatabase->addWayPoint(*wp1);
		WpDatabase->addWayPoint(*wp2);
		WpDatabase->addWayPoint(*wp3);

		PoiDatabase = new CPoiDatabase;
		PoiDatabase->addPoi(*poi1);
		PoiDatabase->addPoi(* poi2);
		PoiDatabase->addPoi(* poi3);

		r1 = new CRoute;
		r1->connectToWpDatabase(WpDatabase);
		r1->connectToPoiDatabase(PoiDatabase);

		r1->addWaypoint("Frankfurt");
		r1->addWaypoint("Hamburg");
		r1->addWaypoint("DARMSTRADE");
		r1->addPoi("EIFELTOWER","Frankfurt");
		r1->addPoi("HDA","Hamburg");
		r1->addPoi("JOBFAIR","DARMSTRADE");

	}


	/* Test for Database Poi connected*/
		void printTest(){
			r1->print();
			//std::cout << (*r1) ;
		}

	static CppUnit::TestSuite* suite_PrintTest() {
	CppUnit::TestSuite* suite = new CppUnit::TestSuite("Load Tests:Print CRoute Test");
	suite->addTest(new CppUnit::TestCaller<CPrintTest>
	("Print CRoute Test", &CPrintTest::printTest));
	return suite;
	}

void tearDown(){

	delete wp1;
	delete wp2;
	delete wp3;
	delete poi1;
	delete poi2;
	delete poi3;
	delete PoiDatabase;
	delete WpDatabase;
	delete r1;

}



};



#endif /* CCOUTOPEARATOROVERLOAD_H_ */
