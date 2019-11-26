/***************************************************************************
 *============= Copyright by Darmstadt University of Applied Sciences =======
 ****************************************************************************
 * Filename        : CPersistanceStorage.h
 * Author          :	ANKIT ANKIT
 * Description     :	Header file for declaration of CPersistanceStorage class
 *
 *
 ****************************************************************************/

#ifndef CPERSISTENTSTORAGE_H_
#define CPERSISTENTSTORAGE_H_

/*Include Files */
#include <iostream>
#include "CPoiDatabase.h"
#include "CWpDatabase.h"

class CPersistanceStorage{
protected:
	/*Declared protected in scope, it is used only by CPersistanceComponent by inheritance*/
	std::string mediaNameWp,mediaNamePoi;
public:
	/**
	* Set the name of the media to be used for persistent storage.
	* The exact interpretation of the name depends on the implementation
	* of the component.
	* @param name the media to be used
	* @return void
	*/
	virtual void setMediaName(std::string name) = 0;
	/**
	* Write the data to the persistent storage.
	*
	* @param waypointDb the data base with way points
	* @param poiDb the database with points of interest
	* @return true if the data could be saved successfully
	*/
	virtual bool writeData (const CWpDatabase& waypointDb,
			const CPoiDatabase& poiDb) = 0;
	/**
	* The mode to be used when reading the data bases.
	*/
	enum MergeMode { MERGE,REPLACE };
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
	virtual bool readData (CWpDatabase& waypointDb,
			 CPoiDatabase& poiDb,MergeMode mode) = 0;

	/**
	 * The Constructor
	 */
	CPersistanceStorage();

	/*Destructor must be virtual if methods are virtual*/
	virtual ~CPersistanceStorage();
};

#endif /* CPERSISTENTSTORAGE_H_ */
