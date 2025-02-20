#pragma once
#include <iostream>

using namespace std;

class Persoana {
private:
	string nume;
public:
	Persoana(string name) : nume(name) {}

	void afisare_nume();
};
//clasa Student mosteneste clasa Persoana

class Student : Persoana {
public:
	Student(string name) : Persoana(name) {}
	void promoveaza();
};
