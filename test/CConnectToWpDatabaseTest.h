/*
 * CConnectToWpDatabaseTest.h
 *
 *  Created on: Jan 10, 2018
 *      Author: ANKIT
 */

#ifndef CCONNECTTOWPDATABASETEST_H_
#define CCONNECTTOWPDATABASETEST_H_


#include <cppunit/TestCaller.h>

#include <cppunit/TestSuite.h>

#include "../myCode/CRoute.h"
using namespace CppUnit;

class CConnectToWpDatabaseTest: public CppUnit::TestFixture{
private:
	CWaypoint* wp1;
	CWaypoint* wp2;
	CWaypoint* wp3;
	CWpDatabase* WpDatabase;
	CRoute* r1;
	CRoute* r2;

public:
	void setUp(){
		/*
		 * creating the wp for test scenario
		 * */

		wp1 = new CWaypoint ("Frankfurt",52.52,13.40);
		wp2 = new CWaypoint ("Hamburg",35.68,10.69);
		wp3 = new CWaypoint ("DARMSTRADE",36.23,21.88);

		WpDatabase = new CWpDatabase;
		WpDatabase->addWayPoint(*wp1);
		WpDatabase->addWayPoint(*wp2);
		WpDatabase->addWayPoint(*wp3);



		r1 = new CRoute;
		r1->connectToWpDatabase(WpDatabase);

		r1->addWaypoint("Frankfurt");
		r1->addWaypoint("Hamburg");
		r1->addWaypoint("DARMSTRADE");

		r2 = new CRoute;
		r2->connectToWpDatabase(NULL);

		r2->addWaypoint("Frankfurt");
		r2->addWaypoint("Hamburg");
		r2->addWaypoint("DARMSTRADE");

	}


	/* Test for Database Wp connected*/
		void wpDatabaseConnected(){
			CPPUNIT_ASSERT_EQUAL(3,(int)r1->getRoute().size());
		}


		/* Test for Database Wp not connected*/
		void wpDatabaseNotConnected(){
			CPPUNIT_ASSERT_EQUAL(0,(int)r2->getRoute().size());
		}




	static CppUnit::TestSuite* suite_ConnectToWpDatabaseTest() {
	CppUnit::TestSuite* suite = new CppUnit::TestSuite("Load Tests:ConnectToWpDatabaseTest");
	suite->addTest(new CppUnit::TestCaller<CConnectToWpDatabaseTest>
	("Wp Database connected", &CConnectToWpDatabaseTest::wpDatabaseConnected));
	suite->addTest(new CppUnit::TestCaller<CConnectToWpDatabaseTest>
	("Wp Database not connected", &CConnectToWpDatabaseTest::wpDatabaseNotConnected));
	return suite;
	}

void tearDown(){

	delete wp1;
	delete wp2;
	delete wp3;
	delete WpDatabase;
	delete r1;
	delete r2;

}



};


#endif /* CCONNECTTOWPDATABASETEST_H_ */
