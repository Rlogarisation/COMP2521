
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Fb.h"
#include "Map.h"
#include "Queue.h"

#define MAX_PEOPLE 128

struct fb {
    int   numPeople;

    char *names[MAX_PEOPLE]; // the id of a person is simply the index
                             // that contains their name in this array
    
    Map   nameToId; // maps names to ids
                    // question to think about: why do we have this when
                    // the names array already provides this information?

    bool  friends[MAX_PEOPLE][MAX_PEOPLE];
};

static char *myStrdup(char *s);
static int   nameToId(Fb fb, char *name);

////////////////////////////////////////////////////////////////////////

// Creates a new instance of FriendBook
Fb   FbNew(void) {
    Fb fb = malloc(sizeof(*fb));
    if (fb == NULL) {
        fprintf(stderr, "Insufficient memory!\n");
        exit(EXIT_FAILURE);
    }

    fb->numPeople = 0;
    fb->nameToId = MapNew();

    for (int i = 0; i < MAX_PEOPLE; i++) {
        for (int j = 0; j < MAX_PEOPLE; j++) {
            fb->friends[i][j] = false;
        }
    }

    return fb;
}

void FbFree(Fb fb) {
    for (int i = 0; i < fb->numPeople; i++) {
        free(fb->names[i]);
    }

    MapFree(fb->nameToId);
    free(fb);
}

bool FbAddPerson(Fb fb, char *name) {
    if (fb->numPeople == MAX_PEOPLE) {
        fprintf(stderr, "error: could not add more people\n");
        exit(EXIT_FAILURE);
    }

    if (!MapContains(fb->nameToId, name)) {
        int id = fb->numPeople++;
        fb->names[id] = myStrdup(name);
        MapSet(fb->nameToId, name, id);
        return true;
    } else {
        return false;
    }
}

bool FbHasPerson(Fb fb, char *name) {
    return MapContains(fb->nameToId, name);
}

List FbGetPeople(Fb fb) {
    List l = ListNew();
    for (int id = 0; id < fb->numPeople; id++) {
        ListAppend(l, fb->names[id]);
    }
    return l;
}

bool FbFriend(Fb fb, char *name1, char *name2) {
    int id1 = nameToId(fb, name1);
    int id2 = nameToId(fb, name2);
    assert(id1 != id2);

    if (!fb->friends[id1][id2]) {
        fb->friends[id1][id2] = true;
        fb->friends[id2][id1] = true;
        return true;
    } else {
        return false;
    }
}

bool FbIsFriend(Fb fb, char *name1, char *name2) {
    int id1 = nameToId(fb, name1);
    int id2 = nameToId(fb, name2);
    return fb->friends[id1][id2];
}

List FbGetFriends(Fb fb, char *name) {
    int id1 = nameToId(fb, name);
    
    List l = ListNew();
    for (int id2 = 0; id2 < fb->numPeople; id2++) {
        if (fb->friends[id1][id2]) {
            ListAppend(l, fb->names[id2]);
        }
    }
    return l;
}

int  FbNumFriends(Fb fb, char *name) {
    int id1 = nameToId(fb, name);
    
    int numFriends = 0;
    for (int id2 = 0; id2 < fb->numPeople; id2++) {
        if (fb->friends[id1][id2]) {
            numFriends++;
        }
    }
    return numFriends;
}

////////////////////////////////////////////////////////////////////////
/*
Implement the FbUnfriend() function in Fb.c, 
which takes the names of two people, 
and unfriends them if they are friends. 
The function should return true if the people were friends 
and were successfully unfriended, 
and false if the two people were not friends to begin with.
*/
bool FbUnfriend(Fb fb, char *name1, char *name2) {
    // Return false if they are not friends.
    if (!FbIsFriend(fb, name1, name2)) {
        return false;
    }
    else {
        int id1 = nameToId(fb, name1);
        int id2 = nameToId(fb, name2);
        // They are not the same person
        assert(id1 != id2);
        // They are friends
        assert(fb->friends[id1][id2] == true);
        // Unfriend
        fb->friends[id1][id2] = false;
        fb->friends[id2][id1] = false;
        return true;
    }
}

/*
Implement the FbMutualFriends() function in Fb.c, 
which takes the names of two people, 
and returns a list of all their mutual friends. 
A person is a mutual friend of two people 
if that person is friends with both of those people. 
*/

List FbMutualFriends(Fb fb, char *name1, char *name2) {
    List l = ListNew();
    // Assume name1 and name2 can be or not be friends
    int id1 = nameToId(fb, name1);
    int id2 = nameToId(fb, name2);
    int counter = 0;
    while (counter < fb->numPeople) {
        // Cannot be themself, and cannot be each other.
        if (counter != id1 && counter != id2 && 
        fb->friends[id1][counter] == true &&
        fb->friends[id1][counter] == fb->friends[id2][counter]) {
            ListAppend(l, fb->names[counter]);
        }
        counter++;
    }
    return l;
}

/*
Implement the FbFriendRecs1() function in Fb.c, 
which takes the name of a person and generates 
and prints friend recommendations for them. 
This function should only recommend people 
who are friends of friends of the person. 
In other words, it should only recommend people who share 
at least one mutual friend with the person. 
Obviously, it should not recommend someone who is already the person's friend.
*/
void FbFriendRecs1(Fb fb, char *name) {
    int id = nameToId(fb, name);
    printf("\n%s's friend recommendations\n", name);
    for (int counter = 0; counter < fb->numPeople; counter++) {
        // Not themself, not any existing friends.
        if (counter != id && fb->friends[id][counter] == false) {
            int size = ListSize(FbMutualFriends(fb, name, fb->names[counter]));
            if (size != 0) {
                printf("\t%-20s%4d mutual friends\n", fb->names[counter], size);
            }
        }
    }
}

////////////////////////////////////////////////////////////////////////
// Optional task

void FbFriendRecs2(Fb fb, char *name) {
    // TODO: Add your code here
}

////////////////////////////////////////////////////////////////////////
// Helper Functions

static char *myStrdup(char *s) {
    char *copy = malloc((strlen(s) + 1) * sizeof(char));
    if (copy == NULL) {
        fprintf(stderr, "Insufficient memory!\n");
        exit(EXIT_FAILURE);
    }
    return strcpy(copy, s);
}

// Converts a name to an ID. Raises an error if the name doesn't exist.
static int nameToId(Fb fb, char *name) {
    if (!MapContains(fb->nameToId, name)) {
        fprintf(stderr, "error: person '%s' does not exist!\n", name);
        exit(EXIT_FAILURE);
    }
    return MapGet(fb->nameToId, name);
}

