
CMP = g++
MAIN = 
CLASS = 
EXEC = runit

$(EXEC): $(MAIN).o $(CLASS).o
	$(CMP) $(MAIN).o $(CLASS).o -o -std=c++11 $(EXEC)

$(MAIN).o: $(CLASS).h $(MAIN).cpp
	$(CMP) -c -std=c++11 $(MAIN).cpp

$(CLASS).o: $(CLASS).h $(CLASS).cpp
	$(CMP) -c -std=c++11 $(CLASS).cpp

clean:
	rm *.o
	rm $(EXEC)

