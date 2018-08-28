CC = gcc
CFLAGS = -g -lm
DEPS =
OBJ = interpreter.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
interpreter: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean
clean:
	-rm $(OBJ) interpreter
