CXX = g++
CXXFLAGS = -std=c++11

TARGET = a.out

$(TARGET): main.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^
