#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Film {
public:
    string nume;
    double rating;
    int vazut;

    // Constructor
    Film(string nume, double rating, int vazut)
        : nume(nume), rating(rating), vazut(vazut) {}

    // Copy constructor (deep copy)
    Film(const Film& other)
        : nume(other.nume), rating(other.rating), vazut(other.vazut) {}

    // Assignment operator (deep copy)
    Film& operator=(const Film& other) {
        if (this == &other) return *this;
        nume = other.nume;
        rating = other.rating;
        vazut = other.vazut;
        return *this;
    }
};

class Colectie {
private:
    vector<Film> filme;

public:
    // Constructor
    Colectie() {}

    // Copy constructor (deep copy)
    Colectie(const Colectie& other) {
        for (const auto& film : other.filme) {
            filme.push_back(film);
        }
    }

    // Assignment operator (deep copy)
    Colectie& operator=(const Colectie& other) {
        if (this == &other) return *this;
        filme.clear();
        for (const auto& film : other.filme) {
            filme.push_back(film);
        }
        return *this;
    }

    void adaugaFilm(string nume, double rating, int vazut) {
        filme.push_back(Film(nume, rating, vazut));
    }

    void incrementeazaVazut(string nume) {
        for (auto& film : filme) {
            if (film.nume == nume) {
                film.vazut++;
                return;
            }
        }
        cout << "Filmul " << nume << " nu a fost gasit in colectie." << endl;
    }

    void afiseazaFilme() {
        for (const auto& film : filme) {
            cout << "Nume: " << film.nume << ", Rating: " << film.rating << ", Vazut: " << film.vazut << " ori" << endl;
        }
    }
};

int main() {
    Colectie colectie;

    colectie.adaugaFilm("Inception", 8.8, 3);
    colectie.adaugaFilm("The Matrix", 8.7, 5);

    colectie.incrementeazaVazut("Inception");

    colectie.afiseazaFilme();

    // Demonstrating deep copy
    Colectie colectie2 = colectie;
    colectie2.incrementeazaVazut("The Matrix");
    cout << "Colectie originala:" << endl;
    colectie.afiseazaFilme();
    cout << "Colectie copiata:" << endl;
    colectie2.afiseazaFilme();

    return 0;
}
