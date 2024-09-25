How to run my program:
I made a makefile
Use these commands:
make
./my_program fileName (1 or 2)


------------------------------------------
Description of classes and hierarchies:

Simulation Class: is abstract.
Is the parent class of: ExpressLaneSimulation and OneWaitingLineSimulation

Event Class: is abstract.
Is the parent class of: ArrivalEvent, StartServiceEvent, and CompleteServiceEvent

ListItem Class: is an abstract class that is the parent class of classes that will be stored in the
generic Queue.
Is the parent class of: Event(including it subclasses), and customer

Generic Queue Class: is a generic Queue that holds a node type.
This GenericQueue could be of two forms: PriorityQueue and Queue(FIFO).

Node Class: is a class that holds a ListItem type.
