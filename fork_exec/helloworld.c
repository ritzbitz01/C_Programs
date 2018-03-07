#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
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
