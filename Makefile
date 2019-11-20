#
# Makefile for shell.c
#

all: shell

shell: shell.c str_funcs.c aux_funcs.c tok_exe.c _path.c
	gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
leaks: shell.c str_funcs.c aux_funcs.c tok_exe.c _path.c
	gcc -g -Wall -Werror -Wextra -pedantic *.c -o hsh && valgrind --leak-check=full --show-leak-kinds=all ./hsh
debug: shell.c str_funcs.c aux_funcs.c tok_exe.c _path.c
	gcc -ggdb -Wall -Werror -Wextra -pedantic *.c -o hsh
clean:
	rm -f hsh
