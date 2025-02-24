#include "Biblioteca.h"
#include <iostream>

void Biblioteca::adaugaCarte(const std::string& titlu, const std::string& autor, int an, const std::string& categorie, int rand, int raft) {
    carti.emplace_back(titlu, autor, an, categorie, rand, raft); // Adăugarea unei noi cărți în vectorul de cărți
}

void Biblioteca::imprumutaCarte(const std::string& titlu) {
    for (auto& carte : carti) { // Iterarea prin toate cărțile
        if (carte.getTitlu() == titlu && carte.esteDisponibila()) { // Verificarea dacă titlul corespunde și cartea este disponibilă
            carte.imprumuta(); // Împrumutarea cărții
            std::cout << "Ai imprumutat: " << titlu << std::endl; // Afișarea mesajului de confirmare
            return; // Ieșirea din funcție după împrumut
        }
    }
    std::cout << "Cartea nu este disponibila sau nu exista!" << std::endl; // Afișarea mesajului de eroare dacă cartea nu este disponibilă
}

void Biblioteca::afiseazaCarti() const {
    for (const auto& carte : carti) { // Iterarea prin toate cărțile
        carte.afiseaza(); // Afișarea detaliilor fiecărei cărți
    }
}