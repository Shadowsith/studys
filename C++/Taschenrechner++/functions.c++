#include<iostream>
#include<string>
#include<math.h>

#include "main.h"

void betweenvalue;
std::string further;
int newop;

int add1() {
  std::cout << "Addition! (a+b)" << std::endl;
  betweenvalue = a+b;
  std::cout << betweenvalue << std::endl;
  std::cout << "Willst du mit dem Ergebnis weiterrechnen?" << std::endl;
  std::cout << "Drücke j für Ja und n für nein" << std::endl;
  std::cin >> further;
  if ( further.compare("j") == 0 ) {
       std::out << "Du kannst jetzt weitere Berechnungen durchführen" << std::endl;
       std::cin >> a;
       std::out << "Wähle nun eine Berechnung Add (1) Sub (2) Mult (3) Div (4) Pot (5) Rad (6)" << std::endl;
       std::cin >> newop;
       switch (newop) {
       case 1:
       betweenvalue += a;
       std::cout << betweenvalue << std::endl;
       break;
       case 2:
       betweenvalue -= a;
       std::cout << betweenvalue << std::endl;
       break;
       case 3:
       betweenvalue *= a;
       std::cout << betweenvalue << std::endl;
       break;
       case 4:
       betweenvalue /= a;
       std::cout << betweenvalue << std::endl;
       break;
       case 5:
       betweenvalue = pow(betweenvalue,a);
       std::cout << betweenvalue << std::endl;
       break;
       case 6:
       betweenvalue += pow(betweenvalue,1/a);
       std::cout << betweenvalue << std::endl;
       break;
       default: 
       break;
       }
    }





  }




