#include <iostream>
#include <cstdlib>

using namespace std;

//ENONCE :
//  Le nombre mystère
//  Ecrivez un fichier mystery dont la fonction main choisit un nombre entier aléatoire entre 0 et 100
//  Demande à l'utilisateur de proposer un nombre sur l'entrée standard.
//  A chaque tentative, on affiche si le nombre mystère est supérieur, inférieur ou égal.
//  Si le nombre est égal, on affiche le nombre de tentatives et on arrête le programme. 
//  On trouvera un entier aléatoire grâce à la fonction rand de <cstdlib>.

int main(){

    srand( time( NULL ) );
    int randomValue = rand() % 101;

    int nombreMystere = 0;
    int tries = 0;

    do{
        cout << "Random number :" << endl;
        cin >> nombreMystere;
        tries += 1;

        if(nombreMystere > randomValue){
            cout << "Mysterie number is " << nombreMystere << " higher than random number " << randomValue << endl; 
        } else if(nombreMystere < randomValue){
           cout << "Mysterie number is " << nombreMystere << " smaller than random number " << randomValue  << endl;
        } else {
             cout << "Tries: " << tries << endl;
            break;
        }
    }
    
    while(true);
}



