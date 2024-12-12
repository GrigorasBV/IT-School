#include <iostream>
#include <string>
using namespace std;

class Player {
private:
    string name;
    int health;
    int xp;

public:
    void set_name(string name_val) {
        name = name_val;
    }
    Player();
    Player(string name);
    Player(string name, int health, int xp);
    ~Player() {
        cout << "destructor apelat " << name << endl;
    }
};
    Player::Player() 
        :name{"miciunul"},health{0}, xp{0}{}
    
    Player::Player(string name_val) 
        :name{ name_val}, health{ 0 }, xp{ 0 }{}

    Player::Player(string name_val,int health_val, int xp_val) 
        :name{ name_val }, health{ health_val }, xp{ xp_val } {}

    class Mate {
    private:
        int a;
        int b;

    public:
        int sum(int a,int b) {
            return a + b;
    }
        int dif(int a, int b) {
            if (a > b) return a - b;
            else return(b - a);
        }
    };
int main()
{
    Mate unu;
    cout<< unu.sum(2, 3)<<endl;

    Mate doi;
    cout << doi.dif(5, 6)<<endl;

    cout << "__________________________________________" << endl;
    Player frank;
    frank.set_name("Frank");
    //cout << frank.set_name() << endl;

    Player hero("Hero");
    hero.set_name("Hero");

    Player Vivi("Vivian", 100, 12);
    Vivi.set_name("Vivian");


    Player* eny = new Player;
    eny->set_name("eny");


    Player* env = new Player("env",80,10);
    env->set_name("env");

    delete eny;
    delete env;

    return 0;
}
/*
#include <iostream>
#include <string>
#include<vector>

using namespace std;


class Player {
private:
    std::string name;
    int health;
    int xp;

public:
    void set_name(std::string name_val) {
        name = name_val;
}

    std::string get_name() {
        return name;
    }
   
Player() {
    cout << "nici un parametru apelat de constructor " << endl;
}

Player(std::string name) {
    cout << "un parametru apelat de constructor " << endl;

}


    Player(std::string name, int health, int xp) {
    cout << "trei parametri apelati de constructor" << endl;
}

~Player() {
    cout << "destructor apelat pentru" << name << endl;
}



};




int main()
{

    Player frank;
    Player jim;

    Player* fotbalist = new Player;
    delete fotbalist;

    frank.set_name("Frank");
    // cout << frank.get_name() << endl;



    Player hero("Hero");
    hero.set_name("Hero");

    Player Vivi("Vivian", 100, 12);
    Vivi.set_name("Vivian");


    Player* eny = new Player;
    eny->set_name("eny");


    delete eny;



    return 0;
}*/