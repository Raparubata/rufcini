CC=gcc
R_INCLUDE_DIRS=include
CC_FLAGS=-g -I$(R_INCLUDE_DIRS)

main: main.c input.c term.c magic.c table.c
	$(CC) $^ -o $@ $(CC_FLAGS)

clean:
	rm main