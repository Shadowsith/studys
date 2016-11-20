#include<iostream>
#include<string>
#include<math.h>

//#include "functions.h"

enum rescode {
	OK,
	ERR,
};

float betweenvalue;

int valueout() {
	std::cout << betweenvalue << std::endl;
	return OK;
}

int main(void) {

int chooseop;
//float betweenvalue;
float a;
float b;
bool check = true;

std::cout << "Willkommen bei meinem kleinen C++ Taschenrechner!" << std::endl;
std::cout << "Du kannst hier zwei Zahlen:" << std::endl;
std::cout << "Addieren (1)\nSubtrahieren (2)\nMultiplizieren (3)\nDividieren (4)" << std::endl;
std::cout << "Potenzieren (5)\nRadizieren (6)" << std::endl;

std::cout << "Gebe zunächst zwei Werte a und b an und danach wie sie verrechnet werden sollen" << std::endl;

while(!(std::cin >> a >> b)) {
std::cin.clear();
std::cin.ignore(1000, '\n');
std::cout <<  "Wert war keine Zahl!" << std::endl;
}


//std::cout << "Wähle nun eine Funktion von oben (bitte nur die Nummer eingeben)!" << std::endl;
//readInt(chooseop);
//std::cin >> chooseop;

//Eigentlicher Taschenrechner

char further;
int newop;


do {
std::cout << "Wähle 1 (a und b verechnen), 2 um weiterzurechnen, 3 um neue Werte einzugeben\n" << std::endl;
std::cin >> chooseop;
if ( chooseop == 1 && check == true  ) {
     
       std::cout << "Du kannst jetzt weitere Berechnungen durchführen" << std::endl;
       std::cout << "Wähle nun eine Berechnung Add (1) Sub (2) Mult (3) Div (4) Pot (5) Rad (6)" << std::endl;
       std::cin >> newop;
       switch (newop) {
       case 1:
       betweenvalue = a+b;
       std::cout << "Das Ergebnis ist: " << betweenvalue << std::endl;
       break;
       case 2:
       betweenvalue = a-b;
       std::cout << "Das Ergebnis ist: " << betweenvalue << std::endl;
       break;
       case 3:
       betweenvalue = a*b;
       std::cout << "Das Ergebnis ist: " << betweenvalue << std::endl;
       break;
       case 4:
       betweenvalue = a/b;
       std::cout << "Das Ergebnis ist: " << betweenvalue << std::endl;
       break;
       case 5:
       betweenvalue = pow(a,b);
       std::cout << "Das Ergebnis ist: " << betweenvalue << std::endl;
       break;
       case 6:
       betweenvalue = pow(a,1/b);
       std::cout << "Das Ergebnis ist: " << betweenvalue << std::endl;
       break;
       default: 
       std::cout << "Falsche Eingabe!" << std::endl;
       break;
       }   
       
       }
       else if (chooseop == 2) {
           std::cout << "Du kannst jetzt weitere Berechnungen durchführen" << std::endl;
            std::cout << "Wähle nun eine Berechnung Add (1) Sub (2) Mult (3) Div (4) Pot (5) Rad (6)" << std::endl;
            std::cin >> newop;
            std::cout << "Wähle nun eine Zahl mit der du das bisherige Ergebnis verrechnen kannst" << std::endl;
            std::cin >> a;
            switch (newop) {
            case 1:
            betweenvalue += a;
            std::cout << "Das Ergebnis ist: " << betweenvalue << std::endl;
            break;
            case 2:
            betweenvalue -= a;
            std::cout << "Das Ergebnis ist: " << betweenvalue << std::endl;
            break;
            case 3:
            betweenvalue *= a;
            std::cout << "Das Ergebnis ist: " << betweenvalue << std::endl;
           break;
            case 4:
            betweenvalue /= a;
            std::cout << "Das Ergebnis ist: " << betweenvalue << std::endl;
            break;
            case 5:
            betweenvalue = pow(betweenvalue,a);
            std::cout << "Das Ergebnis ist: " << betweenvalue << std::endl;
            break;
            case 6:
            betweenvalue += pow(betweenvalue,1/a);
            break;
            std::cout << "Das Ergebnis ist: " << betweenvalue << std::endl;
            default: 
            std::cout << "Falsche Eingabe!" << std::endl;
            break;
            }   
            }
       else if (chooseop == 3) {
            betweenvalue = 0;
            a = 0;
            b = 0;
            std::cout << "Bitte neue Werte für a und b eingeben" << std::endl;
            while(!(std::cin >> a >> b)) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout <<  "Wert war keine Zahl!" << std::endl;
            }
            }
            else {
	        check = false;
	        }

  } 
while( check == true );

return OK;
}

