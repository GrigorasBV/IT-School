#include <iostream>
using namespace std;

struct biblioteca {
	string categorie;
	string carte;
	int rand;
};

struct elev {
	string nume;
	double mediamate;
	double mediainfo;
	double mediaifiz;
};

void citire_elev(elev &a) {
	cout << "Nume" << endl;
	cin >> a.nume;
	cout << "Mediainfo" << endl;
	cin >> a.mediainfo;
	cout << "Mediamate" << endl;
	cin >> a.mediamate;
	cout << "Media fizica" << endl;
	cin>> a.mediaifiz;
}
void afisare_elev(elev& a) {
	cout << a.nume <<" " << a.mediainfo << " " << a.mediainfo << " " << a.mediaifiz<<endl;
}
int main()
{
	elev a, b, c;
	citire_elev(a);
	afisare_elev(a);
	cout << "______________________________________" << endl;


	a.nume = "Bogdan";
	a.mediamate = 9.5;
	a.mediainfo = 9.75;
	a.mediaifiz = 9.25;

	b.nume = "Vladut";
	b.mediamate = 8.5;
	b.mediainfo = 8.75;
	b.mediaifiz = 8.25;

	c.nume = "Grigoras";
	c.mediamate = 7.5;
	c.mediainfo = 7.75;
	c.mediaifiz = 7.25;

	biblioteca carturesti;

	carturesti.categorie = "Fictiune";
	carturesti.carte = "Carte 1";
	carturesti.rand = 12;



	struct {
		int anul;
		string model;
		string brand;

	}mycar, mycar1, mycar2;


	mycar.anul = 1991;
	mycar.brand = 'VW';
	mycar.model = "Polo";

	mycar1.anul = 1992;
	mycar1.brand = "Audi";
	mycar1.model = "A6";

	mycar2.anul = 1993;
	mycar2.brand = "Benz";
	mycar2.model = "W124";
	
	cout << mycar.anul << " " << mycar1.anul << " " << mycar2.anul;

	return 0;
}
