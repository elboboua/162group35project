#makefile

CXXFLAGS = -std=c++0x

SRCS = main.cpp Board.cpp
OBJS = main.o Board.o
HEADERS = Board.hpp


output: $(OBJS) $(HEADERS)
	g++ $(OBJS)  -o output

$(OBJS): $(SRCS) $(HEADERS)
	g++ $(CXXFLAGS) -c $(@:.o=.cpp)

clean:
	rm *.o output
