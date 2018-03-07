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

	FILE *f1 = fopen("first_event_file.txt", "w");
	if (f1 == NULL)
  {
      printf("Error opening file!\n");
      exit(1);
  }

	printf("First event from main proc\n");
  const char *text = "This is the first event";
  fprintf(f1, "Writing a filemod %s\n", text);
  fclose(f1);

	sleep(5);
	printf("Forking process\n");
	pid_t fork_pid = fork();
	if (fork_pid == -1)
	{
		perror("fork");
	}
	if (fork_pid == 0)
	{
		FILE *f2 = fopen("first_event_forked_proc_file.txt", "w");
		if (f2 == NULL)
	  {
	      printf("Error opening file!\n");
	      exit(1);
	  }

		printf("First event from forked proc write file\n");
	  const char *text = "This is the first event from forked proc";
	  fprintf(f2, "Writing a filemod %s\n", text);
	  fclose(f2);

		printf("child: %d\n", fork_pid);
		sleep(5);
		printf("First exec from forked proc\n");
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
