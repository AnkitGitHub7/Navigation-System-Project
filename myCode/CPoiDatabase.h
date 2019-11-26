/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : CPoiDatabase.h
* Author          :	ANKIT ANKIT
* Description     :	Header file for declaration of CPoiDatabase class
*
*
****************************************************************************/

#ifndef CPOIDATABASE_H_
#define CPOIDATABASE_H_

#include <string>

#include "CPOI.h"
#include <map>

/**
 * A CPoiDatabase object contains the database for storing the POIs
 */
class CPoiDatabase{

    /**
     * CPersistanceComponent can access private and all methods of CWaypoint Database class
     */
	friend class CPersistanceComponent;
public:
	/**
	 * The map strMapPoi for storing the POI with name as key and POI as value in a map
	 */
	std::map<std::string,CPOI> strMapPoi;
public:
    /**
     * The Constructor
     * @param void
     */
	CPoiDatabase();
    /**
     * This method will add details of point of interest to the database of POI.
     * @param poi CPOI const &  type
     * @return void
     */
	void addPoi(CPOI const & poi);
    /**
     * This method will return the address of matching poi after searching the POI database.
     * @param string name Value of string to be passed
     * @return pointer
     */
	CPOI* getPointerToPoi(std::string name);
	/**
	 * This method will print all elements in the POI database
	 * @param void
	 * @return void
	 */
	void print();
};
/********************
**  CLASS END
*********************/
#endif /* CPOIDATABASE_H_ */
