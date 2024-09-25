
# Compiler
CXX = g++
# Compiler flags
CXXFLAGS = -std=c++11
# Source files
SRCS = main.cpp ListItem.cpp GenericQueue.cpp Queue.cpp Customer.cpp  Node.cpp \
PriorityQueue.cpp Simulation.cpp Event.cpp \
ArrivalEvent.cpp OneWaitingLineSimulation.cpp StartServiceEvent.cpp CheckoutLane.cpp \
CompleteServiceEvent.cpp ExpressLaneSimulation.cpp
# Object files
OBJS = $(SRCS:.cpp=.o)
# Executable name
EXEC = my_program

# Default target
all: $(EXEC)

# Rule for linking object files into executable
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(EXEC)

# Rule for compiling source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(OBJS) $(EXEC)