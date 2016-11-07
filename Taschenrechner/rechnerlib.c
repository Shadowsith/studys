#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include "taschenrechner.h"

int main(void) {

float a, b, c, d, e, f, g, h;
scanf("%f %f", &g, &h);

a = add(g,h);
printf("%f\n", a);

b = sub(g,h);
printf("%f\n", b);

return 0;
}
