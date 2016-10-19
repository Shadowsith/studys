#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  char Name[100];

  printf("Gebe deinen Spielername ein: \n");
  scanf("%s", Name);
  printf("Hallo %s, Willkommen beim Testadventure \n", Name);
  printf("Wähle bitte eine Spielerklasse aus \n");
  printf("Krieger (k) \n Bogenschütze (b)\n Magier (m)\n");
  
  
}

