#include "Carte.h"
#include <iostream>

Carte::Carte(std::string t, std::string a, int an, std::string cat, int r, int rf) :
    titlu(t), autor(a), anPublicare(an), categorie(cat), rand(r), raft(rf), disponibila(true) { // Inițializarea atributelor cărții
}

void Carte::afiseaza() const {
    std::cout << titlu << " - " << autor << " (" << anPublicare << ") [" << categorie << "] Raft " << raft << ", Rand " << rand; // Afișarea detaliilor cărții
    std::cout << (disponibila ? " [Disponibil]" : " [Imprumutat]") << std::endl; // Afișarea disponibilității cărții
}

bool Carte::esteDisponibila() const { return disponibila; } // Returnează disponibilitatea cărții

void Carte::imprumuta() { disponibila = false; } // Setează cartea ca fiind împrumutată

std::string Carte::getTitlu() const { return titlu; } // Returnează titlul cărții