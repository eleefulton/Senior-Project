CC = gcc
CFLAGS = -g -lm
DEPS = tfidf.h build_file_name.h parse_file.h randomize.h
OBJ = runner.o tfidf.o build_file_name.o parse_file.o randomize.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
runner: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean
clean:
	-rm $(OBJ) runner
