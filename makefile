CC = gcc
CFLAGS = -g -lm
DEPS = ./src/tfidf.h ./src/build_file_name.h ./src/parse_file.h ./src/randomize.h ./src/count_50_words.h ./src/interpreter.h ./src/build_network.h ./src/runner.h ./src/randominitnn.h
OBJ = ./src/runner.o ./src/tfidf.o ./src/build_file_name.o ./src/parse_file.o ./src/randomize.o ./src/count_50_words.o ./src/interpreter.o ./src/build_network.o ./src/randominitnn.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
runner: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean
clean:
	-rm $(OBJ) runner
