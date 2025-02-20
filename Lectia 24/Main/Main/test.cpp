#include <iostream>
#include "test.h"

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
