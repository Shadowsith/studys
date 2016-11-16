#include<iostream>
#include<string>
#include<math.h>

enum rescode {
	OK,
	ERR,
};

float betweenvalue = 0;

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


std::cout << "Wähle nun eine Funktion von oben (bitte nur die Nummer eingeben)!" << std::endl;
//readInt(chooseop);
//std::cin >> chooseop;

//Eigentlicher Taschenrechner

std::string further;

do {
std::cin >> chooseop;
if ( chooseop == 1 && check == true  ) {
     std::cout << "Addition! (a+b)" << std::endl;
     betweenvalue = a+b;
     std::cout << betweenvalue << std::endl;
   }
   else if (chooseop == 2) {
            std::cout << "Subtraktion! (a-b)" << std::endl;
	        betweenvalue = a-b;
	        valueout();
	        }
	        else if ( chooseop == 3) {
	        std::cout << "Multiplikation! (a*b)" << std::endl;
	        betweenvalue = a*b;
	        valueout();
            std::cout << "Willst du mit dem Ergebnis weiterrechnen?" << std::endl;
            std::cout << "Drücke j für Ja und n für nein" << std::endl;
            std::cin >> further;
            if (
	        }
	        else if ( chooseop == 4) {
	        std::cout << "Division! (a/b)" << std::endl;
	        betweenvalue = a/b;
	        valueout();
	        }
	        else if (chooseop == 5) {
	        std::cout << "Potenzieren! (a^b)" << std::endl;
	        betweenvalue = pow(a,b);
	        valueout();
	        }
	        else if (chooseop == 6) {
	        std::cout << "Radizieren! (Wurzel b von a)" << std::endl;
	        betweenvalue = pow(a,1/b);
	        valueout();
	        }
	        else {
	        check = false;
	        }

  } 
while( check == true );

return OK;
}

