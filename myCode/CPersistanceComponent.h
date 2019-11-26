/***************************************************************************
 *============= Copyright by Darmstadt University of Applied Sciences =======
 ****************************************************************************
 * Filename        : CPersistanceComponent.h
 * Author          :	ANKIT ANKIT
 * Description     :	Header file for declaration of CPersistanceComponent class
 *
 *
 ****************************************************************************/

#ifndef CPERSISTANCECOMPONENT_H_
#define CPERSISTANCECOMPONENT_H_


#include "CPersistanceStorage.h"

enum err_enum {TYPE1, TYPE2};
/**
 * A CPersistanceComponent object to perform the read and write operation.
 */
class CPersistanceComponent : public CPersistanceStorage{
private:
	/**
	* Reading a single WayPoint data line from a file
	* @param line string The line to be read
	* @param linecnt1 int The line count
	* @param flag1,flag2 To store the result
	* @return bool
	*/
	bool readWaypointDataLine(std::string line, int linecnt1,bool &,bool &,err_enum &,std::string &,std::string &,std::string &);
	/**
	* Reading a single POI data line from a file
	* @param line string The line to be read
	* @param linecnt2 int The line count
	* @param flag1,flag2 To store the result
	* @return bool
	*/
	bool readPoiDataLine(std::string line, int linecnt2,bool &,bool &,err_enum &,std::string &,std::string &,std::string &,std::string &,std::string &);
	/**
	* To get the enum value from a string
	* @param string& str The string to be converted
	* @return t_poi
	*/
	t_poi funcPrintEnum(const std::string& str);
public:
	/**
	 * The Constructor
	 * @param void
	 */
	CPersistanceComponent();
	/**
	 * The Destructor
	 * @param void
	 */
	~CPersistanceComponent();
	/**
	* Set the name of the media to be used for persistent storage.
	* The exact interpretation of the name depends on the implementation
	* of the component.
	* @param name the media to be used
	* @return void
	*/
	 void setMediaName(std::string name);
	/**
	* Write the data to the persistent storage.
	*
	* @param waypointDb the data base with way points
	* @param poiDb the database with points of interest
	* @return true if the data could be saved successfully
	*/
	 bool writeData (const CWpDatabase& waypointDb,
			const CPoiDatabase& poiDb);
	/**
	* Fill the databases with the data from persistent storage. If
	* merge mode is MERGE, the content in the persistent storage
	* will be merged with any content already existing in the data
	* bases. If merge mode is REPLACE, already existing content
	* will be removed before inserting the content from the persistent
	* storage.
	*
	* @param waypointDb the the data base with way points
	* @param poiDb the database with points of interest
	* @param mode the merge mode
	* @return true if the data could be read successfully
	*/
	 bool readData (CWpDatabase& waypointDb,
			 CPoiDatabase& poiDb,MergeMode mode);


};
/********************
**  CLASS END
*********************/

#endif /* CPERSISTANCECOMPONENT_H_ */
