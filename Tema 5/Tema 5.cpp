#include <iostream>
#include <vector>
using namespace std;

// Structura pentru înregistrarea datelor meteo
struct ZiMeteo {
    string nume;
    double temperatura;
};

// Func?ie pentru afi?area zilelor cu temperatura maxim?
void afisareZileTemperaturaMaxima(const vector<ZiMeteo>& zile)
{
    double maxTemp = zile[0].temperatura;

    // Determin?m temperatura maxim?
    for (const auto& zi : zile) {
        if (zi.temperatura > maxTemp) {
            maxTemp = zi.temperatura;
        }
    }

    // Afi??m zilele cu temperatura maxim?
    cout << "Zilele cu temperatura maxima (" << maxTemp << " grade):\n";
    for (const auto& zi : zile) {
        if (zi.temperatura == maxTemp) {
            cout << zi.nume << endl;
        }
    }
}

int main()
{
    // Vectorul de zile cu temperaturile corespunz?toare
    vector<ZiMeteo> saptamana = {
                                 {"Luni", 15.3},
                                 {"Marti", 18.2},
                                 {"Miercuri", 21.5},
                                 {"Joi", 21.5},
                                 {"Vineri", 19.0},
                                 {"Sambata", 14.8},
                                 {"Duminica", 21.5}
    };

    // Apel?m func?ia de afi?are
    afisareZileTemperaturaMaxima(saptamana);

    return 0;
}