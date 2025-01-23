#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

class Mystring {
private:
    char* str;                                          // Pointer către un array de caractere care conține șirul
    int len;                                            // Lungimea șirului
public:
    Mystring();                                         // Constructor fără parametri
    Mystring(const char* s);                            // Constructor supraincarcat
    Mystring(const Mystring& source);                   // Constructor de copiere
	Mystring(Mystring&& source);                        // Constructor de mutare
    ~Mystring();                                        // Destructor

	Mystring& operator=(const Mystring& rhs);           // Operator de atribuire prin copiere
	Mystring& operator=(Mystring&& rhs);                // Operator de atribuire prin mutare

    void display() const;                               // Metodă pentru afișarea șirului
    int get_length() const;                             // Metodă pentru obținerea lungimii șirului
    const char* get_string() const;                     // Metodă pentru obținerea șirului
};

// Constructor fără parametri
Mystring::Mystring()
    : str(nullptr) {
    str = new char[1];
    *str = '\0';
}

// Constructor supraincarcat
Mystring::Mystring(const char* s)
    : str(nullptr) {
    if (s == nullptr) {
        str = new char[1];
        *str = '\0';
    } else {
        str = new char[strlen(s) + 1];
        strcpy(str, s);                                 // Folosește strcpy pentru a copia șirul
    }
}

// Constructor de copiere
Mystring::Mystring(const Mystring& source)
    : str(nullptr) {
    str = new char[std::strlen(source.str) + 1];
    std::strcpy(str, source.str);                       // Folosește strcpy pentru a copia șirul
}

// Constructor de mutare
Mystring::Mystring(Mystring&& source)
	: str(source.str) {
	source.str = nullptr;                               // Resetează sursa
	cout << "Move constructor" << endl;
}

// Destructor
Mystring::~Mystring() {
    delete[] str;                                       // Eliberează memoria alocată
}

// Operator de atribuire prin copiere
Mystring& Mystring::operator=(const Mystring& rhs) {
    cout <<str<< "Copy assignment" << endl;
    if (this == &rhs) {                                 // Verifică auto-atribuirea
        return *this;
    }
    delete[] this->str;                                 // Eliberează memoria veche
    str = new char[std::strlen(rhs.str) + 1];
    std::strcpy(str, rhs.str);                          // Folosește strcpy pentru a copia șirul
    return *this;
}

// Operator de atribuire prin mutare
Mystring& Mystring::operator=(Mystring&& rhs) {
	cout << "Using Move assignment" << endl;
	if (this == &rhs) {                                 // Verifică auto-atribuirea
		return *this;                                   // return curent object
	}
	delete[] str;                                       // Eliberează memoria veche
	str = rhs.str;                                      // Preia resursa de la rhs
	rhs.str = nullptr;                                  // Resetează rhs
	return *this;
}

// Metodă pentru afișarea șirului
void Mystring::display() const {
    cout << str << " : " << get_length() << endl;
}

// Metodă pentru obținerea lungimii șirului
int Mystring::get_length() const {
    return std::strlen(str);
}

// Metodă pentru obținerea șirului
const char* Mystring::get_string() const {
    return str;
}

int main() {

    Mystring x{ "SALUT" };
    x = Mystring{ "Bonjour" };
    x = "Calimera";
    /*
    Mystring a{ "Hello" };                             // Creează un obiect Mystring cu "Hello"
    Mystring b;
    b = a;                                             // Folosește operatorul de atribuire prin copiere

    b = "acesta este un test";

    Mystring s1{"Vlad"};
    Mystring s2 = s1;                                  // Folosește constructorul de copiere 

    Mystring empty; 
    Mystring Vlad("Vlad"); 
    Mystring BMW{ "BMW" }; 

    empty.display(); 
    Vlad.display(); 
    BMW.display();
    */
    return 0;
}