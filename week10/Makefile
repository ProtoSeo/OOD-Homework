.SUFFIXES: .cpp .o

OBJECTS=  bike.o vehicle.o car.o

TEST_FILE = main.o $(OBJECTS)

CXX = g++
TEST = test

$(TEST):$(TEST_FILE)
		$(CXX) -o $(TEST) $(TEST_FILE)

clean:
	rm -rf $(TEST) $(TEST_FILE)

main.o : main.cpp
bike.o : bike.cpp
car.o : car.cpp
vehicle.o : vehicle.cpp
