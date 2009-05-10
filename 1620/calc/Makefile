Programs: convert calc

convert: convert.o 
	g++ -o convert convert.o

convert.o: convert.cpp tstack.h
	g++ -c convert.cpp

calc: calc.o 
	g++ -o calc calc.o

calc.o: calc.cpp tstack.h
	g++ -c calc.cpp

clean:
	-rm -f *.o 
