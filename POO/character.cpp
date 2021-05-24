#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum Job {
    Druid,
    Guerrier,
    Mage, 
    Barbarian,
    Ninja,
};

struct character {

    static vector<character*> registeredPlayers;

    public:
    string nameChar;

    private: // les autres personnes ne pourront pas changer ces stats
    Job job;
    int atckChar;
    int magicAtck;
    int defChar;
    int pvChar;
    int pvMaxChar;

    public: // tout les personnes externes ont access
    character(): character("John Wick", Guerrier, 20, 25, 2, 100, 50) {}// constructeur 

    // Satistique du personnage et constrcteur
    character(string nameChar, Job job, int atckChar, int magicAtck, int defChar,int pvChar, int pvMaxChar){
        this->nameChar = nameChar;
        this->job = job;
        this->atckChar = atckChar;
        this->magicAtck = magicAtck;
        this->defChar = defChar;
        this->pvMaxChar = pvMaxChar;
        this->pvChar = pvMaxChar;
        this->registerPlayer();
    }

    // Heal 
    void heal(int healValue){
        if(pvChar + healValue > pvMaxChar){
            pvChar = pvMaxChar;

        } 
        else {
            pvChar += healValue;
        }
    }

    // Attack
    void attack(character& defender){ // const on ne pourra pas changer l'attack du peronnage
    int damage = this->atckChar - defender.defChar; // le this va chercher attacker

        if(damage < 0){
            damage = 0;

        }

        if (defender.pvChar - damage < 0){ // si les damage au defenser son negatif, on ne pas car pv = 0
            defender.pvChar = 0;
        }

        else {
            defender.pvChar -= damage;
        }
    }

    int getCurrentHp(){ // demande HP du personnage voir ligne 101
        return this->pvChar;
    }

    static int getRegisteredNumber(){
        return character::registeredPlayers.size();
    }

    private:
    void registerPlayer(){
        character::registeredPlayers.push_back(this);
    }

};

vector<character* >character::registeredPlayers;

// void rename(character& c, string newName){
//     c.nameChar = newName;
// }

int main(int argc, char const *argv[]){

    character Jonesy("Jonesy", Job::Mage, 10, 15, 10, 20, 100);

    character Kakashi("Kakashi", Job::Ninja, 12, 17, 8, 15, 100);
    
    cout << "La partie commence avec " << character::getRegisteredNumber() << " joueurs " << endl;

    // rename(Jonesy, "CIAO");
    // cout << Jonesy.nameChar << endl;

    cout << "Kakashi le ninja copieur a " << Kakashi.getCurrentHp() << " HP" << endl;

    Jonesy.attack(Kakashi);

    Jonesy.heal(50);

    return 0; 
}
