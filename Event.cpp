// Dalton Wright
// CSCI 301 01
// Project #6
// Event.cpp

#include "Event.h"

////////////////////////////////////////////////////////////////////////////////
//                        Default Copy Constructor
////////////////////////////////////////////////////////////////////////////////
Event::Event()
{
  eventType = ' ';
  eventArrivalTime = 0;
  eventTransactionLength = 0;
}

////////////////////////////////////////////////////////////////////////////////
//                          Copy Constructor
////////////////////////////////////////////////////////////////////////////////
Event::Event(const char& type, const int& time)
{
  eventType = type;
  eventArrivalTime = time;
}

////////////////////////////////////////////////////////////////////////////////
//                         Copy Constructor
////////////////////////////////////////////////////////////////////////////////
Event::Event(const char& type, const int& time, const int& length)
{
  eventType = type;
  eventArrivalTime = time;
  eventTransactionLength = length;
}

////////////////////////////////////////////////////////////////////////////////
//                       Non-Member Functions
////////////////////////////////////////////////////////////////////////////////
bool operator <(const Event& event1, const Event& event2)
{
  if(event1.getEventTime() > event2.getEventTime())
  {
    return true;
  }
  else if(event1.getEventTime() == event2.getEventTime())
  {
    if(event1.getEventType() < event2.getEventType())
    {
      return true;
    }
  }

  return false;
}

////////////////////////////////////////////////////////////////////////////////
bool operator >(const Event& event1, const Event& event2)
{
  if(event1.getEventTime() < event2.getEventTime())
  {
    return true;
  }
  else if (event1.getEventTime() == event2.getEventTime())
  {
    if(event1.getEventType() > event2.getEventType())
    {
      return true;
    }
  }

  return false;
}

////////////////////////////////////////////////////////////////////////////////
bool operator <=(const Event& event1, const Event& event2)
{
  if(event1.getEventTime() > event2.getEventTime())
  {
    return true;
  }
  else if(event1.getEventTime() == event2.getEventTime())
  {
    if(event1.getEventType() <= event2.getEventType())
    {
      return true;
    }
  }

  return false;
}

////////////////////////////////////////////////////////////////////////////////
bool operator >=(const Event& event1, const Event& event2)
{
  if(event1.getEventTime() < event2.getEventTime())
  {
    return true;
  }
  else if(event1.getEventTime() == event2.getEventTime())
  {
    if(event1.getEventType() >= event2.getEventType())
    {
      return true;
    }
  }

  return false;
}

////////////////////////////////////////////////////////////////////////////////
bool operator ==(const Event& event1, const Event& event2)
{
  if(event1.getEventTime() == event2.getEventTime() && event1.getEventType() == event2.getEventType() && event1.getEventLength() == event2.getEventLength())
  {
    return true;
  }
  else
  {
    return false;
  }
}

////////////////////////////////////////////////////////////////////////////////
bool operator !=(const Event& event1, const Event& event2)
{
  if(event1.getEventTime() != event2.getEventTime() || event1.getEventType() != event2.getEventType() || event1.getEventLength() != event2.getEventLength())
  {
    return true;
  }
  else
  {
    return false;
  }
}
