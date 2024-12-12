/*#include <iostream>
#include <vector>
using namespace std;

struct ZiMeteo {
    string nume;
    double temperatura;
};
void maxitemp(const vector<ZiMeteo>& zile)
{
    double maxTemp = zile[0].temperatura;
    for (const auto& zi : zile) {
        if (zi.temperatura > maxTemp) {
            maxTemp = zi.temperatura;
        }
    }
    cout << "Zilele cu temperatura maxima (" << maxTemp << " grade):"<<endl;
    for (const auto& zi : zile) {
        if (zi.temperatura == maxTemp) {
            cout << zi.nume << endl;
        }
    }
}

int main()
{
    vector<ZiMeteo> saptamana = {{"Luni", 15.3},
                                 {"Marti", 17.2},
                                 {"Miercuri", 21.5},
                                 {"Joi", 25.5},
                                 {"Vineri", 19.0},
                                 {"Sambata", 14.8},
                                 {"Duminica", 21.5}};
    maxitemp(saptamana);

    return 0;
}*/
#include <iostream>
#include <string>
using namespace std;

class Angajat {
private:
    string nume;
    float salariu;
    int nrOre;
public:
    Angajat(string n, int ore) : nume(n), nrOre(ore), salariu(0) {}
    void calculeazaSalariu() {
        const float salarPeOra = 21.0;
        salariu = nrOre * salarPeOra;
    }
    void display() {
        cout << "Angajatul " << nume<< " a lucrat " << nrOre<< " ore si a caatigat " << salariu<< " lei."<<endl;
    }
};

int main() {
    Angajat angajat1("Grigoras", 50); 
    angajat1.calculeazaSalariu();
    angajat1.display();

    return 0;
}