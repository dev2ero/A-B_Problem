#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"

char *target;

void
find(char *path)
{
	int fd;
	struct stat st;
	struct dirent de;

	char cur_path[128], *p;

	if((fd = open(path, 0)) < 0){
		fprintf(2, "find: cannot open %s\n", path);
		return;
	}

	if(fstat(fd, &st) < 0){
		fprintf(2, "find: cannot stat %s\n", path);
		close(fd);
		return;
	}

	if(st.type == T_DIR){
		strcpy(cur_path, path);
		p = cur_path + strlen(cur_path);
		*p++ = '/';
		while(read(fd, &de, sizeof(de)) == sizeof(de)){
			if(de.inum == 0) continue;
			memmove(p, de.name, DIRSIZ);
			p[DIRSIZ]=0;
			if(strcmp(de.name, target) == 0) {
				printf("%s\n", cur_path);
				continue;
			}
			if(stat(cur_path, &st) < 0){
				printf("find: cannot stat %s\n", cur_path);
				continue;
			}
			if(st.type == T_DIR && strcmp(de.name, ".") && strcmp(de.name, "..")) {
				find(cur_path);
			}
		}
	}
	close(fd);
	return;
}


int
main(int argc, char* argv[])
{
	if(argc < 3) {
		printf("ERROR\n");
		exit(0);
	}
	target = argv[2];
	find(argv[1]);
	exit(0);
}
