/*
 * CPoiAdditionTest.h
 *
 *  Created on: Jan 10, 2018
 *      Author: ANKIT
 */

#ifndef CPOIADDITIONTEST_H_
#define CPOIADDITIONTEST_H_

#include <cppunit/TestCaller.h>

#include <cppunit/TestSuite.h>

#include "../myCode/CRoute.h"
using namespace CppUnit;

class CPoiAdditionTest: public CppUnit::TestFixture{
private:
	CWaypoint* wp1;
	CWaypoint* wp2;
	CWaypoint* wp3;
	CPOI* poi1;
	CPOI* poi2;
	CPOI* poi3;
	CPoiDatabase* PoiDatabase;
	CWpDatabase* WpDatabase;
	CRoute* r;
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
		poi3 = new CPOI (TRADEFAIR,"DARMSTRADE","Trade fair in Darmstadt",24.88,22.31);

		WpDatabase = new CWpDatabase;
		WpDatabase->addWayPoint(*wp1);
		WpDatabase->addWayPoint(*wp2);
		WpDatabase->addWayPoint(*wp3);

		PoiDatabase = new CPoiDatabase;
		PoiDatabase->addPoi(*poi1);
		PoiDatabase->addPoi(* poi2);
		PoiDatabase->addPoi(* poi3);

		r = new CRoute;
		r->connectToWpDatabase(WpDatabase);
		r->connectToPoiDatabase(PoiDatabase);

		r1 = new CRoute;

	}

	void poiAddition_WithoutConnectingToDatabase(){
		r1->addPoi("HDA","Frankfurt");
		CPPUNIT_ASSERT_EQUAL(0,(int)r1->getRoute().size());
	}

	void poiAddition_WithoutWp(){
		r->addPoi("HDA","India");
		CPPUNIT_ASSERT_EQUAL(1,(int)r->getRoute().size());
	}

	void poiAddition_WithWp(){
		r->addPoi("HDA","Frankfurt");
		CPPUNIT_ASSERT_EQUAL(1,(int)r->getRoute().size());
	}

	void poiAddition_WithoutPoi(){
		r->addPoi("India","Hamburg");
		CPPUNIT_ASSERT_EQUAL(0,(int)r->getRoute().size());
	}

	void poiAddition_WpPoiWithSameName(){
		r->addPoi("DARMSTRADE","DARMSTRADE");
		CPPUNIT_ASSERT_EQUAL(1,(int)r->getRoute().size());
	}



	static CppUnit::TestSuite* suite_PoiAdditionTest() {
	CppUnit::TestSuite* suite = new CppUnit::TestSuite("Load Tests:PoiAddition Test");
	suite->addTest(new CppUnit::TestCaller<CPoiAdditionTest>
	("Add poi without connecting to db", &CPoiAdditionTest::poiAddition_WithoutConnectingToDatabase));
	suite->addTest(new CppUnit::TestCaller<CPoiAdditionTest>
	("Add poi without wp", &CPoiAdditionTest::poiAddition_WithoutWp));
	suite->addTest(new CppUnit::TestCaller<CPoiAdditionTest>
	("Add poi with wp", &CPoiAdditionTest::poiAddition_WithWp));
	suite->addTest(new CppUnit::TestCaller<CPoiAdditionTest>
	("Add poi without poi", &CPoiAdditionTest::poiAddition_WithoutPoi));
	suite->addTest(new CppUnit::TestCaller<CPoiAdditionTest>
	("Add poi with same name for Wp and Poi", &CPoiAdditionTest::poiAddition_WpPoiWithSameName));
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
	delete r;
	delete r1;
}



};





#endif /* CPOIADDITIONTEST_H_ */
