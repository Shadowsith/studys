#include <stdio.h>

int main(void) {

char input[9];
int  savechar[9];
int  ctoi[9];
int  count[9] = {7,3,1,7,3,1,7,3,1};
int  nullascii = 48;
int  asciinine = 57;
int  asciiAto10 = 55;
int  sum;

printf("Bitte geben Sie Ihre Ausweisnummer ein\n");
fflush(stdout);

scanf("%s",input);

while ( getchar() != '\n');

for (int inc = 0; inc <= 8; ++inc) {

savechar[inc] = input[inc];

if ( savechar[inc] >= nullascii && savechar[inc] <= asciinine) {

ctoi[inc] = (input[inc] - nullascii)*count[inc];
}
else {

ctoi[inc] = (input[inc] - asciiAto10)*count[inc];
}

}

for (int i = 0; i <= 8; ++i) {
sum += ctoi[i];
}

//sum = ctoi[0]+ctoi[1]+ctoi[2]+ctoi[3]+ctoi[4]+ctoi[5]+ctoi[6]+ctoi[7]+ctoi[8];

//printf("Berechnungsüberprüfung: %d + %d + %d + %d + %d + %d
printf("Gesammtsumme %d\n",sum);

return 0;
}
