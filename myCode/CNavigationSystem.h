/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : CNavigationSystem.h
* Author          :	ANKIT ANKIT
* Description     :	Header file for declaration of CNavigationSystem class
*
*
****************************************************************************/

#ifndef CNAVIGATIONSYSTEM_H_
#define CNAVIGATIONSYSTEM_H_

#include "CRoute.h"
#include "CPersistanceComponent.h"
#include "CJsaonPersistence.h"
/**
 * A CNavigationSystem object represents navigating route.
 */
class CNavigationSystem{
protected:
    /**
     * The m_GPSSensor variable of type CGPSSensor class
     * @link aggregationByValue
     */
	CGPSSensor m_GPSSensor;
    /**
     * The m_route variable of type CRoute class
     * @link aggregationByValue
     */
	CRoute m_route;
    /**
     * The m_PoiDatabase variable of type CPoiDatabase class
     * @link aggregationByValue
     */
	CPoiDatabase m_PoiDatabase;

	CWpDatabase m_pWaypointDatabase;

	CPersistanceComponent componentTesting;

private:
    /**
     * This method will add CWayPoint and POI to the route.
     * @param void
     * @return void
     */
	void enterRoute();
    /**
     * This method will print CWayPoint and POI in the route.
     * @param void
     * @return void
     */
	void printRoute();
    /**
     * This method will calculate the nearest POI from the current position.
     * @param void
     * @return void
     */
	void printDistanceCurPosNextPoi();

public:
    /**
     * The Constructor
     * @param void
     */
	CNavigationSystem();
    /**
     * The Destructor
     * @param void
     */
	~CNavigationSystem();
    /**
     * This method will create route by adding the waypoint
     * and poi to the route.It will also print the route.
     * @param void
     * @return void
     */
	void run();
};
/********************
**  CLASS END
*********************/
#endif /* CNAVIGATIONSYSTEM_H_ */
