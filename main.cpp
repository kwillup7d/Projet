
#include "Jeu.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv){

int cases = 0;

while ( (cases < 25) || (cases > 80)){
cout << "Combien de cases voulez-vous ? Entrez un nombre entre 25 et 80"<<endl;

cin >> cases;

};
Jeu jeu(cases);

jeu.initialisation();
jeu.jouer();

}
