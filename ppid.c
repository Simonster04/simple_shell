#include <stdio.h>
#include <unistd.h>

/**
 * main - PPID
 *
 * Return: Always 0.
 */
int main(void)
{
    pid_t ppid;

    ppid = getppid(); /* ID of parent of current process */
    printf("%u\n", ppid);
    return (0);
}
