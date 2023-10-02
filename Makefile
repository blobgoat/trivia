CC=g++
CFLAGS=-g -I.
DEPS = question.hpp quiz.hpp
OBJ = main.o question.o quiz.o


%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

run: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm $(OBJ) run *~