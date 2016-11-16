#include<iostream>
#include<string>

enum ResCodes { 
    OK,
    ERR,
};

int readInteger (int a) {

do {
std::cin >> a;
if (std::cin.fail() ) {
   std::cout << "Einlesen fehlgeschlagen" << std::endl;
} else {
   std::cout << a << std::endl;
   }
   break;
}
while( a != 0);
}

int main(void) {

    //Begrüßung, Spielername
    std::string playername;
    std::cout << "Willkommen beim Textadventure!" << std::endl;
    std::cout << "Gebe einen Spielernamen ein!" << std::endl;
    std::cout << "Hinweis: Dein Charakter wird später benannt!" << std::endl;
    std::cin >> playername;
    std::cout << "Wunderbar, du bist " << playername << std::endl;

    //Charaktererstellung (später eigene Datei)
    int choosecharname;
    std::string userclass;

    std::cout << "\n" <<  playername << " du kannst nun einen Charakter erstellen!" << std::endl;
//    std::cout << "Wähle zwischen Krieger (1), Schütze (2) und Magier (3)" << std::endl;
//    std::cin >> choosecharname;

    do {
    
    std::cout << "Wähle zwischen Krieger (1), Schütze (2) und Magier (3)" << std::endl;
    std::cin >> choosecharname;

    if (choosecharname == 1) {
        std::cout << "Du hast dich für die Klasse Krieger entschieden!" << std::endl;
        userclass = "Krieger";
        break;
        }
    else if ( choosecharname == 2 ) {
              std::cout << "Du hast dich für die Klasse Schütze entschieden!" << std::endl;
              userclass = "Schütze";
              break;
              }
    else if ( choosecharname == 3) {
              std::cout << "Du hast dich für die Klasse Magier entschieden!" << std::endl;
              userclass = "Magier";
              break;
              }
              else { std::cout << "Falsche Eingabe!\n" << std::endl;}
       }
    while ( readInteger(choosecharname) != 0);
            

 
return OK;
}
