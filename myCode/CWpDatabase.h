/***************************************************************************
 *============= Copyright by Darmstadt University of Applied Sciences =======
 ****************************************************************************
 * Filename        : CWpDatabase.h
 * Author          :	ANKIT ANKIT
 * Description     :	Header file for declaration of CWaypoint class
 *
 *
 ****************************************************************************/

#ifndef CWPDATABASE_H_
#define CWPDATABASE_H_

#include "CWaypoint.h"

#include <string>
#include <map>

/**
 * A CWpDatabase object represents the database which stores the WayPoints
 */
class CWpDatabase {
	/**
	 * CPersistanceComponent can access private variables and methods of CWaypoint Database class
	 */
	friend class CPersistanceComponent;
public:
	/**
	 * The map strMapWp for storing the WayPoint with name as key and WayPoint as value in a map
	 */

	std::map<std::string, CWaypoint> strMapWp;

public:

	/**
	 * The Constructor
	 * @param void
	 */
	CWpDatabase();
	/**
	 * This method will add waypoint to the waypoint database.
	 * @param wp CWaypoint const & type
	 * @return void
	 */
	void addWayPoint(CWaypoint const & wp);
	/**
	 * This method will return the address of matching Waypoint.
	 * @param name string type Value of string to be passed
	 * @return CWaypoint* pointer to the waypoint object address
	 */
	CWaypoint* getPointerToWaypoint(std::string name);
	/**
	 * This method will print all elements in the waypoint database
	 * @param void
	 * @return void
	 */
	void print();
};
#endif /* CWPDATABASE_H_ */
