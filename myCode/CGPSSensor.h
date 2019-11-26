/***************************************************************************
*============= Copyright by Darmstadt University of Applied Sciences =======
****************************************************************************
* Filename        : CGPSSensor.h
* Author          :	ANKIT ANKIT
* Description     :	Header file for declaration of CGPSSensor class
*
*
****************************************************************************/


#ifndef CGPSSENSOR_H_
#define CGPSSENSOR_H_

#include "CWaypoint.h"

/**
 * A CGPSSensor object provides the current position
 * entered by the user
 */
class CGPSSensor{
public:
    /**
     * The Constructor
     * @param void
     */
	CGPSSensor();
    /**
     * This method will return the current position entered by the user.
     * @param void
     * @return CWaypoint It contains the latitude and longitude of
     * current position
     */
	CWaypoint getCurrentPosition();
};
/********************
**  CLASS END
*********************/
#endif /* CGPSSENSOR_H_ */
