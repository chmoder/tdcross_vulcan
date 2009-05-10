
wargame: wargame.o card.o queue.o
	g++ -Wall $^ -o $@

queue.o: queue.cpp queue.h
	g++ -Wall -c $<

card.o: card.cpp card.h
	g++ -Wall -c $<

wargame.o: wargame.cpp queue.h card.h
	g++ -Wall -c $<

clean:
	-rm -f *.o wargame
