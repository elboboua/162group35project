#makefile

CXXFLAGS = -std=c++0x
#debugging symbols
CXXFLAGS += -g


SRCS = main.cpp 
SRCS += Board.cpp
SRCS += Game.cpp
SRCS += Ant.cpp
SRCS += Critter.cpp
SRCS += inputHandler.cpp
SRCS += Menu.cpp
SRCS += logger.cpp

OBJS = main.o 
OBJS += Board.o
OBJS += Ant.o
OBJS += Critter.o
OBJS += Game.o
OBJS += inputHandler.o
OBJS += Menu.o
OBJS += logger.o

HEADERS = Board.hpp


output: $(OBJS) $(HEADERS)
	g++ $(OBJS) ${CXXFLAGS}  -o output

$(OBJS): $(SRCS) $(HEADERS)
	g++ $(CXXFLAGS) -c $(@:.o=.cpp)

clean:
	-rm $(OBJS) output
