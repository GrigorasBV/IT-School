#include <iostream>

using namespace std;
char ok ;
int main() {

    do {
        cout << " Introduce-ti  " << endl;
        cout << " 1 pentru Exercitiul I" << endl;
        cout << " 2 pentru Exercitiul II" << endl;
        cout << " 3 pentru Exercitiul III" << endl;
        int n;
        cin >> n;
        if (n == 1) {
            int a, i;
            cout << "Exercitiul I" << endl << "Introduceti numarul pentru verificare " << endl;
            cin >> a;
            bool ok = true;
            for (i = 2; i <= a / 2; i++)
                if (a % i == 0)
                    ok = false;
            if (ok) cout << " Nr introdus este prim " << endl;
            else cout << " Nr introdus nu este prim" << endl;
        }

        else if (n == 2) {
            int a, b;
            cout << "Exercitiul II" << endl;
            cout << "Introduceti cele 2 nr pentru care vrem sa aflam CMMDC " << endl;
            cin >> a >> b;
            while (a != b) {
                if (a > b)
                    a = a - b;
                else b = b - a;
            }
            cout << " CMMDC-ul este " << a << endl;

        }

        else  if (n == 3) {
            char var = 'y';
            int x;
            double sum = 0.00, bani = 0.00;
            do {

                cout << "Exercitiul III" << endl;
                cout << "Ce Produse Aveti In Cos? " << endl;
                cout << "Paine_________Tasta 1" << "  " << "Lapte_________Tasta 2" << endl;
                cout << "Oua___________Tasta 3" << "  " << "Faina_________Tasta 4" << endl;
                cout << "Ulei__________Tasta 5" << "  " << "Zahar_________Tasta 6" << endl;
                cout << "Sare__________Tasta 7" << "  " << "Gris__________Tasta 8" << endl;
                cout << "Malai_________Tasta 9" << "  " << "Ciocolata____Tasta 10" << endl;
                cout << "Apa__________Tasta 11" << "  " << "Suc__________Tasta 12" << endl;
                cout << "Bere_________Tasta 13" << "  " << "Biscuiti_____Tasta 14" << endl;
                cout << "Napolitane___Tasta 15" << "  " << "Nuttela______Tasta 16" << endl;
                cout << "Varza________Tasta 17" << "  " << "Rosii________Tasta 18" << endl;
                cout << "Ardei________Tasta 19" << "  " << "Castraveti___Tasta 20" << endl;
                cout << "____________________________________________" << endl;

                cout << "             Alegeti un produs " << endl;
                bool ok = 1;
                double sum = 0.00;
                while (ok != 0) {
                    int x;
                    cin >> x;
                    switch (x) {
                    case 1:  { sum += 1.75; cout << "TOTAL " << sum << " "; } break;
                    case 2:  { sum += 2.75; cout << "TOTAL " << sum << " "; } break;
                    case 3:  { sum += 5.75; cout << "TOTAL " << sum << " "; } break;
                    case 4:  { sum += 1.45; cout << "TOTAL " << sum << " "; } break;
                    case 5:  { sum += 31.7; cout << "TOTAL " << sum << " "; } break;
                    case 6:  { sum += 2.25; cout << "TOTAL " << sum << " "; } break;
                    case 7:  { sum += 3.25; cout << "TOTAL " << sum << " "; } break;
                    case 8:  { sum += 11.7; cout << "TOTAL " << sum << " "; } break;
                    case 9:  { sum += 3.75; cout << "TOTAL " << sum << " "; } break;
                    case 10: { sum += 4.65; cout << "TOTAL " << sum << " "; } break;
                    case 11: { sum += 1.65; cout << "TOTAL " << sum << " "; } break;
                    case 12: { sum += 12.7; cout << "TOTAL " << sum << " "; } break;
                    case 13: { sum += 17.6; cout << "TOTAL " << sum << " "; } break;
                    case 14: { sum += 3.54; cout << "TOTAL " << sum << " "; } break;
                    case 15: { sum += 1.65; cout << "TOTAL " << sum << " "; } break;
                    case 16: { sum += 23.7; cout << "TOTAL " << sum << " "; } break;
                    case 17: { sum += 76.7; cout << "TOTAL " << sum << " "; } break;
                    case 18: { sum += 1.35; cout << "TOTAL " << sum << " "; } break;
                    case 19: { sum += 1.85; cout << "TOTAL " << sum << " "; } break;
                    case 20: { sum += 43.7; cout << "TOTAL " << sum << " "; } break;
                    default:if (x > 20 || x < 1) {
                        cout << "Tasta nu este corecta ";
                        ok = 0;
                    }
                           else ok = 1;
                    }
                }
                cout << "Ce suma de bani aveti ?";
                cin >> bani;
                cout << "Din suma de bani " << bani << " au mai ramas " << bani - sum << endl;
                cout << "Faceti alte calcule ? Yes or No ";
                cin >> var;
            } while (var == 'y' || var == 'Y');
        }
            cout << "Doriti sa reluati Exercitiile ?, Alegeti Y pentru DA, sau N pentru NU" << endl;
            cin >> ok;

        } while (ok == 'y' || ok == 'Y');

            return 0;
 }