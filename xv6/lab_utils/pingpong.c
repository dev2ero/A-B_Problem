#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char* argv)
{
	int p1[2], p2[2]; 
	pipe(p1); pipe(p2);

	if(fork() == 0){
		char c;
		read(p1[0], &c, 1);
		printf("%d: received ping\n", getpid());
		write(p2[1], "c", 1);
		exit(0);
	} else {
		char cc;
		write(p1[1], "p", 1);
		read(p2[0], &cc, 1);
		printf("%d: received pong\n", getpid());
		exit(0);
	}
}
