CC=gcc
CC_FLAGS=-g

main.exe: main.c
	$(CC) $^ -o $@ $(CC_FLAGS)