#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <inttypes.h>
#include <math.h>
#include <time.h>

int main()
{
  struct timespec spec;
  clock_gettime(CLOCK_REALTIME, &spec);
  printf("helloworld Process started at: %ld.%ld\n", spec.tv_sec, spec.tv_nsec);

	FILE *f = fopen("test_file.txt", "w");
  if (f == NULL)
  {
      printf("Error opening file!\n");
      exit(1);
  }
  const char *text = "Hello World!";
  printf("Writing to file, first event, second exec");
  fprintf(f, "All I can say is %s\n", text);
  fclose(f);
}
