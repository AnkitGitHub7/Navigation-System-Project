/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : CPOI.cpp
* Author          :	ANKIT ANKIT
* Description     :	Source file for implementation of CPOI class
*
*
****************************************************************************/

/*System Include Files */
using namespace std;

/*Own Include Files */
#include "CPOI.h"

/*Method Implementations */
CPOI::CPOI(t_poi type , string name, string description, double latitude,
		double longitude) :
		CWaypoint(name, latitude, longitude)
{
	m_type = type;
	m_description = description;
}

void CPOI::print(int format)
{
	cout << "===============" << endl;
	cout << "POI Details : " << endl;
	switch (m_type)
	{
	case RESTAURANT:
		cout << "of Type Restaurant" << " : ";
		break;
	case TOURISTIC:
		cout << "of Type Touristic" << " : ";
		break;
	case TRADEFAIR:
		cout << "of Type TradeFair" << " : ";
		break;
	case UNIVERSITY:
		cout << "of Type University" << " : ";
		break;
	default:
		break;
	}
	cout << m_description;
	cout << endl;
	CWaypoint::print(format);
}

void CPOI::getAllDataByReference(string& name, double& latitude,
		double& longitude, t_poi& type, string& description) const
{
	name = m_name;
	latitude = m_latitude;
	longitude = m_longitude;
	type = m_type;
	description = m_description;
}
ostream& operator <<(std::ostream & o, CPOI & poi){
	poi.print(MMSS);
	return o;
}
