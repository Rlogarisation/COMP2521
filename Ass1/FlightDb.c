
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "List.h"
#include "FlightDb.h"
#include "AVLTree.h"

struct flightDb {
	Tree byFlightNumber;
	Tree byDepartureAirportAndDay;

};

#define CMPFLIGHTNUM strcmp(RecordGetFlightNumber(r1), RecordGetFlightNumber(r2))
#define CMPDEPAIRPORT strcmp(RecordGetDepartureAirport(r1), RecordGetDepartureAirport(r2))
#define CMPDAY RecordGetDepartureDay(r1) - RecordGetDepartureDay(r2)
#define CMPHOUR RecordGetDepartureHour(r1) - RecordGetDepartureHour(r2)
#define CMPMIN RecordGetDepartureMinute(r1) - RecordGetDepartureMinute(r2)


////////////////////////////////////////////////////////////////////////
// Comparison functions

// flight number, departure airport, day, hour and minute.
int compareByFlightNumber(Record r1, Record r2) {
	if (CMPFLIGHTNUM == 0) {
		// Departure airport
		if (CMPDEPAIRPORT == 0) {
			// day
			if (CMPDAY == 0) {
				// Hour
				if (CMPHOUR == 0) {
					// Minite
					return CMPMIN;
				}
				else {
					return CMPHOUR;
				}
			}
			else {
				return CMPDAY;
			}
		}
		else {
			return CMPDEPAIRPORT;
		}
	}
	else {
		return CMPFLIGHTNUM;
	}
}
// Searches  for all records with the given departure airport and day of
// week (0 to 6), and returns them all in a list in increasing order  of
// (hour, min, flight number).
int compareByDepartureAirportAndDay(Record r1, Record r2) {
	if (CMPDEPAIRPORT == 0) {
		if (CMPDAY == 0) {
			if (CMPHOUR == 0) {
				if (CMPMIN == 0) {
					return CMPFLIGHTNUM;
				}	
				else {
					return CMPMIN;
				}
			}
			else {
				return CMPHOUR;
			}
		}
		else {
			return CMPDAY;
		}
	}
	else {
		return CMPDEPAIRPORT;
	}
}

//  * Searches  for  all  records  between  (day1, hour1, min1)  and (day2,
//  * hour2, min2), and returns them all in a list in increasing  order  of
//  * (day, hour, min, flight number).
// int compareByTimeRange(Record r1, Record r2) {
	
// }


/**
 * Creates a new flight DB. 
 * You MUST use the AVLTree ADT (from Task 1) in your implementation.
 */
FlightDb DbNew(void) {
	FlightDb db = malloc(sizeof(*db));
	if (db == NULL) {
		fprintf(stderr, "error: out of memory\n");
        exit(EXIT_FAILURE);
	}

	db->byFlightNumber = TreeNew(compareByFlightNumber);
	db->byDepartureAirportAndDay = TreeNew(compareByDepartureAirportAndDay);
	return db;
}

/**
 * Frees all memory allocated to the given flight DB
 */
void     DbFree(FlightDb db) {
	TreeFree(db->byFlightNumber, true);
	TreeFree(db->byDepartureAirportAndDay, false);
	free(db);
}

/**
 * Inserts  a  flight  record  into the given DB if there is not already
 * record with the same flight number, departure airport, day, hour  and
 * minute.
 * If  inserted successfully, this function takes ownership of the given 
 * record (so the caller should not modify or free it). 
 * Returns true if the record was successfully inserted,  and  false  if
 * the  DB  already  contained  a  record  with  the same flight number,
 * departure airport, day, hour and minute.
 * The time complexity of this function must be O(log n).
 * You MUST use the AVLTree ADT (from Task 1) in your implementation.
 */
bool     DbInsertRecord(FlightDb db, Record r) {
	if (TreeInsert(db->byFlightNumber, r) == true) {
		TreeInsert(db->byDepartureAirportAndDay, r);
		return true;
	}
	else {
		return false;
	}
}

/**
 * Searches  for  all  records with the given flight number, and returns
 * them all in a list in increasing order of  (day, hour, min).  Returns
 * an empty list if there are no such records. 
 * The  records  in the returned list should not be freed, but it is the
 * caller's responsibility to free the list itself.
 * The time complexity of this function must be O(log n + m), where m is
 * the length of the returned list.
 * You MUST use the AVLTree ADT (from Task 1) in your implementation.
 */
List     DbFindByFlightNumber(FlightDb db, char *flightNumber) {
	/*
	RecordNew(char *flightNumber,  
                 char *departureAirport, char *arrivalAirport, 
                 int departureDay, int departureHour, int departureMinute,
                 int durationMinutes);
	*/
	Record dummyLower = RecordNew(flightNumber, "", "", 0, 0, 0, 0);
	Record dummyUpper = RecordNew(flightNumber, "zzzzzzz", "zzzzzzz", 6, 23, 59, 9999);
	List l = TreeSearchBetween(db->byFlightNumber, dummyLower, dummyUpper);
	RecordFree(dummyLower);
	RecordFree(dummyUpper);
	return l;
}

/**
 * Searches  for all records with the given departure airport and day of
 * week (0 to 6), and returns them all in a list in increasing order  of
 * (hour, min, flight number).
 * Returns an empty list if there are no such records.
 * The  records  in the returned list should not be freed, but it is the
 * caller's responsibility to free the list itself.
 * The time complexity of this function must be O(log n + m), where m is
 * the length of the returned list.
 * You MUST use the AVLTree ADT (from Task 1) in your implementation.
 */
List     DbFindByDepartureAirportDay(FlightDb db, char *departureAirport,
                                     int day) {
	Record dummyLower = RecordNew("", departureAirport, "", day, 0, 0, 0);
	Record dummyUpper = RecordNew("zzzzzzzz", departureAirport, 
	"zzzzzzz", day, 23, 59, 9999);
	List l = TreeSearchBetween(db->byDepartureAirportAndDay, 
	dummyLower, dummyUpper);
	RecordFree(dummyLower);
	RecordFree(dummyUpper);
	return l;
}


/**
 * Searches  for  all  records  between  (day1, hour1, min1)  and (day2,
 * hour2, min2), and returns them all in a list in increasing  order  of
 * (day, hour, min, flight number).
 * Returns an empty list if there are no such records.
 * The  records  in the returned list should not be freed, but it is the
 * caller's responsibility to free the list itself.
 * The time complexity of this function must be O(log n + m), where m is
 * the length of the returned list.
 * You MUST use the AVLTree ADT (from Task 1) in your implementation.
 */
List     DbFindBetweenTimes(FlightDb db, 
                            int day1, int hour1, int min1, 
                            int day2, int hour2, int min2) {
	// TODO: Complete this function
	return ListNew();
}

/**
 * Searches  for  and  returns  the  earliest next flight from the given
 * departure airport, on or after the given (day, hour, min).
 * The returned record must not be freed or modified. 
 * The time complexity of this function must be O(log n).
 * You MUST use the AVLTree ADT (from Task 1) in your implementation.
 */
Record   DbFindNextFlight(FlightDb db, char *departureAirport, 
                          int day, int hour, int min) {
	// TODO: Complete this function
	return NULL;
}

