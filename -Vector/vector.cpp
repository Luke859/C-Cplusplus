#include <iostream>
#include <vector>

using namespace std;


int main(){
    vector<int> numbers {1 , 4, 7, -2, 8};
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
