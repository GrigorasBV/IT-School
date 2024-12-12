#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Player {
private:
    string name;
    int health;
    int xp;

public:
    string get_name() { return name; }
    int get_health() { return health; }
    int get_xp() { return xp; }

    Player(string name_val, int health_val, int xp_val);

    Player(const Player& source);

    ~Player() { cout << "Destructor apelat pentru: " << name << endl; }

};
Player::Player(string name_val, int health_val, int xp_val)
    :name{ name_val }, health{ health_val }, xp{ xp_val } {
    cout << "Cei 3 parametrii ai constructorului " + name << endl;
}
Player::Player(const Player& source)
    :name{ source.name }, health{ source.health }, xp{ source.xp } {
    cout << "copy constructor - facem o copiere " << endl;
}
void display_player(Player p) {
    cout << "Name:" << p.get_name() << endl;
    cout << "Health:" << p.get_health() << endl;
    cout << "Xp:" << p.get_xp() << endl;
}
/*
class Shallow {
private:
    int* data;                          //pointer
public:
    Shallow(int d);                  //constructor
    Shallow(const Shallow &source); //copy
    ~Shallow();                    //destructor                 
};

Shallow::Shallow(int d) {
    data = new int;                 //alocare de  memorie
    *data = d;
}
Shallow:~Shallow() {
delete data;
cout << "destructor release data " << endl;
}
*/
int main()
{
    Player empty{ "xxxx",100,50 };

    display_player(empty);

    return 0;
}