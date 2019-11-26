/***************************************************************************
 *============= Copyright by Darmstadt University of Applied Sciences =======
 ****************************************************************************
 * Filename        :    CDatabaseTemplate.h
 * Author          :	ANKIT ANKIT
 * Description     :	Header file for declaration of CDatabaseTemplate template
 *
 *
 ****************************************************************************/


#ifndef CDATABASETEMPLATE_H_
#define CDATABASETEMPLATE_H_

#include <map>
#include <string>
#include <iostream>
#include "CPoiDatabase.h"

template<class keyType,class WpOrPoi>
class CDatabaseTemplate
{
private:
	/**
	 * The map mapWpOrPoi for storing the WayPoint or Poi with name as
	 *  key and WayPoint as value in a map
	 */
	std::map<keyType,WpOrPoi> mapWpOrPoi;
public:
	/**
	 * The Constructor
	 * @param void
	 */
	CDatabaseTemplate(){

	}
	/**
	 * The Destrcutor
	 * @param void
	 */
	~CDatabaseTemplate(){
		mapWpOrPoi.clear();
	}
	/**
	 * This method will add waypoint or Poi to the database.
	 * @param wpOrPoiVar WpOrPoi const & type
	 * @return void
	 */
	void addWayPointOrPoi(WpOrPoi const & wpOrPoiVar)
	{
		/*
		 * Check for duplicate keys in maps
		 * */
		typename std::map<keyType,WpOrPoi>::iterator it ;
		it = mapWpOrPoi.find(wpOrPoiVar.getName());
		if(it == mapWpOrPoi.end())
		{
			mapWpOrPoi.insert(std::pair<keyType,WpOrPoi>(wpOrPoiVar.getName(), wpOrPoiVar));
		}
		else{
			std::cout << "Error !! Duplicate keys found in maps" << std::endl;
		}
	}
	/**
	 * This method will return the address of matching Waypoint.
	 * @param name keyType type Value to be passed
	 * @return WpOrPoi* pointer to the waypoint or Poi object address
	 */
	WpOrPoi* getPointerToWaypointOrPOi(keyType name){
		for (typename std::map<keyType,WpOrPoi>::iterator ii = mapWpOrPoi.begin();
				ii != mapWpOrPoi.end(); ++ii) {
			if ((*ii).first == name) {
				return &((*ii).second);
			}
		}

		std::cout << "ERROR : Could not find waypoint or poi in the pool" << std::endl;
		return 0;
	}
	/**
	 * This method will print all elements in the waypoint or Poi database
	 * @param void
	 * @return void
	 */
	void print() {

		/*
		 * Check if the template database map is empty before printing
		 * */
		if(!(mapWpOrPoi.empty())){
			for (typename std::map<keyType,WpOrPoi>::iterator ii = mapWpOrPoi.begin();
					ii != mapWpOrPoi.end(); ++ii) {
				//mapWpOrPoi[(ii->first)].print();
				(*ii).second.print(MMSS);
			}
		}
		else{
			std::cout << "ERROR : Cannot print a empty map" << std::endl;
		}

	}

};

#endif /* CDATABASETEMPLATE_H_ */
