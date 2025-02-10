#include <iostream>  // Include biblioteca standard de intrare/ieșire
#include <string>    // Include biblioteca pentru manipularea string-urilor
#include <vector>    // Include biblioteca pentru utilizarea vectorilor
#include <iomanip>   // Include biblioteca pentru manipularea formatării ieșirii
#include <fstream>   // Include biblioteca pentru manipularea fișierelor
#include <memory>    // Include biblioteca pentru gestionarea memoriei inteligente

using namespace std; // Utilizează spațiul de nume standard pentru a evita prefixarea cu std::
/*
class Base {
public:
    void say_hello() const {
        cout << "Hello - I'm a Base class object" << endl; // Afișează un mesaj specific pentru obiectele de tip Base
    }
};

class Derived : public Base {
public:
    void say_hello() const {
        cout << "Hello - I'm a Derived class object" << endl; // Afișează un mesaj specific pentru obiectele de tip Derived
    }
};

void greetings(const Base& obj) {
    cout << "Greetings: ";
    obj.say_hello(); // Apelează metoda say_hello() a obiectului primit ca parametru
}

int main()
{
    Base b;
    b.say_hello(); // Afișează mesajul pentru obiectul de tip Base

    Derived d;
    d.say_hello(); // Afișează mesajul pentru obiectul de tip Derived

    greetings(b); // Apelează funcția greetings cu un obiect de tip Base
    greetings(d); // Apelează funcția greetings cu un obiect de tip Derived

    Base* ptr = new Derived(); // Creează un pointer de tip Base care pointează la un obiect de tip Derived
	ptr->say_hello(); // Afișează mesajul pentru obiectul de tip Derived

	unique_ptr<Base> ptr = make_unique<Derived>(); // Creează un pointer inteligent de tip Base care pointează la un obiect de tip Derived
	ptr->say_hello(); // Afișează mesajul pentru obiectul de tip Derived
    
	delete ptr; // Dezalocă memoria alocată dinamic pentru pointerul ptr
    return 0; // Returnează 0 pentru a indica faptul că programul s-a terminat cu succes
}*/


class Account {
public:
	virtual void withdraw(double amount) {
		cout << "In Account::withdraw" << endl;
	}
	virtual ~Account() {
		cout << "Account::destructor" << endl;
	}
};

class Checking : public Account {
public:
	virtual void withdraw(double amount) {
		cout << "In Checking::withdraw" << endl;
	}
	virtual ~Checking() {
		cout << "Checking::destructor" << endl;
	}
};

class Trust : public Account {
public:
	virtual void withdraw(double amount) {
		cout << "In Trust::withdraw" << endl;
	}
	virtual ~Trust() {
		cout << "Trust::destructor" << endl;
	}
};

class Savings : public Account {
public:
	virtual void withdraw(double amount) {
		cout << "In Savings::withdraw" << endl;
	}
	virtual ~Savings() {
		cout << "Savings::destructor" << endl;
	}
};

int main() {

	cout << "===================Pointer=================" <<  endl;

	Account* p1 = new Account();
	Account* p2 = new Checking();
	Account* p3 = new Trust();
	Account* p4 = new Savings();

	p1->withdraw(1000);
	p2->withdraw(1000);
	p3->withdraw(1000);
	p4->withdraw(1000);

	cout << "====================Array================" << endl;

	Account* array[] = { p1, p2, p3, p4 };	// Array of pointers, [] specifica numarul de elemente din array

	for (auto i = 0; i < 4; i++) {
		array[i]->withdraw(1000);
	}

	array[0] = p4;//suprascriere pointer

	for (auto i = 0; i < 4; i++) {
		array[i]->withdraw(1000);
	}

	cout << "====================vector================" << endl;

	vector<Account*> accounts{ p1, p2, p3, p4 }; // Vector of pointers

	for (auto acc_ptr : accounts) {
		acc_ptr->withdraw(1000);
	}

	cout << "====================push_pack================" << endl;
	accounts.push_back(p4); // Adaugă un nou element la sfârșitul vectorului
	for (auto acc_ptr : accounts) {
		acc_ptr->withdraw(1000);
	}
	cout << "====================Clean up================" << endl;
	delete p1;
	delete p2;
	delete p3;
	delete p4;




    return 0;
}
