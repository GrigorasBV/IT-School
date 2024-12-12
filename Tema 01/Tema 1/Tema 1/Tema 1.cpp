#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Rezolvă exercițiile 1, 2, și 3
void my_func_rezolvare_ex123() {
    int myNumber = 50;
    float myNumber1 = 75.5;

    ++myNumber;
    --myNumber1;

    cout << "myNumber: " << myNumber << endl;
    cout << "myNumber1: " << myNumber1 << endl;
}

// Rezolvă exercițiile 4, 5 și 6
float my_func_rezolvare_ex456(int a, float b) {
    int suma = int(a + b);   //intreg
    float sumareal = a + b;   //real          

    // Exercițiul 5
    float rest_suma = static_cast<float>(suma * 5 % 12) / 12;
    float rest_sumareal = fmod(sumareal * 5, 12); //am folosit fmod pentru a calcula restul in float

    cout << "Suma intreaga " << suma << endl;
    cout << "Suma real " << sumareal << endl;
    cout << "Rest suma intreaga " << rest_suma << endl;
    cout << "Rest suma real: " << rest_sumareal << endl;

    return rest_sumareal;
}

// Rezolvă exercițiile 6, 7 și 8
void my_func_rezolvare_ex789() {
    string nume = "Bucur";
    string prenume = "Radu";
    string nume_complet = nume + " " + prenume;

    cout << "Nume complet: " << nume_complet << endl;
}

// Rezolvă exercițiile 9, 10 și 11
void my_func_rezolvare_ex91011() {
    string sirul_meu = "Acesta este continutul initial al sirului";
    cout << sirul_meu << endl;

    unsigned int a = 7, b = 9, c = 3;
    unsigned int minim = min({ a, b, c });
    cout << "Cel mai mic numar: " << minim << endl;

    float x = 72.3, y = 1387.12344, z = 6;
    float maxim = max({ x, y, z });
    cout << "Cel mai mare numar: " << maxim << endl;
}

// Exercițiul 12
void my_func_rezolvare_ex12() {
    const float a = 23.6;                // a nu se poate schimba deoarece este const
    float rezultat = a * 72;
    float comparatie = 1500.3;
    float maxim = (rezultat > comparatie) ? rezultat : comparatie;

    cout << "Maximul dintre " << rezultat << " si " << comparatie << " este: " << maxim << endl;
}

// Exercițiul 13
void my_func_rezolvare_ex13() {
    unsigned int y = 2379.8909, z = 11.4;
    int k = int(y / z);

    cout << "Rezultatul impartirii intrgi " << k << endl;
}

// Exercițiul 14 - Expresii logice
void my_func_rezolvare_ex14(int a, int b) {
    cout << "Varianta echivalenta este varianta 2" << endl;
}

// Exercițiul 15 - Operații pe biți
void my_func_rezolvare_ex15() {
    unsigned int var = 3;
    unsigned int var1 = 1;

    cout << "shiftare stanga cu 1 " << (var << 1) << endl;
    cout << "shiftare dreapta cu 1 " << (var >> 1) << endl;
    cout << "sau pe biti " << (var | var1) << endl;
    cout << "si pe biti  " << (var & var1) << endl;
    cout << "sau exclusiv pe biti " << (var ^ var1) << endl;
    //exercitii cu biti am facut la facultate :)
}

int main() {
    int a = 7;
    float b = 72.3;

    my_func_rezolvare_ex123();
    my_func_rezolvare_ex456(a, b);
    my_func_rezolvare_ex789();
    my_func_rezolvare_ex91011();
    my_func_rezolvare_ex12();
    my_func_rezolvare_ex13();
    my_func_rezolvare_ex14(a, 9);
    my_func_rezolvare_ex15();

    return 0;
}