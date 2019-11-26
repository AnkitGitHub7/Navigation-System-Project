/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : CJsaonPersistence.cpp
* Author          :	ANKIT ANKIT
* Description     :	Source file for implementation of CJsaonPersistence  class
*
*
****************************************************************************/

/*System Include Files*/

#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <math.h>
#include <typeinfo>

using namespace std;


/*Own Include Files */
#include "CJsaonPersistence.h"

/*Method Implementations */
CJsaonPersistence :: CJsaonPersistence(){

}
bool CJsaonPersistence :: writeData (const CWpDatabase& waypointDb,
		const CPoiDatabase& poiDb){

	string name, desc;
	double lat, lon;
	t_poi type;
	string enumStr;

	/* Writing Waypoints in the file */
	ofstream file3;
	file3.open("JsonMediaFile.Json");
	if (file3.fail()) {
		cerr << "Error opening Json media file" << endl;
		return false;
	}
	file3 << "{" << endl;
	file3 << "  \"waypoints\":  [" << endl;

	for (map<string, CWaypoint>::const_iterator ii =
			waypointDb.strMapWp.begin(); ii != waypointDb.strMapWp.end();
			++ii) {
		file3 << "    {" << endl;
		file3 << "      \"name\": " << "\""<<(*ii).first << "\"" << "," << endl
			  << "      \"latitude\": " << (*ii).second.getLatitude() << ","<< endl
			  << "      \"longitude\": "<<  (*ii).second.getLongitude() << endl;
		file3 << "    }";
		if(ii == --(waypointDb.strMapWp.end()))
			file3 << ""<< endl;
		else
			file3 << "," << endl;

	}
	file3 << "  ]," << endl;


	file3 << "  \"pois\":  [" << "\n";
	for (map<string, CPOI>::const_iterator jj = poiDb.strMapPoi.begin();
			jj != poiDb.strMapPoi.end(); ++jj) {
		(*jj).second.getAllDataByReference(name, lat, lon, type, desc);

		switch (type) {
		case 0:
			enumStr = "RESTAURANT";
			break;
		case 1:
			enumStr = "TOURISTIC";
			break;
		case 2:
			enumStr = "TRADEFAIR";
			break;
		case 3:
			enumStr = "UNIVERSITY";
			break;
		default:
			break;
		}
		file3 << "    {"<<endl;

		file3 << "      \"name\": " << "\""<<name << "\"" << "," << endl
			  << "      \"latitude\": " << lat << "," << endl
			  << "      \"longitude\": "<<  lon << "," << endl
			  << "      \"type\": "<< "\""<<  enumStr << "\""<< ","<< endl
		      << "      \"description\":\""<<  desc <<"\""<< endl;
		file3 << "    }";
		if(jj == --(poiDb.strMapPoi.end()))
			file3 << ""<< endl;
		else
			file3 << "," << endl;

	}
	file3 << "  ]"<< endl;
	file3 << "}";
	file3.close();


	return true;

}

void CJsaonPersistence::setMediaName(std::string name)
{
	mWpPoiname=name+"-wppoi.json";

}

