CC = gcc
CFLAGS = -g -lm
DEPS = tfidf.h build_file_name.h parse_file.h randomize.h count_50_words.h interpreter.h build_layers.h
OBJ = runner.o tfidf.o build_file_name.o parse_file.o randomize.o count_50_words.o interpreter.o build_layers.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
runner: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean
clean:
	-rm $(OBJ) runner
