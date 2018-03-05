#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{

	char *argv[] = { "./helloworld", NULL };
	char *envp[] = { NULL	};
	execve(argv[0], &argv[0], envp);
	exit(0);

	return 0;

}
