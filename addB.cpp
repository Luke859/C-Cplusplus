#include <iostream>

using namespace std;

int main(){
    int a = 0;
    int b = 0;
    cout << "Nombre entier :" << endl;
    cin >> a;
    cout << "Second nombre entier :" << endl;
    cin >> b;
    if(b >= 0){
        cout << "Resultat:" << a << " + " << b << " = " << (a + b) << endl; 
    } else {
        cout << "Resultat:" << a << " - " << -b << " = " << (a + b) << endl;
    }
    return 0 ;
}

/* ou 

int main(){
    int a = 0;
    int b = 0;
    cout << "Nombre entier :" << endl;
    cin >> a;
    cout << "Second nombre entier :" << endl;
    cin >> b;
    cout << "Resultat: " << a 

    if(b >= 0){
            cout << " + " << b ; 
        } else {
            cout << " - " << -b ;
        }
    cout << " = " << (a + b) << endl;
    return 0 ; 
}*/