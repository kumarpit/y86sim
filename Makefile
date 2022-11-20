main: main.cpp y86.o utils.o
	g++-12 main.cpp y86.o utils.o -o main

y86.o: y86.cpp y86.h
	g++-12 -c y86.cpp

utils.o: utils.cpp utils.h
	g++-12 -c utils.cpp

clean:
	rm *.o output *.out