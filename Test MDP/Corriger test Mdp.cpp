#include <iostream>
#include <string>

using namespace std;

const string punctuation = "!.,;?:";
const string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!.,;?:";
const int iterations = 10000;

bool verify(string str){
    int lowerCase = 0;
    int upperCase = 0;
    bool containsPunct = false;
    for( char c : str){
        if( c >= 'A' && c <= 'Z'){
            upperCase++;
        }
        else if( c >= 'a' &&  c <= 'z'){
            lowerCase++;
        }
        else if(punctuation.find(c) != string::npos){
            containsPunct = true;
        }

        if(upperCase >= 2 && lowerCase >= 2 && containsPunct && str.length() >= 8){
            return true;
        }

    }
    return false;
}

int randomInRange(int min, int max){
    return rand() % (max-min) + min;
}

void shuffle(string& input){
    for(int i = 0; i < input.length(); i++){
        int j = randomInRange(0,input.length());
        char buffer = input[i];
        input[i] = input[j];
        input[j] = buffer;
    }
}

string getLettersInRange(char min, char max, int numberOfLetters){
    string result = "";
    for(int i = 0 ; i < numberOfLetters; i++){
        char letter = randomInRange(min,max);
        result += letter;
    }
    return result;
}

char randomPunctuation(){
    return punctuation[randomInRange(0,punctuation.length())];
}


string generate(){
    string result = "";
    int length = randomInRange(8,16);
    result += getLettersInRange('A','Z',2);
    result += getLettersInRange('a','z',2);
    result += randomPunctuation();
    for(int i = 0; i < (length - 5); i++){
        result += charset[randomInRange(0,charset.length())];
    }
    shuffle(result);
    return result;
}

int main(){
    srand(time(NULL));
    for(int i = 0; i < iterations; i++){
        string password = generate();
        if(!verify(password)){
            cout << "A password did not pass the test : " << password << endl;
            return 2;
        }
    }
    cout << "Everything went fine!" << endl;
    return 0;
}