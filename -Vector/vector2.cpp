#include <iostream>
#include <vector>

using namespace std;

int askForInteger(){
    int input = 0;
    do{
        cout << "Nombre entier: " << endl;
        
        if (!(cin >> input)){
            cout << "Ceci n'est pas un nombre !" << endl;
            cin.clear();
            cin.ignore();
            continue;
        }
        else 
        {
            return input;
        }
    }while(true);
}

int displaySum(vector<int> numbers){
    int result = 0;
    for(int value = 0; value < numbers.size(); value++){

        if(value != 0){

            if(numbers[value] >= 0){
                cout << " + " << numbers[value];
            } else {
                cout << " - " << -numbers[value];
            }

        }else {
            cout << numbers[value];
        }
        result += numbers[value];
    }
    cout << " = " << result << endl;
    return 0;
}


int main(){
    vector<int> numbers;
    do{
        int a = askForInteger();

        if( a == 0){
            break;
        }
        else {
            numbers.push_back(a);
        }

    }while(true);

    displaySum(numbers);
    return 0;
}