spell_check: list.o word.o tree.o spell_main.o
	g++ -Wall $^ -o $@

tree.o: tree.cpp tree.h
	g++ -Wall -c $<

list.o: list.cpp list.h
	g++ -Wall -c $< 

word.o: word.cpp word.h
	g++ -Wall -c $<

spell_main.o: spell_main.cpp list.h word.h tree.h
	g++ -Wall -c $<

clean:
	-rm -f *.o wfc
