#pragma once
#ifndef IBIBLIOTECA_H
#define IBIBLIOTECA_H

#include <string>

class IBiblioteca {
public:
    virtual void adaugaCarte(const std::string& titlu, const std::string& autor, int an, const std::string& categorie, int rand, int raft) = 0; // Metodă virtuală pură pentru adăugarea unei cărți
    virtual void imprumutaCarte(const std::string& titlu) = 0; // Metodă virtuală pură pentru împrumutarea unei cărți
    virtual void afiseazaCarti() const = 0; // Metodă virtuală pură pentru afișarea cărților
    virtual ~IBiblioteca() {} // Destructor virtual
};

#endif // IBIBLIOTECA_H