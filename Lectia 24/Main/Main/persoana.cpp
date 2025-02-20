#include <iostream>
#include "persoana.h"

using namespace std;

void Persoana::afisare_nume() {
	cout << nume << endl;
}


//clasa Student mosteneste clasa Persoana

void Student:: promoveaza() {
	cout << "Promoveaza" << endl;//overriding metoda promoveaza
}
