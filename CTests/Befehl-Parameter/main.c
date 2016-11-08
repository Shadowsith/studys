#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "befehle.h"

#define OK 0
#define ERR 1

int main(void) {

char cmd[20] = "cmds";
char eingabe[20];

int pcmd = strlen(cmd);
printf("%d", pcmd);

printf("Gebe einen Befehl ein:\n");
printf("Hinweis: Mit cmds lassen sich alle Befehle anzeigen!\n");
fflush(stdout);

//scanf("%s", eingabe);
fgets(eingabe, sizeof(eingabe), stdin);


if ( strcmp(cmd,eingabe) == 0 )
{
  cmds();
}
else
{
  printf("Befehl nicht gefunden!\n");
  return 1;
}
}
