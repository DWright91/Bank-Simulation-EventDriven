// Dalton Wright
// CSCI 301 01
// Project #6
// mainBankSimulation.cpp

#include <iostream>
#include <fstream>
#include "Event.h"
#include "SL_PriorityQueue.h"

// Function Prototypes.
bool loadFile(SL_PriorityQueue<Event>& queue, ifstream& file);
bool createDeparture(SL_PriorityQueue<Event>& events);
float calculateAverage(const float& sum, const float& num);
void simulateBankLine(const SL_PriorityQueue<Event>& queue);

// Test Driver.
int main()
{
  ifstream inFile("EventData.txt");
  SL_PriorityQueue<Event> eventQueue;   // Creates priority queue.

  loadFile(eventQueue, inFile);         // Loads file.
  createDeparture(eventQueue);          // Creates departure events.

  try
  {
    simulateBankLine(eventQueue);
  }
  catch (PrecondViolatedExcep e)
  {
    cout << e.what() <<endl;
  }

  return 0;
}

////////////////////////////////////////////////////////////////////////////////
//                        loadFile Function
////////////////////////////////////////////////////////////////////////////////
bool loadFile(SL_PriorityQueue<Event>& queue, ifstream& file)
{
  bool wasOpened = file.is_open();

  int arrivalTime;
  int transactionTime;
  Event newEvent('A', 0);

  while(file >> arrivalTime >> transactionTime)
  {
    newEvent.setEventTime(arrivalTime);
    newEvent.setEventLength(transactionTime);
    queue.add(newEvent);
  }

  return wasOpened;
}

////////////////////////////////////////////////////////////////////////////////
//                       createDeparture Function
////////////////////////////////////////////////////////////////////////////////
bool createDeparture(SL_PriorityQueue<Event>& events)
{
  int time = 0;
  
  Event departureEvent('D',0);
  Event currentEvent;
  SL_PriorityQueue<Event> tempEvents(events); // Copy constructor to another queue,
                                              // creates departure events wothout changing the queue.
                                              // Gives use of remove(), but doesn't change original queue.

  while(tempEvents.isEmpty() != true)
  {
    currentEvent = tempEvents.peek();

    if(time < currentEvent.getEventTime())
    {
      time = currentEvent.getEventTime();
    }

    time += currentEvent.getEventLength();
    departureEvent.setEventTime(time);

    events.add(departureEvent);

    tempEvents.remove();
  }

  return true;
}

////////////////////////////////////////////////////////////////////////////////
//                      calculateAverage Function
////////////////////////////////////////////////////////////////////////////////
float calculateAverage(const float& sum, const float& num)
{
  return (sum/num);
}

////////////////////////////////////////////////////////////////////////////////
//                      simulateBankLine Function
////////////////////////////////////////////////////////////////////////////////
void simulateBankLine(const SL_PriorityQueue<Event>& queue)
{
  SL_PriorityQueue<Event> simulationQueue(queue);
  SL_PriorityQueue<Event> bankLine;
  float numberOfCustomers = 0;
  float waitTime = 0;
  bool tellerIsFree = true;

  while(simulationQueue.isEmpty() != true)
  {
    if(simulationQueue.peek().getEventType() == 'A')
    {
      cout << "Processing an arrival event at time: " << simulationQueue.peek().getEventTime() << endl;

      if(tellerIsFree)
      {
        tellerIsFree = false;
      }
      else
      {
        bankLine.add(simulationQueue.peek());
      }

      numberOfCustomers ++;
      simulationQueue.remove();
    }

    else if(simulationQueue.peek().getEventType() == 'D')
    {
      cout << "Processing a departure event at time: " << simulationQueue.peek().getEventTime() << endl;

      if(!(bankLine.isEmpty()))
      {
        waitTime += simulationQueue.peek().getEventTime() - bankLine.peek().getEventTime();
        bankLine.remove();
      }

      simulationQueue.remove();

      if(bankLine.isEmpty())
      {
        tellerIsFree = true;
      }
    }
  }

  cout << endl;
  cout << "Final Statistics:" << endl;
  cout << "Total number of customers processed: " << numberOfCustomers << endl;
  cout << "Average amount of time spent waiting: " << calculateAverage(waitTime, numberOfCustomers) << endl;
}
