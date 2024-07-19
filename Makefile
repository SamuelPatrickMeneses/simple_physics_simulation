EXECUTABLE_NAME = bin
LD_INCLUDES=-lm -lGL -lglut -lBox2D -v
COMPILER= g++
SOURCE_LIST=./src/test.cpp ./src/primitiveDraw.cpp ./src/internals.cpp ./src/util.cpp ./src/entities.cpp ./src/keyBuffer.cpp

all: clean run

$(EXECUTABLE_NAME): $(SOURCE_LIST)
	$(COMPILER) $? -o $(EXECUTABLE_NAME) $(LD_INCLUDES)
run: $(EXECUTABLE_NAME)
	./$(EXECUTABLE_NAME)
clean: 
	rm -f ./$(EXECUTABLE_NAME) *.o
