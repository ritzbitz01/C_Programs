#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{
	pid_t pid = getpid();
	printf("PID: %d\n", pid);

	pid_t fork_pid = fork();
	if (fork_pid == -1)
	{
		perror("fork");
	}
	if (fork_pid == 0)
	{
		int file_desc = open("test_file.txt", O_RDWR);

		printf("child: %d\n", fork_pid);
		char *argv[] = { "./execloader", NULL };
		char *envp[] = { NULL	};
		execve(argv[0], &argv[0], envp);
		exit(0);
	}
	if (fork_pid > 0)
	{
		printf("parent: %d\n", fork_pid);
 	}
	return 0;

}
