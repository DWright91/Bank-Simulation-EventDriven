// Dalton Wright
// CSCI 301 01
// Project #6
// Event.h

#ifndef EVENT_H
#define EVENT_H

class Event
{
  private:
    char eventType;              // To hold event-type: 'A' or 'D'.
    int eventArrivalTime;        // To hold event arrival time.
    int eventTransactionLength;  // To hold event transaction time.
  public:
    // Constructors.
    Event();
    Event(const char& type, const int& time);
    Event(const char& type, const int& time, const int& length);

    // Inline get functions.
    char getEventType() const {return eventType;}
    int getEventTime() const {return eventArrivalTime;}
    int getEventLength() const {return eventTransactionLength;}

    // Inline set functions.
    void setEventType(const char& newEvent) {eventType = newEvent;}
    void setEventTime(const int& time) {eventArrivalTime = time;}
    void setEventLength(const int& time) {eventTransactionLength = time;}
};

// Non-Member Function Prototypes.
bool operator <(const Event& event1, const Event& event2);
bool operator >(const Event& event1, const Event& event2);
bool operator <=(const Event& event1, const Event& event2);
bool operator >=(const Event& event1, const Event& event2);
bool operator ==(const Event& event1, const Event& event2);
bool operator !=(const Event& event1, const Event& event2);

#include "Event.cpp"

#endif
