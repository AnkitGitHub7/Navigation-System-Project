/*
 * CWpAdditionTest.h
 *
 *  Created on: Jan 10, 2018
 *      Author: ANKIT
 */

#ifndef CWPADDITIONTEST_H_
#define CWPADDITIONTEST_H_


#include <cppunit/TestCaller.h>

#include <cppunit/TestSuite.h>

#include "../myCode/CRoute.h"
using namespace CppUnit;

class CWpAdditionTest: public CppUnit::TestFixture{
private:
	CWaypoint* wp1;
	CWaypoint* wp2;

	CWpDatabase* WpDatabase;

	CRoute* r;

public:
	void setUp(){
		/*
		 * creating the wp for test scenario
		 * */

		wp1 = new CWaypoint ("Frankfurt",52.52,13.40);
		wp2 = new CWaypoint ("Hamburg",35.68,10.69);

		WpDatabase = new CWpDatabase;
		WpDatabase->addWayPoint(*wp1);
		WpDatabase->addWayPoint(*wp2);

		r = new CRoute;
		r->connectToWpDatabase(WpDatabase);

	}

	void WpAddition_WithoutWp(){
		r->addWaypoint("India");
		CPPUNIT_ASSERT_EQUAL(0,(int)r->getRoute().size());
	}

	void WpAddition_WithWp(){
		r->addWaypoint("Frankfurt");
		CPPUNIT_ASSERT_EQUAL(1,(int)r->getRoute().size());
	}

	static CppUnit::TestSuite* suite_WpAdditionTest() {
	CppUnit::TestSuite* suite = new CppUnit::TestSuite("Load Tests:WpAddition Test");
	suite->addTest(new CppUnit::TestCaller<CWpAdditionTest>
	("Add wp without existing wp", &CWpAdditionTest::WpAddition_WithoutWp));
	suite->addTest(new CppUnit::TestCaller<CWpAdditionTest>
	("Add wp with existing wp", &CWpAdditionTest::WpAddition_WithWp));
	return suite;
	}

void tearDown(){

	delete wp1;
	delete wp2;
	delete WpDatabase;
	delete r;

}



};



#endif /* CWPADDITIONTEST_H_ */
