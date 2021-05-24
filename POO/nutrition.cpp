#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum DishType { // enum -> definit un type
    FirstDish,
    MainDish,
    Desert,
    Snack,
    Drink,
};

struct Nutrition {
    string dishName = "Inconnu";
    DishType dishtype = Desert;
    int servingInGrams = 100;
    int calories = 0; 
    float carbohydrates = 0;
    float proteins = 0;
    float fat = 0;


    Nutrition(string name, DishType dishType, int calories, float carbohydrates, float proteins, float fat): dishName(name), dishtype(dishType){

    }
    static vector<Nutrition* > needReview;

    static bool everythingApproved() {
        return Nutrition::needReview.size() == 0;
    }
    void printInfo(){
        cout << dishName << " : " << calories << " calories." << endl;
        // OU this->dishname
        //cout << this->dishName << " : " << this->calories << " calories." << endl;
    }

    void signal(){
        Nutrition::needReview.push_back(this);
    }

    // void approve() {
    //     for(int i = 0; i < needReview.size(); i++ ){
    //         if(needReview[i] == this){
    //             needReview.erase();
    //         }
    //     }
    // }
};

int main() {
    Nutrition donut;
    donut.dishName ="Donut";
    donut.dishtype = Desert;
    donut.calories = 320;
    // cout << donut.dishName << " : " << donut.calories << " calories. " << endl;
    donut.printInfo(); // fait la meme chose que la ligne au dessus 
    return 0;
}