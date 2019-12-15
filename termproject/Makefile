.SUFFIXES: .cpp .o

OBJECTS = Gmap.o pointer.o puyo.o fold.o tree.o cross.o
MAIN = main.o $(OBJECTS)

CXX = g++

TARGET = test

$(TARGET) : $(MAIN)
	$(CXX) -o $(TARGET) $(MAIN)

clean : 
	rm -rf $(MAIN) $(TARGET)

puyo.o : puyo.cpp
map.o : Gmap.cpp
block.o : block.cpp
pointer.o : pointer.cpp
fold.o : fold.cpp
tree.o : tree.cpp
cross.o : cross.cpp
