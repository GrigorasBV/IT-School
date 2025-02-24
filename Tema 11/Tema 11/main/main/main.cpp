#include "Biblioteca.h"

int main() {
    Biblioteca b; // Crearea unui obiect de tip Biblioteca
    b.adaugaCarte("1984", "George Orwell", 1949, "Beletristica", 1, 1); // Adăugarea cărții "1984" în bibliotecă
    b.adaugaCarte("Sapiens", "Yuval Noah Harari", 2011, "Istorie", 2, 3); // Adăugarea cărții "Sapiens" în bibliotecă
    b.afiseazaCarti(); // Afișarea cărților disponibile în bibliotecă
    b.imprumutaCarte("1984"); // Împrumutarea cărții "1984"
    b.afiseazaCarti(); // Afișarea cărților disponibile după împrumut
    return 0; // Terminarea programului
}