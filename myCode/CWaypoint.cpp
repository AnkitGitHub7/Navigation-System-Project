/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : CWaypoint.cpp
* Author          :	ANKIT ANKIT
* Description     :	Source file for implementation of CWaypoint class
*
*
****************************************************************************/

/* System Include Files */
#include <iostream>
using namespace std;

/* Own Include Files */
#include "CWaypoint.h"

#define R 6378.17  		 /* Macro defined for Radius of Earth */
#define PI 3.14159265 	 /* Macro defined for PI value */

/* Method Implementations */

CWaypoint :: CWaypoint(string name,double latitude,double longitude){
	m_name = name;
	m_latitude = latitude;
	m_longitude = longitude;

	set(name,latitude,longitude);

	/*Use of preprocessor directive to turn on and turn off the printing
	 * of data variable size*/

#ifdef SHOWADRESS
	cout << "Address of the object " << name << " is "<< this <<endl;
	cout << endl;
	cout << "Attributes values are : " << m_name << " , " << m_latitude
			<< " and " << m_longitude << endl;
	cout << endl;
	cout << "Attributes address are : " << &(this->m_name) << " , "
		 << &(this->m_latitude) << " and " << &(this->m_longitude) << endl;
	cout << endl;
   cout << "Data occupied by different attributes are : " << endl;
   cout << "The size of name is " << name.length() << " bytes" << endl;
   cout << "The size of latitude is " << sizeof(latitude) << " bytes" << endl;
   cout << "The size of longitude is " << sizeof(longitude) << " bytes" <<endl;
   cout << endl;
   cout << " ================= " << endl;
   cout << endl;
#endif

}

void CWaypoint :: set(string name,double latitude,double longitude){

	/* Checked and corrected the input parameters*/
	if((latitude >= -90) && (latitude <= 90)){
		m_latitude = latitude;
	}
	else{
		m_name = "INVALID_LOCATION";
		m_latitude = 0.0;
	}
	if(( longitude >= -180) && (longitude <= 180)){
		m_longitude = longitude;
	}
	else{
		m_name = "INVALID_LOCATION";
		m_longitude = 0.0;
	}
}

CWaypoint :: ~CWaypoint(){

}

string CWaypoint :: getName() const{
	return m_name;
}
double CWaypoint :: getLatitude() const{
	return m_latitude;
}
double CWaypoint :: getLongitude() const{
	return m_longitude;
}
void CWaypoint::getAllDataByReference(string & name, double & latitude,
		double & longitude)
{

	name = m_name;
	latitude = m_latitude;
	longitude = m_longitude;

	/*The address of instance variable does not match with the address of
	 * local variables.When getAllDataByReference() function is called, the
	 * local variables are passed as an argument which as different address.
	 * The value of instance variable is then copied to this address.Therefore
	 *  the address of local variable is different but value of instance
	 *  variable after constructor call is updated to these local variables.*/

	cout << "address of instance variable inside ref function : " << &m_name
			<< " , " << &m_latitude << " and " << &m_longitude << endl;
	cout << "address local variable inside ref function : " << &name << " , "
			<< &latitude << " and " << &longitude << endl;
}
void CWaypoint :: transformLatitude2degmmss(int & deg,int & mm,double & ss){
	/*converting into degrees*/
	deg = (int)m_latitude;
	/*converting into minutes*/
	mm = (int) ((m_latitude - (double)deg) * 60);
	/*converting into seconds*/
	ss = ((m_latitude - (double)deg - (double)mm/60) * 60 * 60);
	cout << deg << "deg " << mm << "min " << ss << "s ";
}

void CWaypoint :: transformLongitude2degmmss(int & deg,int & mm,double & ss){
	/*converting into degrees*/
	deg = (int)m_longitude;
	/*converting into minutes*/
	mm = (int) ((m_longitude - (double)deg) * 60);
	/*converting into seconds*/
	ss = ((m_longitude - (double)deg - (double)mm/60) * 60 * 60);
	cout << deg << "deg " << mm << "min " << ss << "s " ;
}

double CWaypoint :: calculateDistance(const CWaypoint & wp){

	double distance = 0;
	double latitude_1 = (m_latitude * PI)/ 180;
	double longitude_1 =(m_longitude * PI)/ 180;
	double latitude_2 = ((wp.m_latitude) * PI) / 180;
	double longitude_2 = ((wp.m_longitude) * PI) / 180;
	/* Formula to calculate the distance between two Waypoints */
	distance = R * acos((sin(latitude_1) * sin(latitude_2)) +
	(cos(latitude_1) * cos(latitude_2) * cos(longitude_2 - longitude_1)));

	return distance;
}

void CWaypoint :: print(int format){

	int degVar = 0;
	int minVar = 0;
	double secVar = 0;
	int varFormat = format;
	cout << m_name ;
	switch(varFormat){
	case DEGREE:
		cout << " on latitude "  <<  m_latitude << " and on longitude "
		<< m_longitude <<" in degree format "<< endl;
		break;
	case MMSS:
		cout << " on latitude " ;
		 //Private function transformLatitude2degmmss is called
		transformLatitude2degmmss(degVar,minVar,secVar);
		cout << "and on longitude ";
		 //Private function transformLongitude2degmmss is called
		transformLongitude2degmmss(degVar,minVar,secVar);
		cout <<"in MMSS format "<< endl;
		break;
	default:
		break;
	}
}

ostream& operator<<(ostream& os, CWaypoint& cw){
	cw.print(MMSS);
	return os;
}
