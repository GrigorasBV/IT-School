#pragma once
#include <iostream>



using namespace std;


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
