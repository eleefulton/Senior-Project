CC = gcc
CFLAGS = -g -lm
DEPS = build_name.h parse_file.h
OBJ = tfidf.o build_name.o parse_file.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
tfidf: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean
clean:
	-rm $(OBJ) tfidf
