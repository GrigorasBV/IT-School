#include <iostream>
#include "persoana.h"
#include "test.h"

using namespace std;

struct node {
    int date;  //datele stocate in nod
    node* next;  //pointer catre urmatorul nod

    node(int val) : date(val), next(nullptr) {}
};

//clasa lista

class lista_inlantuita {
private:
    node* head; //pointer catre primul nod din lista
public:
    lista_inlantuita() : head(nullptr) {}

    void adaugare(int val) {
        node* newnode = new node(val);  //creare nod nou
        if (head == nullptr) {
            head = newnode; //daca lista este goala, noul nod devine primul nod
        } else {
            node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;   //parcurgem lista pana la ultimul nod
            }
            temp->next = newnode;  //legam noul nod la ultimul nod
        }
    }

    void afisare() {
        node* temp = head;
        while (temp != nullptr) {
            cout << temp->date << " ";
            temp = temp->next;
        }
        cout << "nullptr" << endl; // afisare nullptr cand ajungem la finalul listei
    }

    ~lista_inlantuita() {
        node* temp = head;
        while (temp != nullptr) {
            node* next = temp->next;
            delete temp;
            temp = next;
        }
        head = nullptr;
    }
};

struct dnode {
    int date;  //datele stocate in nod
    dnode* next;  //pointer catre urmatorul nod
    dnode* prev;  //pointer catre nodul anterior

    dnode(int val) : date(val), next(nullptr), prev(nullptr) {}
};

//clasa lista

class lista_dublainlantuita {
private:
    dnode* head; //pointer catre primul nod din lista
public:
    lista_dublainlantuita() : head(nullptr) {}

    void adaugare(int val) {
        dnode* newnode = new dnode(val);  //creare nod nou
        if (head == nullptr) {
            head = newnode; //daca lista este goala, noul nod devine primul nod
        } else {
            dnode* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;   //parcurgem lista pana la ultimul nod
            }
            temp->next = newnode;  //legam noul nod la ultimul nod
            newnode->prev = temp;  //setam pointerul prev al noului nod
        }
    }

    void afisare() {
        dnode* temp = head;
        while (temp != nullptr) {
            cout << temp->date << " ";
            temp = temp->next;
        }
        cout << "nullptr" << endl; // afisare nullptr cand ajungem la finalul listei
    }

    ~lista_dublainlantuita() {
        dnode* temp = head;
        while (temp != nullptr) {
            dnode* next = temp->next;
            delete temp;
            temp = next;
        }
        head = nullptr;
    }
};

int main() {
    cout << "================================================================" << endl;
    cout << "TESTAREA CLASEI LISTA INLANTUITA" << endl;

    lista_inlantuita lista;
    lista.adaugare(10);
    lista.adaugare(20);
    lista.adaugare(30);
    lista.adaugare(40);
    lista.adaugare(50);

    lista.afisare();

    cout << "================================================================" << endl;

    cout << "TESTAREA CLASEI LISTA DUBLAINLANTUITA" << endl;

    lista_dublainlantuita dlista;
    dlista.adaugare(10);
    dlista.adaugare(20);
    dlista.adaugare(30);
    dlista.adaugare(40);
    dlista.adaugare(50);

    dlista.afisare();

    cout << "================================================================" << endl;

    Student studentpoli("Ion");
    studentpoli.promoveaza();

    Mystring x{ "SALUT" };
    x = Mystring{ "Bonjour" };
    x = "Calimera";

    Mystring a{ "hello" };          //overload constructor
    Mystring b;                     //no-arg constructor
    b = a;                          //copy assignment
    //b.operator=(a)
    b = "acesta este un test";      //b.operator=("acesta este un test")

    Mystring empty;                 //no-arg constructor
    Mystring lavinia("Lavinia");    //overload constructor
    Mystring BMW{ "bmw" };

    Mystring opel;                  //no-arg constructor
    empty = BMW;                    //copy assignment operator

    empty.display();
    lavinia.display();
    BMW.display();

    Mystring alin{ "Alin" };
    Mystring itschool{ "ITSchool" };

    Mystring stooge = alin;
    alin.display();
    itschool.display();

    std::cout << (alin == itschool) << std::endl;
    std::cout << (alin == stooge) << std::endl;

    alin.display();
    Mystring alin2 = -alin;
    alin2.display();

    Mystring stooges = alin + "ALIN";
    //Mystring stooges = "alin" + "ITSchool";     //compiler error

    Mystring two_stooges = alin + "" + "ALIN";
    two_stooges.display();

    return 0;
}