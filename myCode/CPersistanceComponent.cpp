/***************************************************************************
 *============= Copyright by Darmstadt University of Applied Sciences =======
 ****************************************************************************
 * Filename        : CPersistanceComponent.cpp
 * Author          :	ANKIT ANKIT
 * Description     :	Header file for declaration of CPersistanceComponent class
 *
 *
 ****************************************************************************/

/*System Include Files */
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <math.h>
#include"algorithm"
#include <cstdlib> // for atof function

using namespace std;

/*Own Include Files */
#include "CPersistanceComponent.h"

/*Method Implementations */
CPersistanceComponent::CPersistanceComponent() {

}

CPersistanceComponent::~CPersistanceComponent() {

}

bool CPersistanceComponent::writeData(const CWpDatabase& waypointDb,
		const CPoiDatabase& poiDb) {

	/* Writing Waypoints in the file */
	ofstream file1;
	file1.open("MediaFile-wp.txt");
	if (file1.fail()) {
		cerr << "Error opening waypoint media file" << endl;
		return false;
	}
	for (map<string, CWaypoint>::const_iterator ii =
			waypointDb.strMapWp.begin(); ii != waypointDb.strMapWp.end();
			++ii) {
		string name;
		file1 << (*ii).first << ";" << (*ii).second.getLatitude() << ";"
				<< (*ii).second.getLongitude() << endl;

	}
	file1.close();
	/* Writing pois in the file */

	string name, desc;
	double lat, lon;
	t_poi type;
	string enumStr;

	ofstream file2;
	file2.open("MediaFile-poi.txt");
	if (file2.fail()) {
		cerr << "Error opening poi media file" << endl;
		return false;
	}
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
		file2 << enumStr << ";" << name << ";" << desc << ";" << lat << ";"
				<< lon << endl;
	}
	file2.close();

	return true;
}

bool CPersistanceComponent::readData(CWpDatabase& waypointDb,
		CPoiDatabase& poiDb, MergeMode mode) {
	/*Clearing the database when mode is replace while reading a file*/
	if (mode == REPLACE) {
		waypointDb.strMapWp.clear();
		poiDb.strMapPoi.clear();
	}

	fstream file1;

	file1.open(mediaNameWp.c_str(),fstream::in);
	/*Checking if the file can be opened*/
	if (file1.fail()) {
		cerr << "Error opening waypoint media file" << endl;
		return false;
	}

	int linecnt1 = 0;
	/*Looping till the end of the file*/
	while (!file1.eof()) {

		string name1, lat1, long1;

		double lat2, long2;
		/*Flags to indicate the error*/
		bool flag1 = false;
		bool flag2 = false;

		err_enum err;

		string line;
		/*Looping till all lines are read*/
		while (getline(file1, line)) {

			linecnt1++;

			/*calling the readWaypointDataLine to read single line from the file*/
			bool res = readWaypointDataLine(line, linecnt1, flag1, flag2, err,
					name1, lat1, long1);

			/*If  the line is read correctly the values extracted from line
			 * are added to the CWaypoint DataBase depending on mode*/
			if (res == true) {

				/*Converting string to float values*/
				lat2 = strtod(lat1.c_str(),NULL);
				long2 = strtod(long1.c_str(),NULL);

/*				cout << "data read for from media file for WP : " << endl;
				cout << name1 << endl;
				cout << lat2 << endl;
				cout << long2 << endl;*/

				/*creating CWaypoint object with correct read data*/
				CWaypoint cw1(name1, lat2, long2);
				/*Storing the object cwaypoint in database*/
				waypointDb.addWayPoint(cw1);

			} else {
				/*Checking for the error flags to determine the error type*/
				if ((flag1 == true) || (flag2 == true)) {

					cout << "Error : ";
					switch (err) {
					case TYPE1:
						cout << " wrong datatype read !! " << " : ";
						break;
					case TYPE2:
						cout << " wrong number of data read !! " << " : ";
						break;
					default:
						break;
					}
					cout << " in line number ";
					cout << linecnt1;
					cout << " : ";
					cout << line;
					cout << " in waypoint media file";
					cout << endl;
				}

				return false;
			}
		}
	}

	file1.close();

	fstream file2;
	file2.open(mediaNamePoi.c_str(),fstream::in);

	if (file2.fail()) {
		cerr << "Error opening poi media file" << endl;
		return false;
	}

	int linecnt2 = 0;
	/*Looping till end of the file*/
	while (!file2.eof()) {

		string cptype;

		string name1, descrp1, line, lat1, long1;

		double lat2, long2;
		/*Flags to indicate the error*/
		bool flag1 = false;
		bool flag2 = false;

		err_enum err;
		/*Looping through all lines in a file*/
		while (getline(file2, line)) {

			linecnt2++;
			/*calling the readPoiDataLine to read single line from the file*/
			bool res = readPoiDataLine(line, linecnt2, flag1, flag2, err,
					cptype, name1, descrp1, lat1, long1);
			/*If  the line is read correctly the values extracted from line
			 * are added to the CWaypoint DataBase depending on mode*/
			if (res == true) {
				/*Converting string to float values*/
				lat2 = strtod(lat1.c_str(),NULL);
				long2 = strtod(long1.c_str(),NULL);

				t_poi res = funcPrintEnum(cptype);

				string enumStr;
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

				CPOI cp(res, name1, descrp1, lat2, long2);
				/*Storing the object poi in database*/
				poiDb.addPoi(cp);

			} else {
				/*Checking for the error flags to determine the error type*/
				if ((flag1 == true) || (flag2 == true)) {

					cout << "Error : ";
					switch (err) {
					case TYPE1:
						cout << " wrong datatype read !! " << " : ";
						break;
					case TYPE2:
						cout << " wrong number of data read !! " << " : ";
						break;
					default:
						break;
					}
					cout << " in line number ";
					cout << linecnt2;
					cout << " : ";
					cout << line;
					cout << " in poi media file";
					cout << endl;
				}

				return false;
			}
		}
	}
	file2.close();

	return true;

}

