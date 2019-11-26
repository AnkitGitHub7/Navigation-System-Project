/*
 * CPlusEqualOperatorOverloadTest.h
 *
 *  Created on: Jan 10, 2018
 *      Author: ANKIT
 */

#ifndef CPLUSEQUALOPERATOROVERLOADTEST_H_
#define CPLUSEQUALOPERATOROVERLOADTEST_H_


#include <cppunit/TestCaller.h>

#include <cppunit/TestSuite.h>

#include "../myCode/CRoute.h"
using namespace CppUnit;

class CPlusEqualOperatorOverloadTest: public CppUnit::TestFixture{
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
		r1->connectToWpDatabase(WpDatabase);
		r1->connectToPoiDatabase(PoiDatabase);

	}

	void CPlusEqualTestOperator(){
		*r += "Frankfurt";
		*r += "Hamburg";
		*r += "EIFELTOWER";
		*r += "HDA";

		CPPUNIT_ASSERT_EQUAL(4,(int)r->getRoute().size());

	}

	void CPlusEqualTestOperatorWithWpOrPoi(){
		*r1 += "China";

		CPPUNIT_ASSERT_EQUAL(0,(int)r1->getRoute().size());

	}

	static CppUnit::TestSuite* suite_PlusEqualOperatorOverloadTest() {
	CppUnit::TestSuite* suite = new CppUnit::TestSuite("Load Tests: += operator OverloadTest");
	suite->addTest(new CppUnit::TestCaller<CPlusEqualOperatorOverloadTest>
	("Test for += operator overload", &CPlusEqualOperatorOverloadTest::CPlusEqualTestOperator));
	suite->addTest(new CppUnit::TestCaller<CPlusEqualOperatorOverloadTest>
	("Test for += operator overload without Poi or wp", &CPlusEqualOperatorOverloadTest::CPlusEqualTestOperatorWithWpOrPoi));
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






#endif /* CPLUSEQUALOPERATOROVERLOADTEST_H_ */
