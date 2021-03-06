#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h>
#include <inttypes.h>
#include <math.h>
#include <time.h>

int main()
{
  struct timespec spec;
  clock_gettime(CLOCK_REALTIME, &spec);
  printf("execloader Process started at: %ld.%ld\n", spec.tv_sec, spec.tv_nsec);

  FILE *f1 = fopen("first_exec_event_file.txt", "w");
  if (f1 == NULL)
  {
      printf("Error opening file!\n");
      exit(1);
  }
  printf("First event from first exec proc\n");
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
