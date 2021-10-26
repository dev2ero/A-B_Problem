#include "kernel/types.h"
#include "user/user.h"
#include "kernel/param.h"

#define MAX_LEN 512

char fout[MAX_LEN];
char *p_cargv[MAXARG];

int main(int argc, char *argv[]) {
	if(argc < 2){
		fprintf(2, "argc error\n");
		exit(1);
	}

	for(int i = 0; i < MAX_LEN; i++) {
		char c;
		if( read(0, &c, 1) != 1 || c == '\n')
			break;
		fout[i] = c;
	}

	for(int i = 0; i < argc-1; i++)
		p_cargv[i] = argv[i+1];

	p_cargv[argc-1] = fout;

	int pid = fork();

	if(pid == 0) {
		exec(argv[1], p_cargv); 
		exit(0);
	} else {
		wait(&pid);
		exit(0);
	}
}
