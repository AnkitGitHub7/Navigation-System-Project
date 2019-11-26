/*
 * CPlusOperatorOverloadTest.h
 *
 *  Created on: Jan 10, 2018
 *      Author: ANKIT
 */

#ifndef CPLUSOPERATOROVERLOADTEST_H_
#define CPLUSOPERATOROVERLOADTEST_H_


#include <cppunit/TestCaller.h>

#include <cppunit/TestSuite.h>

#include "../myCode/CRoute.h"
using namespace CppUnit;

class CPlusOperatorOverloadTest: public CppUnit::TestFixture{
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
	CRoute* r2;
	CRoute* r3;
	CRoute* r4;

public:
	void setUp(){
		/*
		 * creating the wp and poi for test scenario
		 * */

		wp1 = new CWaypoint ("Frankfurt",52.52,13.40);
		wp2 = new CWaypoint ("Hamburg",35.68,10.69);


		poi1 = new CPOI (TOURISTIC,"EIFELTOWER","The tallest tower",10.45,20.65);
		poi2 = new CPOI (UNIVERSITY,"HDA","Best Technical University",11.12,22.32);

		WpDatabase = new CWpDatabase;
		WpDatabase->addWayPoint(*wp1);
		WpDatabase->addWayPoint(*wp2);

		PoiDatabase = new CPoiDatabase;
		PoiDatabase->addPoi(*poi1);
		PoiDatabase->addPoi(* poi2);

		r1 = new CRoute;
		r1->connectToWpDatabase(WpDatabase);
		r1->connectToPoiDatabase(PoiDatabase);

		r1->addWaypoint("Frankfurt");
		r1->addPoi("EIFELTOWER","Frankfurt");

		r2 = new CRoute;
		r2->connectToWpDatabase(WpDatabase);
		r2->connectToPoiDatabase(PoiDatabase);

		r2->addWaypoint("Hamburg");
		r2->addPoi("HDA","Hamburg");

		r3 = new CRoute;
		r3->connectToWpDatabase(WpDatabase);
		r3->connectToPoiDatabase(PoiDatabase);

		r4 = new CRoute;

	}


	/* Test for + operator overload */
		void plusOperatorOverloadTest(){
			*r3 = (*r1) + (*r2);
			CPPUNIT_ASSERT_EQUAL(4,(int)(r3->getRoute().size()));
		}

		/* Test for + operator overload with connection */
		void plusOperatorOverloadTestWithoutConnection(){
			*r3 = (*r1) + (*r4);
			CPPUNIT_ASSERT_EQUAL(0,(int)(r3->getRoute().size()));
		}


	static CppUnit::TestSuite* suite_PlusOperatorOverloadTest() {
	CppUnit::TestSuite* suite = new CppUnit::TestSuite("Load Tests:+OperatorOverloadTest");

	suite->addTest(new CppUnit::TestCaller<CPlusOperatorOverloadTest>
	("+ Operator Overload Test", &CPlusOperatorOverloadTest::plusOperatorOverloadTest));

	suite->addTest(new CppUnit::TestCaller<CPlusOperatorOverloadTest>
		("+ Operator Overload Test without connection", &CPlusOperatorOverloadTest::plusOperatorOverloadTestWithoutConnection));


	return suite;
	}

void tearDown(){

	delete wp1;
	delete wp2;
	delete poi1;
	delete poi2;
	delete PoiDatabase;
	delete WpDatabase;
	delete r1;
	delete r2;
	delete r3;
	delete r4;
}



};



#endif /* CPLUSOPERATOROVERLOADTEST_H_ */
