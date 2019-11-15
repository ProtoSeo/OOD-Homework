.SUFFIXES: .cpp .o

OBJECTS = Integer.o Float.o Complex.o
# 만들 object 파일들 지정
TEST_FILE = test.o $(OBJECTS)
# 실행파일을 만들 때 필요한 모든 object 파일 지정
CXX = g++
# build 도구 지정
TEST = test
# 실행 파일명
$(TEST) :$(TEST_FILE)
		$(CXX) -o $(TEST) $(TEST_FILE)

# 실행파일 : 사용될 object
# tab 후 빌드도구 -o 실행파일 사용될 object

clean : 
	rm -rf $(TEST) $(TEST_FILE)
# make 결과 생성된 파일 모두 제거

test.o : test.cpp
Integer.o : Integer.cpp
Float.o : Float.cpp
Complex.o : Complex.cpp
