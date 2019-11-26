/*
 * CJsonScanner.cpp
 *
 *  Created on: 10.12.2015
 *      Author: mnl
 */

#include <string>
#include "CJsonScanner.h"

using namespace std;

namespace APT {

CJsonScanner::CJsonScanner(std::istream& input) : jsonFlexLexer(&input) {
	token = 0;
}

CJsonScanner::~CJsonScanner() {
	if (token != 0) {
		delete token;
	}
}

CJsonToken* CJsonScanner::nextToken() {
	if (token != 0) {
		delete token;
		token = 0;
	}
	int scanResult = yylex();
	/* Try and catch block for raising the exception for illegal character */
	try{
		if (scanResult == -1) {
			string illegalChar(YYText());
			// Found illegal character, currently ignored.

			throw ILLEGAL_CHARACTER;
		}
	}catch(int exceperr){
		cout<<"Error !! Illegal character at line "<<scannedLine()<<endl;
		token=nextToken();
	}
	return token;
}

int CJsonScanner::scannedLine() {
	return yylineno;
}

} /* namespace APT */

int yyFlexLexer::yywrap() {
	return 1;
}

