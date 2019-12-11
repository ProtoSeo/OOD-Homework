.SUFFIXES: .cpp .o

OBJECTS = location.o controller.o array_2d.o big_block.o cross_block.o tree_block.o fold_block.o 
MAIN = main.o $(OBJECTS)

CXX = g++

TARGET = test

$(TARGET) : $(MAIN)
	$(CXX) -o $(TARGET) $(MAIN)

clean:
	rm -rf $(MAIN) $(TARGET)
