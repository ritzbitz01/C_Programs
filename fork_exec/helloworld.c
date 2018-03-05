#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("HELLO WORLD!\n");
  printf("\n");
  FILE *f = fopen("test_file.txt", "w");
  if (f == NULL)
  {
      printf("Error opening file!\n");
      exit(1);
  }

  const char *text = "Hello World!";
  fprintf(f, "All I can say is %s\n", text);
  fclose(f);
}
