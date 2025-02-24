#pragma once
#ifndef CARTE_H
#define CARTE_H

#include <string>

class Carte {
private:
    std::string titlu, autor, categorie; // Atribute pentru titlu, autor și categorie
    int anPublicare, rand, raft; // Atribute pentru anul publicării, rând și raft
    bool disponibila; // Atribut pentru disponibilitatea cărții

public:
    Carte(std::string t, std::string a, int an, std::string cat, int r, int rf); // Constructor pentru inițializarea unei cărți
    void afiseaza() const; // Metodă pentru afișarea detaliilor cărții
    bool esteDisponibila() const; // Metodă pentru verificarea disponibilității cărții
    void imprumuta(); // Metodă pentru împrumutarea cărții
    std::string getTitlu() const; // Metodă pentru obținerea titlului cărții
};

#endif // CARTE_H