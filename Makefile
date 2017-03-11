SRCS:=$(wildcard ./*.cc)
LIBS:=-lpthread
OBJS:=$(patsubst %.cc,%.o, $(SRCS))
CXX:=g++

CXXFLAGES:= -Wall -g -std=c++11

EXE:=main

$(EXE):$(SRCS)
	$(CXX) -o $(EXE) $(SRCS) $(CXXFLAGES) $(LIBS)
