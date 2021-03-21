// Assignment 1 21T1 COMP2521: ADTs: FlightDb Using a Generic AVL Tree
//
// This program was written by Zheng Luo (z5206267@ad.unsw.edu.au)
// on March/2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "List.h"
#include "FlightDb.h"
#include "AVLTree.h"

#define CMPFLIGHTNUM strcmp(RecordGetFlightNumber(r1), \
RecordGetFlightNumber(r2))
#define CMPDEPAIRPORT strcmp(RecordGetDepartureAirport(r1), \
RecordGetDepartureAirport(r2))
#define CMPDAY RecordGetDepartureDay(r1) - RecordGetDepartureDay(r2)
#define CMPHOUR RecordGetDepartureHour(r1) - RecordGetDepartureHour(r2)
#define CMPMIN RecordGetDepartureMinute(r1) - RecordGetDepartureMinute(r2)
#define MINDAY 0
#define MAXDAY 6
#define MINHOURS 0
#define MAXHOURS 23
#define MINMINS 0
#define MAXMINS 59
#define MINDURATION 0
#define MAXDURATION 9999
#define MINCHAR ""
#define MAXCHAR "zzzzzzz"

struct flightDb {
	Tree byFlightNumber;
	Tree byDepartureAirportAndDay;
	Tree byTimeRange;
	Tree byNext;
};

////////////////////////////////////////////////////////////////////////
// Comparison functions

// This function compares the records in the order of 
// flight number, departure airport, day, hour and minute.
// This function will return positive integer if r1 is greater than r2,
// return negative integer if r1 is smaller than r2, 
// or return 0 if r1 is equal to r2.
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

// This function compares the records in the order of 
// departure airport, day, hour, minute, and flight number.
// This function will return positive integer if r1 is greater than r2,
// return negative integer if r1 is smaller than r2, 
// or return 0 if r1 is equal to r2.
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

// This function compares the records in the order of 
// day, hour, minute, and flight number.
// This function will return positive integer if r1 is greater than r2,
// return negative integer if r1 is smaller than r2, 
// or return 0 if r1 is equal to r2.
int compareByTimeRange(Record r1, Record r2) {
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

// This function compares the records in the order of 
// departure airport, day, hour, and minute.
// This function will return positive integer if r1 is greater than r2,
// return negative integer if r1 is smaller than r2, 
// or return 0 if r1 is equal to r2.
int compareByNext(Record r1, Record r2) {
	if (CMPDEPAIRPORT == 0) {
		if (CMPDAY == 0) {
			if (CMPHOUR == 0) {
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

// End of comparison functions
////////////////////////////////////////////////////////////////////////

// Creates a new flight DB. 
FlightDb DbNew(void) {
	FlightDb db = malloc(sizeof(*db));
	if (db == NULL) {
		fprintf(stderr, "error: out of memory\n");
        exit(EXIT_FAILURE);
	}

	db->byFlightNumber = TreeNew(compareByFlightNumber);
	db->byDepartureAirportAndDay = TreeNew(compareByDepartureAirportAndDay);
	db->byTimeRange = TreeNew(compareByTimeRange);
	db->byNext = TreeNew(compareByNext);
	return db;
}


// Frees all memory allocated to the given flight DB.
void     DbFree(FlightDb db) {
	TreeFree(db->byFlightNumber, true);
	TreeFree(db->byDepartureAirportAndDay, false);
	TreeFree(db->byTimeRange, false);
	TreeFree(db->byNext, false);
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
 */
bool     DbInsertRecord(FlightDb db, Record r) {
	if (TreeInsert(db->byFlightNumber, r) == true) {
		TreeInsert(db->byDepartureAirportAndDay, r);
		TreeInsert(db->byTimeRange, r);
		TreeInsert(db->byNext, r);
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
 */
List     DbFindByFlightNumber(FlightDb db, char *flightNumber) {
	Record dummyLower = RecordNew(flightNumber, MINCHAR, MINCHAR, MINDAY, 
	MINHOURS, MINMINS, MINDURATION);
	Record dummyUpper = RecordNew(flightNumber, MAXCHAR, MAXCHAR, MAXDAY, 
	MAXHOURS, MAXMINS, MAXDURATION);

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
 */
List     DbFindByDepartureAirportDay(FlightDb db, char *departureAirport,
                                     int day) {
	Record dummyLower = RecordNew(MINCHAR, departureAirport, 
	MINCHAR, day, MINHOURS, MINMINS, MINDURATION);
	Record dummyUpper = RecordNew(MAXCHAR, departureAirport, 
	MAXCHAR, day, MAXHOURS, MAXMINS, MAXDURATION);

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
 */
List     DbFindBetweenTimes(FlightDb db, 
                            int day1, int hour1, int min1, 
                            int day2, int hour2, int min2) {
	Record dummyLower = RecordNew(MINCHAR, MINCHAR, MINCHAR, day1, 
	hour1, min1, MINDURATION);
	Record dummyUpper = RecordNew(MAXCHAR, MAXCHAR, MAXCHAR, day2, 
	hour2, min2, MAXDURATION);

	List l = TreeSearchBetween(db->byTimeRange, dummyLower, dummyUpper);

	RecordFree(dummyLower);
	RecordFree(dummyUpper);

	return l;
}

/**
 * Searches  for  and  returns  the  earliest next flight from the given
 * departure airport, on or after the given (day, hour, min).
 * The returned record must not be freed or modified. 
 * The time complexity of this function must be O(log n).
 */
Record   DbFindNextFlight(FlightDb db, char *departureAirport, 
                          int day, int hour, int min) {
	Record dummy = RecordNew(MINCHAR, departureAirport, MINCHAR, day, 
	hour, min, MINDURATION);

	Record n = TreeNext(db->byNext, dummy);

	RecordFree(dummy);
	
	return n;
}

