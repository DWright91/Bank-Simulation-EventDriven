# Bank-Simulation-EventDriven

Purpose: Simulate a bank through the use of event-driven processing using the use of queues.

1). Implement the event-driven simulation of a bank. 

2). A queue of arrival events will represent the line of customers in the bank. 

3). Maintain the arrival events and departure events in a priority queue, sorted by the time of event. Use a link-based implementation for the event list.

4). The input is a text file of arrival and transaction times. Each line of the file contains the arrival time and required transaction time for a customer. The arrival times are ordered by increasing time.
Your program must count customers and keep track of their cumulative waiting time. These statistics are sufficient to compute the average waiting time after the last event has been processed.

-------------------------------------------------------------------------------------------------------------------------------------------------------------
Output:
Display a trace of the events executed and a summary of the computed statistic (total number of the arrivals and average time spent waiting in line). 

For example, if an input file contains the following customer samples:

Arrival time

Transaction time

1

5

2

5

4

5

20

5

22

5

24

5

26

5

28

5

30

5

88

3

then the following output should be produced by your program:

Processing an arrival event at time: 1

Processing an arrival event at time: 2

Processing an arrival event at time: 4

Processing a departure event at time: 6

Processing a departure event at time: 11

Processing a departure event at time: 16

Processing an arrival event at time: 20

Processing an arrival event at time: 22

Processing an arrival event at time: 24

Processing a departure event at time: 25

Processing an arrival event at time: 26

Processing an arrival event at time: 28

Processing an arrival event at time: 30

Processing a departure event at time: 30

Processing a departure event at time: 35

Processing a departure event at time: 40

Processing a departure event at time: 45

Processing a departure event at time: 50

Processing an arrival event at time: 88

Processing a departure event at time: 91

Simulation ends.

Final Statistics:

Total number of customers processed: 10

Average amount of time spent waiting: 5.6
