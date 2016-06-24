CXX=g++
CXXFLAGS=-Wall -g
SRCS = action.cpp moveaction.cpp moneyaction.cpp player.cpp gotoaction.cpp test_action.cpp
OBJ = $(SRCS:.cpp=.o)

all: test_action

test_action: $(OBJ)
	$(CXX) $(CXXFLAGS) -o test_action $(OBJ)
.cpp.o:
	$(CXX) $(CXXFLAGS) -c $<

action.o: action.h

moveaction.o: moveaction.h action.h

moneyaction.o: moneyaction.h action.h player.h

gotoaction.o: gotoaction.h action.h

player.o: player.h

test_action.o: action.h moveaction.h moneyaction.h player.h gotoaction.h

clean:
	rm -f *.o *~