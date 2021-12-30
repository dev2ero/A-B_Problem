#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

struct subprocess {
	pid_t pid;
	int stdin;
	int stdout;
	int stderr;
};

void lose(int fd) {
	if (close(fd) == -1) { perror("Could not close pipe end" ); exit(1); }
}

void mk_pipe(int fds[2]) {
	if (pipe(fds) == -1) { perror("Could not create pipe"); exit(1); }
}

void mv_fd(int fd1, int fd2) {
	if (dup2(fd1,  fd2) == -1) { perror("Could not duplicate pipe end"); exit(1); }
		close(fd1);
}

void call(char* argv[], struct subprocess* p) {
	int child_in[2]; int child_out[2]; int child_err[2];
	pipe(child_in); pipe(child_out); pipe(child_err);
	pid_t pid = fork();
	if(pid == 0){
		close(0); close(1); close(2); 
		close(child_in[1]); close(child_out[0]); close(child_err[0]);
		mv_fd(child_in[0], 0); mv_fd(child_out[1], 1); mv_fd(child_err[1], 2);
		char* envp[] = { NULL };
		execve(argv[0], argv, envp);
	} else {
		close(child_in[0]); close(child_out[1]); close(child_err[1]);
		p->pid = pid;
		p->stdin = child_in[1];
		p->stdout = child_out[0];
		p->stderr = child_err[0];
	}
}

int main() {
	
}
