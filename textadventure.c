#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  char name[100];

  printf("Gebe deinen Spielername ein: \n");
  scanf("%s", name);						//Zuweisung des Spielernamens (String)
  printf("Hallo %s, Willkommen beim Testadventure \n", name);
  printf("Wähle bitte eine Spielerklasse aus \n");
  printf("Krieger (1) \nBogenschütze (2)\nMagier (3)\n");
  int playerclass;						//RPG-Klassendeklaration
  int warrior;
  int archer;
  int mage;
  scanf("%i", &playerclass);
  if ( playerclass == 1)					//Prüfung der RPG-KLasse
  {
   printf("Du hast die Klasse Krieger gewählt!\n");
   playerclass == warrior;
  }
  else
  {
    if( playerclass == 2)
    {
     printf("Du hast die Klasse Bogenschütze gewählt!\n");
    }
     else
     {
      if ( playerclass == 3)
      {
       printf("Du hast die Klasse Magier gewählt! \n");
      }
       else
  	{	
  	 printf("Du hast eine falsche Eingabe getätigt! \n");
 	}
     }
     
   }
  

  
}

