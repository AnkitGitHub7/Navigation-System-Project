/*
 * CJsaonPersistence.h
 *
 *  Created on: Dec 27, 2017
 *      Author: ANKIT
 */

#ifndef CJSAONPERSISTENCE_H_
#define CJSAONPERSISTENCE_H_


#include<stdlib.h>
#include <fstream>
#include <string>
#include <iostream>
#include "CPoiDatabase.h"
#include"CWpDatabase.h"
#include "CJsonScanner.h"
#include "CPersistanceStorage.h"
#include "CPersistanceComponent.h"
#include "CJsonScanner.h"
#include "CJsonToken.h"
#include <string.h>
#include <stdio.h>
using namespace APT;

enum states
{
	IDEAL,
	WAIT_DB_NAME,
	WAIT_ATTRIBUTE_NAME,
	WAIT_NEXT_ATTRIBUTE_NAME_OBJECT,
	WAIT_SEPERATOR_FOR_NAME,
	WAIT_DBSTART
};


class CJsaonPersistence:public CPersistanceStorage{
public:
	/*
	 * This method is for setting the media name for CJason file */
	void setMediaName(std::string name);
	/*
	 * This method will write data in Json media file*/
	bool writeData (const CWpDatabase & waypointDb,const CPoiDatabase & poiDb);
	/*
	 * This method will read data from Json media file*/
	bool readData(CWpDatabase & waypointDb,CPoiDatabase & poiDb,MergeMode mode);
	/**
	* To get the enum value from a string
	* @param string& str The string to be converted
	* @return t_poi
	*/
	t_poi funcPrintEnum(const std::string& str);


protected:
	std::string mWpPoiname;

public :
   CJsaonPersistence();
   virtual ~CJsaonPersistence();
};



#endif /* CJSAONPERSISTENCE_H_ */
