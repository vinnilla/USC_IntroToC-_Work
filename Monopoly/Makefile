CXX=g++
CXXFLAGS=-Wall -g
SRCS = space.cpp player.cpp bank.cpp card.cpp gameboard.cpp monopoly.cpp
OBJ = $(SRCS:.cpp=.o)

all: monopoly

monopoly: $(OBJ)
	$(CXX) $(CXXFLAGS) -o monopoly $(OBJ)
.cpp.o:
	$(CXX) $(CXXFLAGS) -c $<

player.o: player.h

space.o: space.h

card.o: card.h

gameboard.o: gameboard.h player.h space.h

monopoly.o: space.h player.h bank.h card.h gameboard.h

clean:
	rm -f *.o *~