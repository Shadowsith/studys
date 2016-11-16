#include<iostream>
#include<string>
#include<math.h>

int readFloat (float a, float b) {

while(!(std::cin >> a >> b)) {
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    std::cout <<  "Wert war keine Zahl!" << std::endl;
    }
}

int readInt (int a) {

while(!(std::cin >> a)) {
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    std::cout <<  "Wert war keine Zahl!" << std::endl;
    }
}

int main(void) {

int chooseop;
float betweenvalue;
float a;
float b;

std::cout << "Willkommen bei meinem kleinen C++ Taschenrechner!" << std::endl;
std::cout << "Du kannst hier zwei Zahlen:" << std::endl;
std::cout << "Addieren (1)\nSubtrahieren (2)\nMultiplizieren (3)\nDividieren (4)" << std::endl;
std::cout << "Potenzieren (5)\nRadizieren (6)" << std::endl;

std::cout << "Gebe zunächst zwei Werte a und b an und danach wie sie verrechnet werden sollen" << std::endl;
readFloat(a, b);

std::cout << "Wähle nun eine Funktion von oben (bitte nur die Nummer eingeben)!" << std::endl;
readInt(chooseop);

do {
if ( chooseoption == 1 ) {
     std::cout << "Addition!" << std::endl;
   }
   else if (chooseoption == 2) {
            std::cout << "Subtraktion!" << std::endl;

   } 
while( chooseoption < 10);

}

