#include <iostream> // std::cout
#include <cstdlib> // std::rand et srand
#include <vector>   // std::vector
#include <algorithm> // std::random_shuffle

using namespace std;


string passw(){

    string psw = "";
    int strSize = rand() % 8 +8;
    vector <char> ponctuation = {'.', '!', '?', ',', ';', ':'};


    for (int i = 0; i < strSize; i++){ 

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


int main(){

    srand( time( NULL ) );  /* initialize random seed: */

    cout << passw() << endl;
    
}