wfc: list.o word.o main.o
	g++ -Wall $^ -o $@

list.o: list.cpp list.h
	g++ -Wall -c $< 

word.o: word.cpp word.h
	g++ -Wall -c $<

main.o: main.cpp list.h
	g++ -Wall -c $<

clean:
	-rm -f *.o wfc
