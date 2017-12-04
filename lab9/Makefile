
CMP = g++
MAIN = crossword
CLASS = cwBoard
EXEC = crossword

$(EXEC): $(MAIN).o $(CLASS).o
	$(CMP) $(MAIN).o $(CLASS).o -std=c++11 -o $(EXEC)

$(MAIN).o: $(CLASS).h $(MAIN).cpp
	$(CMP) -c -std=c++11 $(MAIN).cpp

$(CLASS).o: $(CLASS).h $(CLASS).cpp
	$(CMP) -c -std=c++11 $(CLASS).cpp

clean:
	rm *.o
	rm $(EXEC)

