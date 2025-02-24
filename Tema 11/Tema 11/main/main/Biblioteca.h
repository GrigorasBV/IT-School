#pragma once
#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include "IBiblioteca.h"
#include "Carte.h"
#include <vector>

class Biblioteca : public IBiblioteca {
private:
    std::vector<Carte> carti; // Vector pentru stocarea cărților
public:
    void adaugaCarte(const std::string& titlu, const std::string& autor, int an, const std::string& categorie, int rand, int raft) override; // Adăugarea unei cărți
    void imprumutaCarte(const std::string& titlu) override; // Împrumutarea unei cărți
    void afiseazaCarti() const override; // Afișarea cărților
};

#endif // BIBLIOTECA_H