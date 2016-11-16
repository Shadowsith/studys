#include <stdio.h>

int main(int a, int b)
{
  printf("Geben Sie Wert a ein! \n");
  scanf("%d", &a);
  printf("Geben Sie Wert b ein! \n");  
  scanf("%d", &b);
  
  if ( a == 0)
  {
    return b;
  }
  while ( b != 0)
  {
    if ( a > b)
    { 
      a = a - b;
    }
    else
    {
      b = b - a;
    }
    printf("a hat den Wert %d, b hat dan Wert %d \n", a, b);
    
  }
  printf("Der größte geminsame Teiler von a und b ist %d \n", a);
  return a;
}
  

