/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : CRoute.h
* Author          :	ANKIT ANKIT
* Description     :	Header file for declaration of CRoute class
*
*
****************************************************************************/

#ifndef CROUTE_H_
#define CROUTE_H_

#include <string>
#include <list>
#include <iostream>
#include <vector>

#include "CGPSSensor.h"
#include "CPoiDatabase.h"
#include "CWpDatabase.h"

#define ZERO_POI_COUNT 2

/**
 * A CRoute object represents inclusion of WayPoints and point of interests.
 */
class CRoute{
private:
    /**
     * The m_pPoiDatabase pointer
     */
	CPoiDatabase* m_pPoiDatabase;
    /**
     * The m_pPoiDatabase pointer
     */
	CWpDatabase* m_pWaypointDatabase;
    /**
     * The m_pListRoute list to store the address of POI and WayPoint objects.
     */
	std::list <CWaypoint*> m_pListRoute;

public:
    /**
     * The CRoute Constructor
     * @param void
     */
	CRoute();
    /**
     * Copy constructor, copies data from one class to another
     * @param origin CRoute const &
     */
	CRoute(CRoute const & origin);
    /**
     * The Destructor
     * @param void
     */
	~CRoute();
    /**
     * cntwp Variable to keep the count of WayPoints stored in CRoute
     */
	 int cntwp;
	    /**
	     * cntpoi Variable to keep the count of POI stored in CRoute
	     */
	 int cntpoi;

    /**
     * This method will set the address value to m_pPoiDatabase.
     * @param CPoiDatabase* pPoiDB Pointer to pass address.
     * @return void
     */
	void connectToPoiDatabase(CPoiDatabase* pPoiDB=0);
    /**
     * This method will set the address value to CWpDatabase.
     * @param CWpDatabase* pWpDB Pointer to pass address.
     * @return void
     */
	void connectToWpDatabase(CWpDatabase* pWpDB=0);
    /**
     * This method will add details of Waypoint to the CRoute.
     * @param string name Name of Waypoint
     * @return void
     */
	void addWaypoint(std::string name);
    /**
     * This method will add details of point of interest with name namePoi only after
     * the waypoint with name afterWp.
     * @param string namePoi Matching of POI is done using the string namePoi
     * @param string afterWp Matching of waypoint is done using the string afterWp
     * @return void
     */
	void addPoi(std::string namePoi,std::string afterWp);
    /**
     * This method calculates the shortest distance.
     * It is been used by CNavigationSystem to get nearest poi from current
     * positon.
     * @param CWaypoint const & wp  WayPoint passed as reference
     * @param CPOI & poi Point Of Interest passed as reference
     * @return double
     */
	double getDistanceNextPoi(CWaypoint const & wp , CPOI & poi);
    /**
     * This method will print all the CWaypoint and Point Of Interest stored in route
     * @param void
     * @return void
     */
	void print();
    /**
     * This is operator += overloading which searches for a CWayPoint and POI
     * with name as name and adds them to end of the CRoute.
     * @param string name
     * @return void
     */
	void operator += (std::string name);
    /**
     * This is operator + overloading which adds the two CRoute
     * @param CRoute & CRoute to be added
     * @return CRoute
     */
	CRoute operator + (CRoute &);
	/*
	 * This method returns a vector of pointers to the Waypoint
	 * and Pois that are added to the route
	 * @param void
	 * @return vector<const CWaypoint*>
	 * */

	const std::vector<const CWaypoint*> getRoute();

};
/********************
**  CLASS END
*********************/
#endif /* CROUTE_H_ */
