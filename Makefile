#
# Makefile for shell.c
#

shell: aux_func.c loop.c psh_builtins.c psh_functions.c getpath.c main.c
	gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
leaks: aux_func.c loop.c psh_builtins.c psh_functions.c getpath.c main.c
	gcc -g -Wall -Werror -Wextra -pedantic *.c -o hsh && valgrind --leak-check=full --show-leak-kinds=all ./hsh
debug: aux_func.c loop.c psh_builtins.c psh_functions.c getpath.c main.c
	gcc -ggdb -Wall -Werror -Wextra -pedantic *.c -o hsh
clean:
	rm -f hsh