void CPersistanceComponent::setMediaName(string name) {
	mediaNameWp = name + "-wp.txt";
	mediaNamePoi = name + "-poi.txt";
}

bool CPersistanceComponent::readWaypointDataLine(string line, int linecnt1,
		bool & flag1, bool & flag2, err_enum & err_type, string & name,
		string & d1, string &d2) {

	string strName, strLat, strLong;

	int numWords = 1; // Holds number of words
	/* Checking for number of parameters read from a line*/
	for (unsigned int j = 0; j < line.size(); j++) {
		if ((line[j] == ';') || (line[j] == ','))
		{
			/*Counting the number of parameters*/
			numWords++;
		}
	}

	if (numWords != 3) {

		flag2 = true;
		err_type = TYPE2;
		return false;
	}

	int varA = 0;

	while (!((line[varA] == ';') || (line[varA] == ','))) {
		/*Checking the first parameter*/
		if (!((line[varA] <= 'z' && line[varA] >= 'a')
				|| (line[varA] <= 'Z' && line[varA] >= 'A')
				|| (line[varA] <= '9' && line[varA] >= '0'))) {

			flag1 = true;
			err_type = TYPE1;
			return false;
		}

		strName += line[varA];
		varA++;
	}
	name = strName;

	int varB = varA + 1;
	while (!((line[varB] == ';') || (line[varB] == ','))) {
		/*Checking the second parameter*/
		if (!((line[varB] <= '9' && line[varB] >= '0') || (line[varB] == '.'))) {
			flag1 = true;
			err_type = TYPE1;
			return false;
		}

		strLat += line[varB];
		varB++;
	}
	int counter1 = 0;
	int j1 = 0;
	while (strLat[j1] != '\0') {
		if (strLat[j1] == '.') //Checking for float value
				{
			counter1++;
		}
		j1++;
	}
	if (counter1 != 1) {
		flag1 = true;
		err_type = TYPE1;
		return false;
	}

	d1 = strLat;

	int varC = varB + 1;

	while (!(line[varC] == '\0')) {
		/*Checking the third parameter*/
		if (!((line[varC] <= '9' && line[varC] >= '0') || (line[varC] == '.'))) {
			flag1 = true;
			err_type = TYPE1;
			return false;
		}

		strLong += line[varC];
		varC++;
	}

	int counter2 = 0;
	int j2 = 0;
	while (strLong[j2] != '\0') {
		if (strLong[j2] == '.') //Checking for float
		{
			counter2++;
		}
		j2++;
	}

	if (counter2 != 1) {

		flag1 = true;
		err_type = TYPE1;
		return false;
	}

	d2 = strLong;

	return true;
}
bool CPersistanceComponent::readPoiDataLine(string line, int linecnt2,
		bool & flag1, bool & flag2, err_enum & err_type, string & tp,
		string & des, string & nam, string & lat, string & lon) {

	string strName1, strName2, strName3;
	string strLat, strLong;

	int numWords = 1; // Holds number of words

	/* Checking for number of parameters read from a line*/
	for (unsigned int j = 0; j < line.size(); j++) {
		if ((line[j] == ';') || (line[j] == ','))
		{
			numWords++;
		}
	}

	if (numWords != 5) {

		flag2 = true;
		err_type = TYPE2;
		return false;
	}

	int varA = 0;
	/* Checking for first parameter read from a line*/
	while (!((line[varA] == ';') || (line[varA] == ','))) {

		if (!((line[varA] <= 'z' && line[varA] >= 'a')
				|| (line[varA] <= 'Z' && line[varA] >= 'A')
				|| (line[varA] <= '9' && line[varA] >= '0'))) {
			flag1 = true;
			err_type = TYPE1;
			return false;
		}
		strName1 += line[varA];
		varA++;
	}
	tp = strName1;

	int varB = varA + 1;
	/* Checking for second parameter read from a line*/
	while (!((line[varB] == ';') || (line[varB] == ','))) {

		if (!((line[varB] <= 'z' && line[varB] >= 'a')
				|| (line[varB] <= 'Z' && line[varB] >= 'A')
				|| (line[varB] <= '9' && line[varB] >= '0')
				|| (line[varB] <= ' '))) {

			flag1 = true;
			err_type = TYPE1;
			return false;
		}
		strName2 += line[varB];
		varB++;
	}
	nam = strName2;

	int varC = varB + 1;
	/* Checking for third parameter read from a line*/
	while (!((line[varC] == ';') || (line[varC] == ','))) {

		if (!((line[varC] <= 'z' && line[varC] >= 'a')
				|| (line[varC] <= 'Z' && line[varC] >= 'A')
				|| (line[varC] <= '9' && line[varC] >= '0')
				|| (line[varC] <= ' '))) {

			flag1 = true;
			err_type = TYPE1;
			return false;
		}
		strName3 += line[varC];
		varC++;
	}
	des = strName3;

	int varD = varC + 1;
	/* Checking for fourth parameter read from a line*/
	while (!((line[varD] == ';') || (line[varD] == ','))) {
		if (!((line[varD] <= '9' && line[varD] >= '0') || (line[varD] == '.'))) {
			flag1 = true;
			err_type = TYPE1;
			return false;
		}
		strLat += line[varD];
		varD++;
	}

	int counter1 = 0;
	int j1 = 0;
	while (strLat[j1] != '\0') {
		if (strLat[j1] == '.') //Checking for float value
				{
			counter1++;
		}
		j1++;
	}

	if (counter1 != 1) {
		flag1 = true;
		err_type = TYPE1;
		return false;
	}

	lat = strLat;

	int varE = varD + 1;
	/* Checking for last parameter read from a line*/
	while (!(line[varE] == '\0')) {
		if (!((line[varE] <= '9' && line[varE] >= '0') || (line[varE] == '.'))) {
			flag1 = true;
			err_type = TYPE1;
			return false;
		}

		strLong += line[varE];
		varE++;
	}

	int counter2 = 0;
	int j2 = 0;
	while (strLong[j2] != '\0') {
		if (strLong[j2] == '.') //Checking for float
				{
			counter2++;
		}
		j2++;
	}

	if (counter2 != 1) {

		flag1 = true;
		err_type = TYPE1;
		return false;
	}

	lon = strLong;

	return true;

}
t_poi CPersistanceComponent::funcPrintEnum(const std::string& str) {
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
