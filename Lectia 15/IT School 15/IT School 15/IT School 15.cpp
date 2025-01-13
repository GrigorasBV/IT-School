#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;


class Mystring {
private:
    char* str;
    int len;
public:
	Mystring();                                          //constructor fara parametrii
	Mystring(const char* s);                            //constructor overload
	Mystring(const Mystring& source);                  //constructor de copiere
	~Mystring();                                      //destructor
	void display()const; 						     //afisare
	int get_length()const;						    //lungimea sirului
	const char* get_string()const;				   //returneaza sirul
};


Mystring::Mystring() //constructor pentru alocare memorie
    : str(nullptr){
	str = new char[1];
	*str = '\0';
}
Mystring::Mystring(const char* s) //constructor overload 
    : str(nullptr) {
    if (s == nullptr) {
        str = new char[1];
        *str = '\0';
    }
    else {
        len = strlen(s);
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }
}
Mystring::Mystring(const Mystring& source)//constructor de copiere
		:str(nullptr) {
		str = new char[std::strlen(source.str) + 1];
		std::strcpy(str, source.str);
    }
Mystring::~Mystring() {   //destructor
		delete [] str;
	}
void Mystring::display()const {//metoda de afisare  
		cout << str << " : " << get_length() << endl;
	}

int Mystring::get_length()const {//metoda de calculare a lungimii sirului
		return std::strlen(str);
	}
const char* Mystring::get_string()const {//metoda de returnare a sirului
		return str;
	}

/*class Complex {
private:
    int real;
    int imag;
public:
    Complex(int r = 0, int i = 0) {
        real = r;
        imag = i;
    }

    Complex operator+(Complex const& obj) {
        Complex res;
        res.real = real + obj.real;
        res.imag = imag + obj.imag;
        return res;
    }
    void print() {
        cout << real << " + i " << imag << endl;
    }
};

class MyCar {
private:
    string name;
    int price;
public:
    MyCar(string n = " ", int p = 0) {
        name = n;
        price = p;
    }
    MyCar operator=(MyCar const& obj) {
        name = obj.name;
        price = obj.price;
        return *this;
    }
    bool operator==(MyCar const& obj) const {
        return (name == obj.name && price == obj.price);
    }
};

class MySold {
private:
    string name;
    int sum;
public:
    MySold(string n = " ", int s = 0) {
        name = n;
        sum = s;
    }
    MySold operator-(MySold const& obj) {
        MySold res;
        res.name = name;
        res.sum = sum - obj.sum;
        return res;
    }
    void print() {
        cout << name << " " << sum << endl;
    }
};
*/
int main()
{
	Mystring empty;
	Mystring Vlad("Vlad");
	Mystring BMW{ "BMW" };



	empty.display();
	Vlad.display();
	BMW.display(); 

	



   /* Complex c1(10, 5), c2(2, 4);
    Complex c3 = c1 + c2;

    c3.print();


    MyCar car1("BMW", 10000), car2("Audi", 20000);


    if (car1 == car2) cout << "egal\n";
    else cout << "diferit\n";

    MySold sold1("Abonament", 100), sold2("Factura", 50);
    MySold sold3 = sold1 - sold2;       
    sold3.print();
    */
    return 0;
}