CXX = g++
CXXFLAGS = -std=c++17 -Wall
INCLUDES = -I/opt/homebrew/opt/openjdk@17/include

OBJS = main.o playlist.o ratingtree.o
TARGET = PlayWise

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp playlist.hpp ratingtree.hpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c main.cpp

playlist.o: playlist.cpp playlist.hpp
	$(CXX) $(CXXFLAGS) -c playlist.cpp

ratingtree.o: ratingtree.cpp ratingtree.hpp
	$(CXX) $(CXXFLAGS) -c ratingtree.cpp

clean:
	rm -f *.o $(TARGET)
