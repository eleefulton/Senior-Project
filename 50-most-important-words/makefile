CC = gcc
CFLAGS = -g -lm
DEPS = build_name.h parse_file.h tfidf.h
OBJ = runner.o tfidf.o build_name.o parse_file.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
runner: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean
clean:
	-rm $(OBJ) runner
