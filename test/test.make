#
INCLUDE=../../1-cpp/Seasons/Seasons/include
FLAGS="-std=c++11"

OctoberPath=C:/Source/1-cpp/Seasons/Seasons/src/Moderate/October

Objects=test.o String.o
LIBS= October.a
LIBObjects=String.o
LIBSrc="$(OctoberPath)/String.cpp"
LIBPATH=C:/Source/gcc/test

test,make : test.exe


test.exe: $(Objects)
	c++ $(Objects)   -municode -o test.exe
	
test.o: test.cpp $(INCLUDE)/October/BTree.h $(INCLUDE)/October/Stack.h $(INCLUDE)/October/ArrayList.h $(INCLUDE)/October/String.h
	c++ -c -I $(INCLUDE) $(FLAGS) test.cpp

	
String.o : $(OctoberPath)/String.cpp $(INCLUDE)/October/String.h
	c++ -c -I $(INCLUDE) $(FLAGS) $(OctoberPath)/String.cpp -o $@
	

clean:
	rm test.exe string.o test.o
	
