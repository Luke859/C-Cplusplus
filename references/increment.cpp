// Reference

int increment(int& a){
    return a + 1;
}

int main(){
    int x = 6;
    increment(x);
    return 0;
}

// Pointeur


// void increment(int* a){
//     *a = *a + 1;
// }

// int main(){
//     int x = 6;
//     increment(&x);
//     return 0;
// }