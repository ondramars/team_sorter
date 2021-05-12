CXX = g++
CPP_VER = -std=c++14
CFLAGS = -Wall -pedantic

all: program

program: person.o team.o assigner.o team_sorter.o 
	$(CXX) -o program person.o team.o assigner.o team_sorter.o 

team_sorter.o: team_sorter.cpp assigner.cpp assigner.h team.h person.h
	$(CXX) -c $(CPP_VER) team_sorter.cpp

person.o: person.cpp person.h
	$(CXX) -c $(CPP_VER) person.cpp

team.o: team.cpp team.h person.h 
	$(CXX) -c $(CPP_VER) team.cpp

assigner.o: assigner.cpp assigner.h team.h person.h
	$(CXX) -c $(CPP_VER) assigner.cpp

clean:
	rm -f core *.o
	rm $(USER)

run: $(USER)
	./$(USER)