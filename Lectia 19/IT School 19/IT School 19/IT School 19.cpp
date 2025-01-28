#include <iostream>
#include <string>
#include <vector>

using namespace std;
/*
// Declarația clasei dreptunghi
class dreptunghi {
private:
    int latime, lungime; // Atribute private: lățimea și lungimea dreptunghiului
public:
    // Constructor implicit
    dreptunghi() {};
    // Constructor cu parametri pentru inițializarea lățimii și lungimii
    dreptunghi(int x, int y):latime(x), lungime(y){}
    // Metodă publică pentru calcularea ariei dreptunghiului
    int aria() { return lungime * latime; }
    // Declarația funcției prietene pentru dublarea dimensiunilor dreptunghiului
    friend dreptunghi dubleaza(const dreptunghi&);
};

// Definirea funcției prietene pentru dublarea dimensiunilor dreptunghiului
dreptunghi dubleaza(const dreptunghi& param) {
    dreptunghi res;
    res.latime  = param.latime * 2; // Dublarea lățimii
    res.lungime = param.lungime * 2; // Dublarea lungimii
    return res;
}

// Funcția principală main
int main()
{
    dreptunghi foo;         // Crearea unui obiect de tip dreptunghi
    dreptunghi mare(2, 3);  // Crearea unui obiect de tip dreptunghi cu lățimea 2 și lungimea 3
    foo = dubleaza(mare);   // Dublarea dimensiunilor dreptunghiului mare și atribuirea rezultatului lui foo
    cout << foo.aria() << endl; // Afișarea ariei dreptunghiului foo

    return 0; // Terminarea programului
}

// Declarația clasei patrat
class patrat;

// Declarația clasei dreptunghi
class dreptunghi {
    int latime, lungime; // Atribute private: lățimea și lungimea dreptunghiului
public:
    // Metodă publică pentru calcularea ariei dreptunghiului
    int aria() {
        return (latime * lungime);
    }
    // Metodă publică pentru a converti un obiect de tip patrat într-un dreptunghi
    void converteste(patrat a);
};

// Declarația clasei patrat
class patrat {
    // Prietenia clasei dreptunghi pentru a avea acces la atributele private ale clasei patrat
    friend class dreptunghi;
private:
    int latura; // Atribut privat: latura pătratului
public:
    // Constructor pentru inițializarea laturii pătratului
    patrat(int a):latura(a){}
};

// Definirea metodei converteste a clasei dreptunghi
void dreptunghi::converteste(patrat a) {
    latime  = a.latura; // Setează lățimea dreptunghiului egală cu latura pătratului
    lungime = a.latura; // Setează lungimea dreptunghiului egală cu latura pătratului
}

// Funcția principală main
int main(){
    dreptunghi mic;     // Crearea unui obiect de tip dreptunghi
    patrat mare(4);     // Crearea unui obiect de tip patrat cu latura 4
    mic.converteste(mare); // Convertirea obiectului patrat în dreptunghi
    cout << mic.aria(); // Afișarea ariei dreptunghiului
    return 0;           // Terminarea programului
}*/

/*class Account {
public:
	double balance;
    string name;
    void deposit(double amount);
	void withdraw(double amount);
	Account();
    ~Account();
};

Account::Account() : balance(0.0), name{ "An Account" }{}
Account::~Account() {}
void Account::deposit(double amount) {
    cout << "Account deposit called with " << amount << endl;
}
void Account::withdraw(double amount) {
cout << "Account withdraw called with " << amount << endl;
}
class Saving_Account : public Account {
public:
	double interest_rate;
	void deposit(double amount);
	void withdraw(double amount);
	Saving_Account();
	~Saving_Account();
};

Saving_Account::Saving_Account() : interest_rate(3.0) {
}
Saving_Account::~Saving_Account() {
}
void Saving_Account::deposit(double amount) {
	cout << "Saving Account deposit called with " << amount << endl;
}
void Saving_Account::withdraw(double amount) {
	cout << "Saving Account withdraw called with " << amount << endl;
}

int main() {
    cout << "==================Account==================" << endl;

    Account acc{};//instantierea clasei baza
	acc.deposit(2000.00);
	acc.withdraw(500.00);

    cout << endl;

	Account* p_acc{ nullptr };//pointer catre clasa baza
	p_acc = new Account();

	p_acc->deposit(1000.00);
	p_acc->withdraw(500.00);

	delete p_acc;

	cout << "==================Saving Account==================" << endl;

	Saving_Account sav_acc{};//instantierea clasei derivata
	sav_acc.deposit(2000.00);
	sav_acc.withdraw(500.00);


	cout << endl;

	Saving_Account* p_sav_acc{ nullptr };//pointer catre clasa derivata
	p_sav_acc = new Saving_Account();

	p_sav_acc->deposit(1000.00);
	p_sav_acc->withdraw(500.00);

	delete p_sav_acc;




    return 0;
}*/

class Base {
	//Note friends of Base have access to all
public:
	int a{ 0 };
	void display() { cout << a << ", " << b << ", " << c << endl; };
protected:
	int b{ 0 };
private:
	int c{ 0 };
};

class Derived : public Base {
	//Note friends of Derived have access to only a and b, NOT c
	//a will be public
	//b will be protected
	//c will not be accessible
public:
	void access_base_members() {
		a = 100; //OK
		b = 200; //OK
		//c = 300; //Compiler error
	}
};
int main() {
	cout << "==================Base==================" << endl;
	Base base;
	base.a = 100; //OK
	//base.b = 200; //Compiler error
	//base.c = 300; //Compiler error
	cout << "==================Derived==================" << endl;
	Derived derived;
	derived.a = 100; //OK
	//derived.b = 200; //Compiler error
	//derived.c = 300; //Compiler error
	return 0;
}