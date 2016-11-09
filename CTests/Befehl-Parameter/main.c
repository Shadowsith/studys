#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "functions.h"

#define OK 0
#define ERR 1

int main(void) {

char cmd[8] = "cmds\n";
char input_t[15] = "input_text\n";
char output_t[15] = "output_text\n";
char end[10] = "endall\n";
char eingabe[20];

printf("Wilkommen!\n");
printf("Hinweis: Mit cmds lassen sich alle Befehle anzeigen!\n");

do
{
 printf("Bitte Befehl eingeben!\n");
 fflush(stdout);
 fgets(eingabe, 20, stdin);
 
 if ( strcmp(cmd, eingabe) == 0 )
  {
   cmds();
  }
  else if ( strcmp(input_t, eingabe) == 0)
       { 
        input_text();
        //continue;
               }
       else if ( strcmp(output_t, eingabe) == 0)
            {
             output_text();
            // continue;
            }
            else if ( strcmp(end,eingabe) == 0 )
                 {
                  endall();
                 }
                  else 
                  {   
                   printf("Befehl nicht gefunden!\n");
                  }


}
while ( strcmp(end, eingabe) != 0);

/* if ( strcmp(cmd, eingabe) == 0 )
  {
   cmds();
   break;
  }
  else if ( strcmp(input_t, eingabe) == 0)
       { 
        input_text();
        continue;
               }
       else if ( strcmp(output_t, eingabe) == 0)
            {
             output_text();
             continue;
            }
            else if ( strcmp(end,eingabe) == 0 )
                 {
                  endall();
                 }
                  else 
                  {   
                   printf("Befehl nicht gefunden!\nBitte neue Eingabe!");
                   fflush(stdout);
                   fgets(eingabe, 20, stdin);
                  }

*/

 return 0;
} 
