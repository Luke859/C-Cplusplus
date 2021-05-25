#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <exception>

using namespace std;

enum Job {
    Druid,
    Guerrier,
    MageJob, 
    BarbarianJob,
    Ninja,
};

struct character {

    static vector<character*> registeredPlayers;

    public:
    string nameChar;

    protected:
    int atckChar;
    int magicAtck;
    int defChar;
    int pvChar;
    int pvMaxChar;

    private: // les autres personnes ne pourront pas changer ces stats
    Job job;

    public: // tout les personnes externes ont access
    character(): character("John Wick", Guerrier, 20, 25, 2, 100, 50) {}// constructeur 

    // Satistique du personnage -> constrcteur
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

    class emptyPotion : public std::exception { // exception pour dire qu on n'a plus de potion
        virtual const char* what() const throw(){
            return "Trying to drink an empty potion !";
        }
    };

    class IllegalFury : public std::exception {
        bool entering; // exception pour dire qu on a Illegal Fury
        virtual const char* what() const throw(){
            if(entering){
                return "Cannot enter Fury twice !";
            }
            else {
                return "Cannot leave Fury if not in fury !";
            }
        }
        public:
        IllegalFury(bool entering ) : entering(entering) {}
    };

    // Potion pour heal 
    class Potion {

    int remainingCharges;
    int hpPerCharge;

    public:
    Potion(int remainingCharges, int hpPerCharge) : remainingCharges(remainingCharges), hpPerCharge(hpPerCharge) {}

    int getHealedHP(){
        if(!remainingCharges <= 0){
                throw emptyPotion();
            }

            remainingCharges -= 1;
            return hpPerCharge;
        }

        bool operateur<(const Potion& p) {
            return this-> remainngCharges*this->hpPerCharge < p.remainingCharges*p.hpPerCharge;
        }

    };

    // Heal 
    void heal(int healValue){
        if(pvChar + healValue > pvMaxChar){
            pvChar = pvMaxChar;

        } 
        else {
            pvChar += healValue;
        }
    }

    void drink(Potion& p){
        this->heal(p.getHealedHp());
    }

    character& operator+=(Potion& p){
        this-> drink(p);
        return *this;
    }

    // Attack
    void attack(character& defender){ // const on ne pourra pas changer l'attack du peronnage

        int damage = this->atckChar - defender.defChar; // le this va chercher attacker
        defender.receiveDamage(damage);

    }

    // Savoir les HP
    int getCurrentHp(){ // demande HP du personnage voir ligne 101
        return this->pvChar;
    }

    // Savoir nombre de personnages enregistrer
    static int getRegisteredNumber(){
        return character::registeredPlayers.size();
    }
    // recevoir des damages
    public:
    void receiveDamage(int damage){
        
        if(damage < 0){
            damage = 0;

        }

        if (this->pvChar - damage < 0){
            this->pvChar = 0;
        }

        else {
            this->pvChar -= damage;
        }
    }

    private:
    void registerPlayer(){
        character::registeredPlayers.push_back(this);
    }

};

// La classe Barbarian
class Barbarian : public character {

    private:
    int baseAtk;
    int baseDef;
    bool inFury;

    public: 
    Barbarian(string nameChar) : character(nameChar, Job::BarbarianJob, 20, 0, 7, 150, 150){
        baseAtk = this->atckChar;
        baseDef = this->defChar;
        inFury = false;
    }

    void enterFury(){ // Le mode Fury du Barbarian

        if(inFury){
            throw IllegalFury(true);
        }

        baseAtk = this->atckChar;
        baseDef = this->defChar;
        inFury = true;
        atckChar *= 1.5f; // attack multiplier par 150%
        defChar = 0;
        this->receiveDamage(pvMaxChar*0.15f);

    }

    void leaveFury(){ // on quitte le mod Fury
        if(!inFury){
            throw IllegalFury(false);
        }
        atckChar = baseAtk;
        defChar = baseDef;
        inFury = false;

    }
};

// La classe Mage
class Mage : public character {

    private:
    int pointMagie;
    int MaxPointMagie;
    bool tryUsingMp(int pointMagie){
        if(this->pointMagie > pointMagie){
            return false;
        }
        this-> pointMagie -= pointMagie;
    };

    public:
    Mage(string nameChar) : character(nameChar, Job::MageJob, 12, 10, 20, 200, 200), pointMagie(100){}

    void fireBall(character& other){
        if(!tryUsingMp(this->MaxPointMagie*0.10f)){
            return;
        }
        int randomNumber = rand() % 10;
        if(randomNumber == 0){
            return;
        }
        other.receiveDamage(this->magicAtck);
    }

};

vector<character* >character::registeredPlayers;

// void rename(character& c, string newName){
//     c.nameChar = newName;
// }

int main(int argc, char const *argv[]){

    try {

        srand( time(NULL) );
        Barbarian Jonesy("Jonesy");
        Mage Jayna("Jayna");
        character Kakashi("Kakashi", Job::Ninja, 12, 17, 8, 15, 100);

        // character* JonesyPtr = &Jonesy;                  Permet de changer d'une classe a une autre mais DANGEREUX car peut avoir erreur !!!

        // Mage* JonesyBarbarianPtr = (Barbarian* ) JonesyPtr;
        
        cout << "La partie commence avec " << character::getRegisteredNumber() << " joueurs " << endl;
        cout << "Kakashi le ninja copieur a " << Kakashi.getCurrentHp() << " HP" << endl;
        Jonesy.enterFury();

        Jonesy.attack(Kakashi);

        Potion small(200);
        
        Jonesy += small;
        Jonesy += small;
        Jonesy += small;
        Jonesy += small;
        cout << "All potions were drunk" << endl;
    }
    catch(IllegalFury& illegalF){
        cout << "An illegal barbarian fury operation occured : " << illegalF.what() < endl;
    }

    catch(EmptyPotion& ep){
        cout << "An illegal barbarian fury operation occured : " << ep.what() < endl;
    }

    catch(std::exception& e){
        cout << "An exception occured" << e.what() << endl;
    }

    cout << "End of combat" << endl;

    return 0; 
}
