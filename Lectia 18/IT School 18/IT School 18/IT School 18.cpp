/*#include <iostream>
#include <string>
using namespace std;

class MyClass {
private:
    string name;
    int age;
public:
    // Constructor implicit care deleagă către constructorul parametrizat
    MyClass() : MyClass("", 0) { cout << "verificare" << endl; }

    // Constructor parametrizat
    MyClass(string name, int age) : name(name), age(age) {}

    // Constructor de copiere
    MyClass(const MyClass& other) {
        name = other.name;
        age = other.age;
    }

    // Constructor de mutare
    MyClass(MyClass&& other) noexcept {
        name = move(other.name);
        age = other.age;
        other.age = 0; // Resetăm valoarea pentru a indica că resursele au fost mutate
    }

    string get_name() {
        return name;
    }
    int get_age() {
        return age;
    }

    void set_name(string name) {
        this->name = name;
    }
    void set_age(int age) {
        this->age = age;
    }
    void display() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

int main()
{
    MyClass obj1;
    obj1.set_name("VLAD");
    obj1.set_age(35);    
    obj1.display();

    // Utilizarea constructorului de copiere
    MyClass obj2 = obj1;
    obj2.display();

    // Utilizarea constructorului parametrizat
    MyClass obj3("ION", 25);
    obj3.display();

    // Utilizarea constructorului de mutare
    MyClass obj4 = move(obj3);
    obj4.display();
    obj3.display(); // Obiectul mutat ar trebui să aibă valorile resetate

    return 0;
}
*/
#include <iostream>
#include <string>
#include<vector>
#include <cstring>


class Mystring {
private:
    char* str;
public:
    Mystring();                        //no args constructor
    Mystring(const char* s);           //overloaded constructor
    Mystring(const Mystring& source);  //copy constructor
    Mystring(Mystring&& source);       //move constructor
    ~Mystring();                       //destructor

    Mystring& operator = (const Mystring& rhs); //copy assignment
    Mystring& operator = (Mystring&& rhs);        //move assigment

    Mystring operator-()const;                       //lowercase
    Mystring operator+(const Mystring& rhs)const;    //concatenate
    bool operator==(const Mystring& rhs) const;      //egalitate

    void display() const;
    int get_length() const;
    const char* get_str() const;
};

Mystring::Mystring()
    :str{ nullptr } {
    str = new char[1];
    *str = '\0';
}

Mystring::Mystring(const char* s)
    :str(nullptr) {
    if (s == nullptr) {
        str = new char[1];
        *str = '\0';
    }
    else {
        str = new char[std::strlen(s) + 1];
        std::strcpy(str, s);
    }
}

Mystring::Mystring(const Mystring& source)
    :str(nullptr) {
    str = new char[std::strlen(source.str) + 1];
    std::strcpy(str, source.str);
}

//Move constructor
Mystring::Mystring(Mystring&& source)
    :str(source.str) {
    source.str = nullptr;
    std::cout << "move constructor" << std::endl;
}

Mystring::~Mystring() {
    delete[] str;
}

//copy assigment
Mystring& Mystring::operator = (const Mystring& rhs) {
    std::cout << str << "copy assignment" << std::endl;

    if (this == &rhs)       //p1=p1
        return *this;           //return curent object

    delete[] this->str;
    str = new char[std::strlen(rhs.str) + 1];
    std::strcpy(this->str, rhs.str);

    return *this;          //return curent object
}

//move assignment
Mystring& Mystring::operator=(Mystring&& rhs) {
    std::cout << "USING MOVE ASSIGNENT" << std::endl;

    if (this == &rhs)   //self assignment
        return *this;   //return curent object

    delete[]str;        //dealocate the curent object
    str = rhs.str;      //steal the pointer
    rhs.str = nullptr;  //null out the rhs object

    return *this;
}

//egalitate
bool Mystring::operator==(const Mystring& rhs)const {
    return (std::strcmp(str, rhs.str) == 0);
}

//make lowercase
Mystring Mystring::operator-()const {
    char* buff = new char[std::strlen(str) + 1];
    std::strcpy(buff, str);

    for (size_t i = 0; i < std::strlen(buff); i++)
        buff[i] = std::tolower(buff[i]);
    Mystring temp{ buff };
    delete[]buff;
    return temp;
}

//concatenate
Mystring Mystring::operator+(const Mystring& rhs)const {
    char* buff = new char[std::strlen(str) + std::strlen(rhs.str) + 1];

    std::strcpy(buff, str);
    std::strcat(buff, rhs.str);
    Mystring temp{ buff };
    delete[] buff;
    return temp;
}

void Mystring::display() const {
    std::cout << str << ":" << get_length() << std::endl;
}

int Mystring::get_length() const { return std::strlen(str); }

const char* Mystring::get_str() const { return str; }



int main() {


    Mystring x{ "SALUT" };
    x = Mystring{ "Bonjour" };
    x = "Calimera";


    Mystring a{ "hello" };          //overload constructor
    Mystring b;                     //no-arg constructor
    b = a;                          //copy assignment
    //b.operator=(a)
    b = "acesta este un test";      //b.operator=("acesta este un test")

    Mystring empty;                 //no-arg constructor
    Mystring lavinia("Lavinia");    //overload constructor
    Mystring BMW{ "bmw" };

    Mystring opel;                  //no-arg constructor
    empty = BMW;                    //copy assignment operator

    empty.display();
    lavinia.display();
    BMW.display();


    Mystring alin{ "Alin" };
    Mystring itschool{ "ITSchool" };

    Mystring stooge = alin;
    alin.display();
    itschool.display();

    std::cout << (alin == itschool) << std::endl;
    std::cout << (alin == stooge) << std::endl;

    alin.display();
    Mystring alin2 = -alin;
    alin2.display();

    Mystring stooges = alin + "ALIN";
    //Mystring stooges = "alin" + "ITSchool";     //compiler error

    Mystring two_stooges = alin + "" + "ALIN";
    two_stooges.display();

    return 0;
}