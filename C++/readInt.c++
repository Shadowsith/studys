#include<iostream>

int main(void) {
int a;

do {
std::cin >> a;
if (std::cin.fail() ) {
   std::cout << "Einlesen fehlgeschlagen" << std::endl;
} else {
   std::cout << a << std::endl;
   }
   break;
}
while( a != 1);
return 0;
}
