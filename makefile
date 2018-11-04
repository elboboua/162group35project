#makefile

CXXFLAGS = -std=c++0x
#debugging symbols
CXXFLAGS += -g


SRCS = main.cpp 
SRCS += Board.cpp
SRCS += Game.cpp
SRCS += Ant.cpp
SRCS += Doodlebug.cpp
SRCS += Critter.cpp
SRCS += inputHandler.cpp
SRCS += logger.cpp

OBJS = main.o 
OBJS += Board.o
OBJS += Ant.o
OBJS += Doodlebug.o
OBJS += Critter.o
OBJS += Game.o
OBJS += inputHandler.o
OBJS += logger.o

HEADERS = Board.hpp
HEADERS += Game.hpp
HEADERS += Critter.hpp
HEADERS += Ant.hpp
HEADERS += Doodlebug.hpp
HEADERS += inputHandler.cpp

output: $(OBJS) $(HEADERS)
	g++ $(OBJS) ${CXXFLAGS}  -o output

$(OBJS): $(SRCS) $(HEADERS)
	g++ $(CXXFLAGS) -c $(@:.o=.cpp)

clean:
	-rm $(OBJS) output
