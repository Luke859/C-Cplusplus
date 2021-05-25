#include <iostream>
#include <vector>

using namespace std;

class Parent {
    int prop1;

    protected:
    int prop2;

    public:
    int prop3;

    void print(){
        cout << "Parent" << prop1 << " " << prop2 << " " << prop3 << endl;
    }

    
    Parent(int p1, int p2, int p3) : prop1(p1), prop2(p2), prop3(p3){}
};

class Child: public Parent {
    int cprop1;

    protected:
    int cprop2;

    public:
    float cprop3;


    void doSomething() {
    }

    void print() override{
        cout << "Child " << cprop1 << " " << cprop2 << " " << cprop3 << endl;
    }

    Child(int p1, int p2, int p3, float cp1, float cp2, float cp3) : Parent(p1, p2,p3), cprop1(cp1), cprop2(cp2), cprop3(cp3){}
};

void doSomethingWithParent(Parent& p){
    cout << p.prop3 << endl;
}

int main(int argc, char const *argv[])
{
    Parent p(1, 2, 3);
    Parent p2(4, 5, 6);
    Child c(7, 8, 9, 10.0f, 11.0f,12.0f);
    Child c2(13, 14, 15, 16.0f, 17.0f,18.0f);

    vector<Parent* > instances {&p, &c, &c2, &p2};

    for(Parent* ptr : instances){ // affiche la liste des chiffres( de parent et child)
        ptr->print();
    }

    doSomethingWithParent(c); // va afficher un chiffre de "c" qui est Child 
    return 0;
}

