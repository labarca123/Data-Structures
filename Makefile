CXX = g++
INC = -I.
OPC = -g -c
all: list.exe

list.exe: list_test.o list_char.o
	$(CXX) -o $@ $^

list_char.o: list_char.cpp
	$(CXX) $(INC) $(OPC) $<

list_test.o: list_test.cpp
	$(CXX) $(INC) $(OPC) $<

clean:
	rm *.o list.exe