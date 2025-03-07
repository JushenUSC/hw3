#ifndef EVENT_H
#define EVENT_H
#include "wire.h"

struct Event
{
    uint64_t time;
    Wire* wire;
    char state;
};

typedef struct EventLess {
        //write the operator() required to make this a functor that compares Events by time

		//event1 is the child, event2 is the parent
		//if it outputs true then we swap
		bool operator()(const Event* event1, const Event* event2) {
			//so here event1 is the child, and event 2 is parent
			//when event 1 is less than event 2, you swap child with parent, so the smallest values circulate to top
			//creates min heap
			//key is you swap when this is true
			return event1->time < event2->time;
		}
} EventLess;
	
#endif
