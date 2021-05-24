#include <iostream> 

using namespace std;

string mdp(){

    string passw;
    cout << "Enter a password :" << endl;
    cin >> passw;
    return passw;

}

bool verify(string mdp){

    int majuscule = 0; // charactere ASCII majuscule
    int minuscule = 0;// charactere ASCII minuscule
    bool length = false;
    bool ponctuation = false;

    for(int value = 0; value <= mdp.size(); value++){

        if(mdp.size() >= 8){
            length = true;

        }

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
    if(majuscule >= 2 && minuscule >= 2 && ponctuation == true && length == true ){
        return true;
    }
    return false;
}

int main(){

    string password = mdp();
    bool look = verify(password);

    if(look == true){
        cout << "Correct password" << endl;
    }else {
        cout << "Incorrect password" << endl;
    }

}