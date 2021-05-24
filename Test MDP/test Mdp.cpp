#include <iostream> // std::cout
#include <cstdlib> // std::rand et srand
#include <vector>   // std::vector
#include <algorithm> // std::random_shuffle


using namespace std;

const int iterations = 1000;

string generateur(){

    string psw = "";
    int strSize = rand() % 8 +8;
    vector <char> ponctuation = {'.', '!', '?', ',', ';', ':'};


    for (int i = 0; i <= strSize; i++){ 

        if (i <= 2){
            psw.push_back(rand() % 26 + 65);

        }else if ( i > 2 && i <= 4){
            psw.push_back(rand() % 26 + 97);

        } else if (i == 5){
            int random = rand() % 6;
            psw.push_back(ponctuation[random]);

        } else {
            psw.push_back(rand() % 26 + 65);
        }
    }
    random_shuffle(psw.begin(), psw.end());
    return psw;
}

// verifier le mot de passe
bool verify(string mdp){

    int majuscule = 0; // charactere ASCII majuscule
    int minuscule = 0;// charactere ASCII minuscule
    bool length = false;
    bool ponctuation = false;

    for(int value = 0; value <= mdp.size(); value++){

        if(mdp[value] == 46 ||mdp[value] == 33 ||mdp[value] == 63 ||mdp[value] == 59 ||mdp[value] == 44 ||mdp[value] == 58){
            ponctuation = true;
        }

        if(mdp[value] >= 65 && mdp[value] <= 90){

            majuscule++;

        }
        else if(mdp[value] >= 97 && mdp[value] <= 122){
            minuscule++;
        }
    
    }
    if(majuscule >= 2 && minuscule >= 2 && ponctuation == true && mdp.size() >= 8){
        return true;
    }
    return false;
}

int main(){
    srand( time( NULL ) );  /* initialize random seed: */

    for(int i = 0; i < iterations; i++){
        string password = generateur();
        
        if(!verify(password)){
            cout << "Wrong password -> code error 2! : " << password << endl;
            return 2;
        }
    }
    cout << "Nothing wrong !" << endl;
    return 0;
}