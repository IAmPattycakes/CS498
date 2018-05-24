#include <stdio.h>

int main(void)
{
	printf("Hello world from process ID %ld\n", (long)getpid());
	exit(0);
}

/*
In testing this program, I was unable to get it to do non-sequential PIDs except
for just waiting a little bit for something else to run as a process. This might
have been what was happening, but I wasn't able to recreate the 3 PID difference
that is shown in figure 1.6
*/
