CXX=g++
CXXFLAGS=-Wall -g
SRCS = card.cpp deck.cpp warplayer.cpp war.cpp
OBJ = $(SRCS:.cpp=.o)

all: war

war: $(OBJ)
	$(CXX) $(CXXFLAGS) -o war $(OBJ)
.cpp.o:
	$(CXX) $(CXXFLAGS) -c $<

card.o: card.h

deck.o: deck.h card.h

warplayer.o: warplayer.h card.h

war.o: deck.h card.h warplayer.h

clean:
	rm -f *.o *~
