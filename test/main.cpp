/*
 * main.cpp
 *
 *  Created on: Jan 10, 2018
 *      Author: ANKIT
 */
#include <cppunit/TestCase.h>
#include <cppunit/TestSuite.h>
#include <cppunit/ui/text/TestRunner.h>

#include "CConnectToPoiDatabaseTest.h"
#include "CConnectToWpDatabaseTest.h"
#include "CCopyConstructorTest.h"
#include "CCoutOpearatorOverload.h"
#include "CPlusEqualOperatorOverloadTest.h"
#include "CPlusOperatorOverloadTest.h"
#include "CPoiAdditionTest.h"
#include "CWpAdditionTest.h"

using namespace CppUnit;

int main (int argc, char* argv[]) {

TextUi::TestRunner runner;

runner.addTest(CConnectToPoiDatabaseTest::suite_ConnectToPoiDatabaseTest());
runner.addTest(CConnectToWpDatabaseTest::suite_ConnectToWpDatabaseTest());
runner.addTest(CCopyConstructorTest::suite_CopyConstructorTest());
runner.addTest(CPlusEqualOperatorOverloadTest::suite_PlusEqualOperatorOverloadTest());
runner.addTest(CPlusOperatorOverloadTest::suite_PlusOperatorOverloadTest());
runner.addTest(CPoiAdditionTest::suite_PoiAdditionTest());
runner.addTest(CPrintTest::suite_PrintTest());
runner.addTest(CWpAdditionTest::suite_WpAdditionTest());

runner.run();

return 0;

}








