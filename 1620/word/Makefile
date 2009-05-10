
wtest: wtest.o word.o
	g++ -Wall $^ -o $@

word.o: word.cpp word.h
	g++ -Wall -c $<

wtest.o: wtest.cpp word.h
	g++ -Wall -c $<

clean:
	-rm -f *.o wtest
