#include<stdio.h>
#include<string.h>

int main(void)
{
  char name[40];
  int nameLength;
  int i, j;

  printf("Bitte Namen eingeben: ");
  fflush(stdout);
  scanf("%s", &name);

  nameLength = strlen(name);

  for( i = 0; i < nameLength; i++) {
    for ( j = i; j > 0; j--) {
       printf(" ");
    }
    printf("%c\n", name[i]);
  }
  return 0;
}
