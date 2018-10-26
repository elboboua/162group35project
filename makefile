#makefile

CXXFLAGS = -std=c++0x

SRCS = main.cpp Board.cpp Critter.cpp Ant.cpp
OBJS = main.o Board.o Critter.o Ant.o
HEADERS = Board.hpp Critter.hpp Ant.hpp


output: $(OBJS) $(HEADERS)
	g++ $(OBJS)  -o output

$(OBJS): $(SRCS) $(HEADERS)
	g++ $(CXXFLAGS) -c $(@:.o=.cpp)

clean:
	rm *.o output
