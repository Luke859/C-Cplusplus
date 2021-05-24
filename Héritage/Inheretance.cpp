#include <iostream>
#include <vector>

using namespace std;

class Parent {
    int Prop1;

    protected:
    int prop2;

    public:
    int prop3;
};

class Child: public Parent {
    int cprop1;

    protected:
    int cprop2;

    public:
    float cprop3;


    void doSomething() {
    }

};

void doSomethingWithParent(Parent& p){
    cout << p.prop3 << endl;
}

int main(int argc, char const *argv[])
{
    Parent p;
    Child c;
    c.prop3;
    doSomethingWithParent(c);
    return 0;
}

