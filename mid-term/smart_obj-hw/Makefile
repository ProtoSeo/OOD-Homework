.SUFFIXES: .cpp .o
# .cpp와 .o파일을 다룰 것임을 표기
OBJECTS = shared_ref.o student.o weak_pointer.o human.o smart_obj.o 
# compile할 object파일들 설정
TEST_FILE = test.o $(OBJECTS)
# compile할 테스트코드의 object파일을 포함한 object 파일들 설정
CXX = g++
# CXX 설정
TEST = test
# 실행파일 이름 설정
$(TEST) : $(TEST_FILE)
		$(CXX) -o $(TEST) $(TEST_FILE)


#실행파일 : 컴파일에 사용될 object파일들
#  (탭으로 띄운 후) 컴파일 명령어 사용
clean:
	rm -rf $(TEST) $(TEST_FILE)

# clean은 make 결과 생성된 파일들 모두 삭제
test.o : test.cpp
shared_ref.o : shared_ref.cpp
weak_pointer.o : weak_pointer.cpp
smart_obj.o : smart_obj.cpp
student.o : student.cpp
human.o : human.cpp


# 컴파일하기 위해 필요한 파일들 설정
