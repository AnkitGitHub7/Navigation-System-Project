/***************************************************************************
 *============= Copyright by Darmstadt University of Applied Sciences =======
 ****************************************************************************
 * Filename        : CWaypoint.h
 * Author          :	ANKIT ANKIT
 * Description     :	Header file for declaration of CWaypoint class
 *
 *
 ****************************************************************************/

#ifndef CWAYPOINT_H_
#define CWAYPOINT_H_

#include <string>
#include <cmath>		 /* Inclusion of math library for computation of distance*/
#include <iostream>
#include <stdlib.h>
//#define SHOWADRESS	 /* Preprocessor directive for printing the address*/
#define DEGREE 1   		 /* Macro defined for DEGREE Format */
#define MMSS 2     		 /* Macro defined for MMSS Format */

/**
 * A CWaypoint object represents name of place , latitude and longitude.
 */
class CWaypoint {
protected:
	/**
	 * The string value
	 */
	std::string m_name;
	/**
	 * The latitude value
	 */
	double m_latitude;
	/**
	 * The longitude value
	 */
	double m_longitude;
public:
	/**
	 * This method will convert longitude into degree min and sec format.
	 * @param int & deg Deg is passed as reference to store the result
	 * @param int & mm Min is passed as reference to store the result
	 * @param int & ss Sec is passed as reference to store the result
	 * @return void
	 */
	void transformLongitude2degmmss(int & deg, int & mm, double & ss);
	/**
	 * This method will convert latitude into degree min and sec format.
	 * @param int & deg Deg is passed as reference to store the result
	 * @param int & mm Min is passed as reference to store the result
	 * @param int & ss Sec is passed as reference to store the result
	 * @return void
	 */
	void transformLatitude2degmmss(int & deg, int & mm, double & ss);
public:
	/**
	 * The Constructor
	 * @param string name Name of the default string
	 * @param double latitude Value of the default latitude
	 * @param double longitude Value of the default longitude
	 */
	CWaypoint(std::string name = "Default Name", double latitude = 0,
			double longitude = 0);
	/**
	 * The Destructor
	 * @param void
	 */
	virtual ~CWaypoint();
	/**
	 * This method will return the set the parameters.
	 * @param string name String to set the name
	 * @param double latitude Value to be set for latitude
	 * @param double longitude Value to be set for  longitude
	 * @return void
	 */
	void set(std::string name, double latitude, double longitude);
	/**
	 * This method will return the name stored in CWaypoint object.
	 * @param void
	 * @return string
	 */
	std::string getName() const;
	/**
	 * This method will return the Latitude stored in CWaypoint object.
	 * @param void
	 * @return double
	 */
	double getLatitude() const;
	/**
	 * This method will return the Longitude stored in CWaypoint object.
	 * @param void
	 * @return double
	 */
	double getLongitude() const;
	/**
	 * This method will store the values of CWaypoint in variables passed by user.
	 * @param string & name Variable to store the name
	 * @param double & latitude Variable to be store latitude
	 * @param double & longitude Variable to be store longitude
	 * @return void
	 */
	void getAllDataByReference(std::string & name, double & latitude,
			double & longitude);
	/**
	 * This method will return the distance between two CWaypoints
	 * @param const CWaypoint & wp The reference of type CWaypoint is passed.
	 * @return double Distance is returned by this method.
	 */
	double calculateDistance(const CWaypoint & wp);
	/**
	 * This method will print the distance between two CWaypoints in
	 * format specified by the user.
	 * @param int format Format specified by user for priting the distance.
	 * @return void
	 */
	void print(int format=MMSS);
	/**
	 * This is a << operator overloading to print the cwpoint object
	 * directly on the console output.
	 * @param ostream& os output char stream
	 * @param CWaypoint& cw CWayPoint object to be printed.
	 * @return ostream
	 */
	friend std::ostream & operator<<(std::ostream& os, CWaypoint& cw);
};
/********************
 **  CLASS END
 *********************/
#endif /* CWAYPOINT_H_ */
