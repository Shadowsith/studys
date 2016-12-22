#include <stdio.h>
#include <stdlib.h>

int my_strlen(const char* s){
int len;
len = 0;
while (*s != '\0'){
s++;
len++;
}
return len;
}

char* my_strcpy(char *dest, const char *src){
char *d = dest;
while (*src != '\0'){

*d = *src;
d++;
src++;
}
*d = '\0';
return dest;
}

char* my_strncpy(char *dest, const char *src, int n){
char *d = dest;
int i;
i = 0;
while(i < n && *src != '\0'){

*d = *src;
d++; src++; i++;
}

while


int main(void){

char* new;
char* new1;
char hallo[] = "Hallo";
char bye[] = "bye";
new = hallo;
new1 = bye;


printf("%c\n",*new);
printf("%d\n",my_strlen(new));
printf("%s\n",my_strcpy(new,new1));
fflush(stdout);

return 0;
}

