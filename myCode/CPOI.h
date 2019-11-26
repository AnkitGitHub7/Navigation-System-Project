/***************************************************************************
 *============= Copyright by Darmstadt University of Applied Sciences =======
 ****************************************************************************
 * Filename        : CPOI.h
 * Author          :	ANKIT ANKIT
 * Description     :	Header file for declaration of CPOI class
 *
 *
 ****************************************************************************/

#ifndef CPOI_H_
#define CPOI_H_

#include <string>
#include<iostream>

#include "CWaypoint.h"

/*Enum for specifying the type of poi */
enum t_poi {
	RESTAURANT, TOURISTIC, TRADEFAIR, UNIVERSITY
};

/**
 * A CPOI object represents different point of interest.
 */
class CPOI: public CWaypoint {

	/**
	 * CPersistanceComponent can access private and all methods of CWaypoint Database class
	 */
	friend class CPersistanceComponent;
private:
	/**
	 * The m_type variable of type enum t_poi
	 * @link aggregationByValue
	 */
	t_poi m_type;
	/**
	 * The m_description variable of type string
	 */
	std::string m_description;

public:
	/**
	 * Method implemented in printing Point of Interest in defined format.Polymorphic approach
	 */
	void print(int);
	/**
	 * The Constructor
	 * @param t_poi type , defaults to RESTAURANT
	 * @param string name , defaults to Default Name
	 * @param string Description , defaults to default description
	 * @param double latitude , defaults to 0
	 * @param double longitude , defaults to 0
	 */
	CPOI(t_poi type = RESTAURANT, std::string name = "Default Name",
			std::string description = "default description",
			double latitude = 0, double longitude = 0);
	/**
	 * This method is used to get all details for POI using call by reference
	 * @param string name Variable to store name of poi
	 * @param double latitude Variable to store latitude of poi
	 * @param double longitude Variable to store longitude of poi
	 * @param t_poi type Variable to store type of poi
	 * @param string Description Variable to Description name of poi
	 * @return void
	 */
	void getAllDataByReference(std::string& name, double& latitude,
			double& longitude, t_poi& type, std::string& description) const;
	/**
	 * This is a << operator overloading to print the poi object
	 * directly on the console output.
	 * @param os ostream& output char stream
	 * @param poi CPOI& CPOI object to be printed.
	 * @return ostream
	 */
	friend std::ostream& operator<<(std::ostream& o, CPOI& poi);
};
/********************
 **  CLASS END
 *********************/
#endif /* CPOI_H_ */
