#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{

  int first_exec_file_desc = open("first_exec_event_file.txt", O_RDWR);
  printf("Second event from first exec proc\n");
  FILE *f1 = fopen("first_exec_event_file.txt", "w");
  if (f1 == NULL)
  {
      printf("Error opening file!\n");
      exit(1);
  }
  printf("Third event from first exec proc\n");
  const char *text = "This is the first event for the first exec";
  fprintf(f1, "Writing a filemod %s\n", text);
  fclose(f1);
  sleep(5);
  printf("Second exec from fork proc\n");
	char *argv[] = { "./helloworld", NULL };
	char *envp[] = { NULL	};
	execve(argv[0], &argv[0], envp);
	exit(0);

	return 0;

}
