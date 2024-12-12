#include <iostream>
#include <vector>
#include <string>


using namespace std;


class Player {
public:
	//atribute
	string name{ "Player" };
	int health;
	int xp;
	//metode
	void spune_ceva(string text) { cout << name << " salut"<<endl; };
	bool alive();

};
class Adunare {
private:
	int a,b;
public:
	void suma(int a, int b) { cout << a + b<<endl; };
};
class cont {
public:
	string name;
	long long cnp; 
		void zi() const {
		cout << (cnp / 1000000) % 100;
	}
		void luna() const {
		cout << (cnp / 100000000) % 100;
	}
		void an() const {
		cout << (cnp / 10000000000) % 100;
	}
		void afisare(const string& text) const {
			cout << text << ": " << name << " "; zi();
			cout << ".";luna();
			cout << ".";an();
			cout << endl;
	}
};

int main()
{
	cont eu;
	eu.cnp = 1910522898989;
	eu.name = { "Bogdan" };
	eu.afisare("Datele");





	Adunare unu;
	unu.suma(12,13);
	Player Bogdan;
	Player* prieten = new Player;
	(*prieten).name = "Andrei";
	prieten->name = "Andreea";
	prieten->spune_ceva("andrei");


	Bogdan.name = { "Grigoras" };


	Bogdan.spune_ceva("Tovarase");
	

	return 0;
}