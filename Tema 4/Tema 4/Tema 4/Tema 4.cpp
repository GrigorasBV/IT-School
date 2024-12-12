#include <iostream>
#include <string>
using namespace std;

struct Carte {
    string titlu;
    string categorie;
    int rand;
    int raft;
    bool disponibila = true;
};

void sistemBiblioteca() {
    const int NUMAR_CARTI = 6;
    Carte biblioteca[NUMAR_CARTI] = {
        {"Dama cu camelii", "Beletristica", 1, 3},
        {"Ion", "Beletristică", 2, 2},
        {"Atomic Habits", "Dezvoltare personala", 1, 1},
        {"Thinking in C++", "Programare", 1, 1},
        {"Python Crash Course", "Programare", 1, 2},
        {"WebDev", "Programare", 2, 1}
    };

    while (true) {
        cout << "\n=== BIBLIOTECA ===\n";
        cout << "1. cauta carte\n";
        cout << "2. imprumuta carte\n";
        cout << "3. returneaza carte\n";
        cout << "4. inapoi la meniu principal\n";
        cout << "Alegeti optiunea: ";

        int optiune;
        cin >> optiune;

        if (optiune == 4) break;

        cout << "Introduceti titlul cartii: ";
        cin.ignore();
        string titlu;
        getline(cin, titlu);

        bool gasit = false;
        for (int i = 0; i < NUMAR_CARTI; ++i) {
            if (biblioteca[i].titlu == titlu) {
                gasit = true;
                switch (optiune) {
                case 1: //caut
                    cout << "Cartea se afla în categoria " << biblioteca[i].categorie
                        << ", randul " << biblioteca[i].rand
                        << ", raftul " << biblioteca[i].raft << endl;
                    cout << "Status: " << (biblioteca[i].disponibila ? "disponibila" : "imprumutata") << endl;
                    break;

                case 2: // imprumut
                    if (biblioteca[i].disponibila) {
                        biblioteca[i].disponibila = false;
                        cout << "Carte imprumutata cu succes!\n";
                    }
                    else {
                        cout << "Cartea este deja imprumutata!\n";
                    }
                    break;

                case 3: // Returnare
                    if (!biblioteca[i].disponibila) {
                        biblioteca[i].disponibila = true;
                        cout << "Carte returnata cu succes!\n";
                        cout << "Asezat cartea la categoria " << biblioteca[i].categorie
                            << ", randul " << biblioteca[i].rand
                            << ", raftul " << biblioteca[i].raft << endl;
                    }
                    else {
                        cout << "Aceasta care nu era imprumutata!\n";
                    }
                    break;
                }
                break;
            }
        }
        if (!gasit) {
            cout << "Cartea nu exista in bibloteca!\n";
        }
    }
}

void alegeriPrezidentiale() {
    int voturi[5] = { 0 };
    int totalVoturi = 0;
    int vot;

    cout << "\n=== ALEGERI PREZIDENȚIALE ===\n";
    cout << "Introduceti numarul candidatului (1-5) sau 0 pentru a termina\n";

    while (true) {
        cout << "\nVot (0 pentru terminare): ";
        cin >> vot;

        if (vot == 0) break;

        if (vot >= 1 && vot <= 5) {
            voturi[vot - 1]++;
            totalVoturi++;
        }
        else {
            cout << "Vot invalid!\n";
        }
    }

    if (totalVoturi > 0) {
        cout << "\nRezultate:\n";
        int castigator = 0;
        for (int i = 0; i < 5; i++) {
            float procent = (float)voturi[i] / totalVoturi * 100;

            cout << "Candidat " << i + 1 << ": " << procent << "% (" << voturi[i] << " voturi)\n";
            if (voturi[i] > voturi[castigator]) {
                castigator = i;
            }
        }
        cout << "\nCastigator: Candidat " << castigator + 1 << endl;

    }
    else {
        cout << "Nu s-au înregistrat voturi!\n";

    }
}

int main() {
    while (true) {
        cout << "\n=== MENIU PRINCIPAL ===\n";
        cout << "1. Biblioteca\n";
        cout << "2. Alegeri Prezidentiale\n";
        cout << "3. Iesire\n";
        cout << "Alegeti optiunea: ";

        int optiune;
        cin >> optiune;

        switch (optiune) {
        case 1:
            sistemBiblioteca();
            break;
        case 2:
            alegeriPrezidentiale();
            break;
        case 3:
            cout << "La revedere!\n";
            return 0;
        default:
            cout << "Optiune invalida!\n";
        }
    }
    return 0;
}