CJsaonPersistence :: ~CJsaonPersistence(){

}
t_poi CJsaonPersistence::funcPrintEnum(const std::string& str) {
	if (str == "RESTAURANT")
		return RESTAURANT;
	else if (str == "TOURISTIC")
		return TOURISTIC;
	else if (str == "TRADEFAIR")
		return TRADEFAIR;
	else if (str == "UNIVERSITY")
		return UNIVERSITY;
	else
		return RESTAURANT;
}
bool CJsaonPersistence :: readData(CWpDatabase& waypointDb, CPoiDatabase& poiDb,
		MergeMode mode){

	string WPname;
	double WpLat;
	double WpLong;

	int WpAttrCount = 0;
	int PoiAttrCount = 0;

	bool Dtbse_Wypt_Detection = false;
	bool Dtbse_Poi_Detection = false;

	//temp CWaypoint attributes
	std::map <string, CWaypoint> WpDbTempMap;
	std::map <string, CPOI> PoiDbTempMap;
	std::map <string, CPOI>::iterator poiIterator;

	string poiName,poiDescr,poiType;
	double poiLat,poiLong;
	//t_poi enumtype;

	states curr_state = IDEAL;
	ifstream file4;
	file4.open("JsonMediaFile.Json");
	string nameOfDatabase,attributeName,attributeNameValue;
	double attributeNumValue;
	CJsonScanner ScanObject(file4);
	CJsonNumberToken* token_num;
	CJsonStringToken* token_str;
	CJsonToken* tokenObj ;

	/*Clearing the database when mode is replace while reading a file*/
	if (mode == REPLACE) {
		waypointDb.strMapWp.clear();
		poiDb.strMapPoi.clear();
	}

	while((tokenObj =  ScanObject.nextToken()) != NULL){
	switch(curr_state){

	case IDEAL:
		if(tokenObj->getType() == CJsonToken::BEGIN_OBJECT){
			curr_state = WAIT_DB_NAME;
		}
		else{
			cout << "Error ! Incorrect token read at line " << ScanObject.scannedLine() << endl;
			curr_state = WAIT_DB_NAME;
		}
		break;


	case WAIT_ATTRIBUTE_NAME:
		if(tokenObj->getType() == CJsonToken::STRING)
		{
			token_str = (CJsonStringToken*)tokenObj;
			attributeName = token_str->getValue();
			if((strcmp(attributeName.c_str(),"longitude") == 0)||
			(strcmp(attributeName.c_str(),"latitude") == 0) ||
			(strcmp(attributeName.c_str(),"description") == 0) ||
			(strcmp(attributeName.c_str(),"type") == 0) ||
			(strcmp(attributeName.c_str(),"name") == 0)){

				cout << attributeName << endl;
				curr_state = WAIT_SEPERATOR_FOR_NAME;

			}
			else{
				cout << "Error!! Invalid attribute name " << endl;
				WpAttrCount=0;
				PoiAttrCount=0;
				curr_state = WAIT_DBSTART;

			}
		}
		else if(tokenObj->getType() == CJsonToken::BEGIN_OBJECT)
		{
			curr_state = WAIT_ATTRIBUTE_NAME;
		}
		break;

	case WAIT_SEPERATOR_FOR_NAME:
	if(tokenObj->getType() == CJsonToken::NAME_SEPARATOR)
	{
		tokenObj = ScanObject.nextToken();
		if(tokenObj->getType() == CJsonToken::BEGIN_ARRAY)
		{
			curr_state = WAIT_DBSTART;
		}
		else if(tokenObj->getType() == CJsonToken::STRING)
		{
			token_str = (CJsonStringToken*)tokenObj;
			attributeNameValue = token_str->getValue();
			cout << attributeNameValue << endl;
			if(Dtbse_Wypt_Detection == true){
				if((strcmp(attributeName.c_str(),"name")) == 0){
					WPname = attributeNameValue;
					WpAttrCount++;
				}
			}
			if(Dtbse_Poi_Detection == true){
				if((strcmp(attributeName.c_str(),"name")) == 0){
					poiName = attributeNameValue;
					PoiAttrCount++;
				}
				else if((strcmp(attributeName.c_str(),"description")) == 0){
					poiDescr = attributeNameValue;
					PoiAttrCount++;
				}
				else if((strcmp(attributeName.c_str(),"type")) == 0){
					poiType = attributeNameValue;
					PoiAttrCount++;
				}
			}
			curr_state = WAIT_NEXT_ATTRIBUTE_NAME_OBJECT;
			}

		else if (tokenObj->getType() == CJsonToken::NUMBER){
			token_num = (CJsonNumberToken*)tokenObj;
			attributeNumValue = token_num->getValue();
			if(Dtbse_Wypt_Detection == true){
				if((strcmp(attributeName.c_str(),"latitude")) == 0){
					WpLat = attributeNumValue;
					WpAttrCount++;
				}
				else if((strcmp(attributeName.c_str(),"longitude")) == 0){
					WpLong = attributeNumValue;
					WpAttrCount++;
				}
			}
			if(Dtbse_Poi_Detection == true){
				if((strcmp(attributeName.c_str(),"latitude")) == 0){
					poiLat = attributeNumValue;
					PoiAttrCount++;
				}
				else if((strcmp(attributeName.c_str(),"longitude")) == 0){
					poiLong = attributeNumValue;
					PoiAttrCount++;
				}
			}

			if(attributeNumValue>=-180 && attributeNumValue<=180)
			{
				cout << attributeNumValue << endl;
			}
			else
			{
				cout << "Attribute value range is Invalid " << " ; "<<endl;
				cerr<<"Error in scanned Line no. "<< ScanObject.scannedLine() <<endl;
			}
			curr_state = WAIT_NEXT_ATTRIBUTE_NAME_OBJECT;

		}
	}
	break;

	case WAIT_DBSTART:
		if(tokenObj->getType() == CJsonToken::BEGIN_OBJECT)
		{
			curr_state = WAIT_ATTRIBUTE_NAME;
		}
		break;

	case WAIT_NEXT_ATTRIBUTE_NAME_OBJECT:
		if(tokenObj->getType() == CJsonToken::VALUE_SEPARATOR){

			curr_state = WAIT_ATTRIBUTE_NAME;

		}
		else if(tokenObj->getType() == CJsonToken::END_OBJECT){
			if(WpAttrCount == 3){
				CWaypoint tempWp(WPname,WpLat,WpLong);
				WpAttrCount = 0;
				if((mode == MERGE) || (mode == REPLACE ) )
	     			 waypointDb.addWayPoint(tempWp);
				else
					cout << "Invalid mode !! Error .." << endl;

				}

			if(PoiAttrCount == 5){
				PoiAttrCount = 0;
				string enumStr;
				t_poi res = funcPrintEnum(poiType);
				switch (res) {
				case 0:
					enumStr = "RESTAURANT";
					break;
				case 1:
					enumStr = "TOURISTIC";
					break;
				case 2:
					enumStr = "TRADEFAIR";
					break;
				case 3:
					enumStr = "UNIVERSITY";
					break;
				default:
					break;
				}

				CPOI tempPoi(res,poiName,poiDescr,poiLat,poiLong);
				if((mode == MERGE) || (mode == REPLACE ))
					poiDb.addPoi(tempPoi);
				else
					cout << "Invalid mode !! Error .." << endl;


			}
			curr_state = WAIT_NEXT_ATTRIBUTE_NAME_OBJECT;
		}

		else if(tokenObj->getType() == CJsonToken::END_ARRAY)
		{

			tokenObj = ScanObject.nextToken();
			if(tokenObj->getType() == CJsonToken::VALUE_SEPARATOR)
			{
				curr_state = WAIT_DB_NAME;
			}

			else if(tokenObj->getType() == CJsonToken::END_ARRAY)
			{
				curr_state = WAIT_NEXT_ATTRIBUTE_NAME_OBJECT;
			}

		}
		break;

	case WAIT_DB_NAME:
			if(tokenObj->getType() == CJsonToken::STRING)
			{
				token_str = (CJsonStringToken*)tokenObj;
				nameOfDatabase = token_str->getValue();
				if(strcmp(nameOfDatabase.c_str(),"waypoints") == 0){

					cout << "Waypoint DB" << endl;

					Dtbse_Wypt_Detection = true;
					Dtbse_Poi_Detection = false;
					curr_state = WAIT_SEPERATOR_FOR_NAME;

				}
				else if(strcmp(nameOfDatabase.c_str(),"pois") == 0){

					cout << "POI DB" << endl;

					Dtbse_Wypt_Detection = false;
					Dtbse_Poi_Detection = true;
					curr_state = WAIT_SEPERATOR_FOR_NAME;

				}
				else{
					cout << "Error ! Incorrect token read for databse name at line " << ScanObject.scannedLine() << endl;
					curr_state = WAIT_SEPERATOR_FOR_NAME;
				}
			}
			break;

	default:
		break;

	}
	}

	return true;
}
