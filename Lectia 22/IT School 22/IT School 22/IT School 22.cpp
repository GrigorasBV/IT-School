#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>


using namespace std;

class shape {//abstract class
private://atributes common all shapes 

public:
	virtual void draw() = 0;//pure virtual function
	virtual void rotate() = 0;//pure virtual function
	virtual ~shape() {}//virtual destructor
};

class open_shape : public shape {//abstract class
public:
	virtual ~open_shape() {}//virtual destructor
};

class closed_shape : public shape {//abstract class
public:
	virtual ~closed_shape() {}//virtual destructor
};

class line : public open_shape {//concrete class
public:
	virtual void draw() override {
		cout << "Draw a line" << endl;
	}
	virtual void rotate() override {
		cout << "Rotate a line" << endl;
	}
	virtual ~line() {}//virtual destructor
};

class circle : public closed_shape {//concrete class
public:
	virtual void draw() override {
		cout << "Draw a circle" << endl;
	}
	virtual void rotate() override {
		cout << "Rotate a circle" << endl;
	}
	virtual ~circle() {}//virtual destructor
};

class square : public closed_shape {//concrete class
public:
	virtual void draw() override {
		cout << "Draw a square" << endl;
	}
	virtual void rotate() override {
		cout << "Rotate a square" << endl;
	}
	virtual ~square() {}//virtual destructor
};


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

void do_withdraw(Account& account, double amount) {
	account.withdraw(amount);
}


void screen_refreshing(vector<shape*>& shapes) {
	cout << "Refreshing" << endl;
	for (const auto p : shapes) {
		p->draw();
	}
}

int main()
{
	Account a;
	Account& ref = a;
	ref.withdraw(1000);

	Trust t;
	Account& ref1 = t;
	ref1.withdraw(1000);

	do_withdraw(a, 1000);


	//Shape s; //error: cannot instantiate abstract class
	//shape* p1 = new Shape(); //error: cannot instantiate abstract class


	shape* c = new circle();

	c->draw();
	c->rotate();

	shape* ptr = new line();
	shape* ptr1 = new square();
	shape* ptr2 = new circle();

	vector<shape*> shapes{ ptr, ptr1, ptr2 };
	for (const auto p : shapes) {
		p->draw();
	}
	screen_refreshing(shapes);

	delete ptr, ptr1, ptr2;	




	return 0;
}