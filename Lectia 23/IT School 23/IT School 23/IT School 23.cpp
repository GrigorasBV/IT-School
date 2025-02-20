#include <iostream>
#include <string>
#include<vector>
#include <ostream>
#include <cstring>
#include <fstream>
#include <memory>

//abstract classess as interfaces
class I_printable {
    friend std::ostream& operator<<(std::ostream& os, const I_printable& obj);
public:
    virtual void print(std::ostream& os) const = 0;
};

std::ostream& operator<<(std::ostream& os, const I_printable& obj) {
    obj.print(os);
    return os;
}



class Account :public I_printable {
    //   friend std::ostream& operator<<(std::ostream& os, const Account& acc);
public:
    virtual void withdraw(double amount) {
        std::cout << "In Account::withdraw" << std::endl;
    }
    virtual void print(std::ostream& os)const override {
        os << "Account dislay";
    }
    virtual ~Account() {
        std::cout << "Destructor Account::withdraw" << std::endl;
    }
};
/*
std::ostream& operator<<(std::ostream& os, const Account& acc) {
    os << "Account display";
    return os;
}
*/

class Checking :public Account {
    //   friend std::ostream& operator<<(std::ostream& os, const Checking& acc);
public:
    virtual void withdraw(double amount) {
        std::cout << "In Checking::withdraw" << std::endl;
    }
    virtual void print(std::ostream& os)const override {
        os << "Checking dislay";
    }
    virtual ~Checking() {
        std::cout << "Destructor Checking::withdraw" << std::endl;
    }
};
/*
std::ostream& operator<<(std::ostream& os, const Checking& acc) {
    os << "Checking display";
    return os;
}

*/

class Saving :public Account {
    //  friend std::ostream& operator<<(std::ostream& os, const Saving& acc);
public:
    virtual void withdraw(double amount) {
        std::cout << "In Saving::withdraw" << std::endl;
    }
    virtual void print(std::ostream& os)const override {
        os << "Saving dislay";
    }
    virtual ~Saving() {
        std::cout << "Destructor Saving::withdraw" << std::endl;
    }
};
/*
std::ostream& operator<<(std::ostream& os, const Saving& acc) {
    os << "Saving display";
    return os;
}
*/


class Trust :public Account {
    //  friend std::ostream& operator<<(std::ostream& os, const Trust& acc);
public:
    virtual void withdraw(double amount) {
        std::cout << "In Trust::withdraw" << std::endl;
    }
    virtual void print(std::ostream& os)const override {
        os << "Trust dislay";
    }
    virtual ~Trust() {
        std::cout << "Destructor Trust::withdraw" << std::endl;
    }
};
/*
std::ostream& operator<<(std::ostream& os, const Trust& acc) {
    os << "Trust display";
    return os;
}
*/

class Dog : public I_printable {
public:
    virtual void print(std::ostream& os)const override {
        os << "HAM HAM";
    }
};


void print(const I_printable& obj) {
    std::cout << obj << std::endl;
}

int main() {

    Dog* dog = new Dog();
    // std::cout << *dog << std::endl;
    print(*dog);


    //nu avem nici o functie de tip virtual si obiectul nu contin nici o functie de tip virtual si de aceea o putem printa
    Account* p1 = new Account();
    std::cout << *p1 << std::endl;


    /*
    Account a;
    std::cout << a << std::endl;

    Checking c;
    std::cout << c << std::endl;

    Saving s;
    std::cout << c << std::endl;

    Trust t;
    std::cout << t << std::endl;
    */

    return 0;
}















/*
//Abstract class
class Animal {
public:
    virtual void sound() = 0; //pure virtual function

    void eat() {              //concrete method(with implementation)
        std::cout << "This animal is eating" << std::endl;
    }


    virtual ~Animal(){}
};

//derived class Dog
class Dog : public Animal {
public:
    void sound()override {
        std::cout << "HAM HAM" << std::endl;
    }
};

class Cat :public Animal {
public:
    void sound()override {
        std::cout << "MEOW" << std::endl;
    }
};


int main() {

    Dog dog;
    dog.sound();
    dog.eat();

    Cat cat;
    cat.sound();
    cat.eat();


    return 0;
}

*/


/*
//why destructor needs to be virtual
class Base {
public:
    virtual ~Base() {
        std::cout << "Base destructor" << std::endl;
    }
};

class Derived :public Base {
public:
    ~Derived() { //need to be virtual
        std::cout << "Base Derived" << std::endl;
    }
};

int main() {
    Base* ptr = new Derived();

    delete ptr;//this will call derive's destructor if ~Base is virtual, without a virtual destructor deleting a
               //derived class object through a base class pointer leads to undefined behavior

    return 0;
}

*/


