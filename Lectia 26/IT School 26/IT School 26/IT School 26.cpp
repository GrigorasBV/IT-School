#include <iostream>
using namespace std;

// Definirea structurii unui nod al listei 

struct Node {
	int data; // valoarea stocata in nod
	Node* next; // pointer catre urmatorul nod



	// constructor pentru a initializa nodul
	Node(int val) :data(val), next(nullptr) {}
};

//Clasa pentru lista simplu inlantuita
class LinkedList {
public:
    Node* head; // capul listei (primul nod)

    //Constructorul clasei
    LinkedList() :head(nullptr) {}

    //Adaugarea unui nod la inceputul listei
    void apend(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    //Adaugarea unui nod la sfarsitul listei


    //metoda pentru a copia lista intr o alta lista

    LinkedList copy() {
        LinkedList newList;
        Node* temp = head;
        while (temp != nullptr) {
            newList.apend(temp->data);//adauga valoarea nodului in lista noua
            temp = temp->next;
        }
        return newList;
    }
    int* toArray(int& size) {
        size = 0;
        Node* temp = head;
        while (temp != nullptr) {
            size++;
            temp = temp->next;
        }
        int* arr = new int[size];
        temp = head;
        for (int i = 0; i < size; i++) {
            arr[i] = temp->data;
            temp = temp->next;
        }
        return arr;

    }

    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    // destructor pentru a elibera memoria
    ~LinkedList() {
        Node* temp = head;
        while (head != nullptr) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }
};



int main() {

	LinkedList list;
	list.apend(10);
	list.apend(20);
	list.apend(30);
	list.apend(40);

	list.print();

	LinkedList lista2 = list.copy();
	lista2.print();

    int size = 0;
	int* arr = list.toArray(size);

	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}



    return 0;
}





/*
struct Nod {
    int data;                         //valoarea stocata in nod
    Nod* next;                        //pointer catre urmatorul nod
    Nod* prev;                          //pointer catre nodul anterior

    //constructor pentru a initializa nodul
    Nod(int val) :data(val), next(nullptr), prev(nullptr) {}
};


class Lista {
private:
    Nod* head;        //capul listei (primul nod)
    Nod* tail;        //coada listei(ultimul nod)

public:
    //constructor pentru a initializa lista
    Lista() :head(nullptr), tail(nullptr) {}


    void adaugareinceput(int val) {
        Nod* nouNod = new Nod(val);
        if (!head) {
            head = tail = nouNod;    //daca lisat este goala, capul si coada devin noul nod
        }
        else {
            nouNod->next = head;
            head->prev = nouNod;
            head = nouNod;        //actualizaeaza capul listei
        }
    }

    void adaugare_sfarsit(int val) {
        Nod* nouNod = new Nod(val);
        if (!tail) {
            head = tail = nouNod;    //daca lisat este goala, capul si coada devin noul nod
        }
        else {
            tail->next = nouNod;
            nouNod->prev = tail;
            tail = nouNod;         //actualizaeaza coada listei
        }
    }

    void stergere(int val) {
        if (!head)return;     //DACA LISTA ESTE GOALA, NU exista nimic de sters


        //cautam nodul cu valodare specificata
        Nod* temp = head;
        while (temp && temp->data != val) {
            temp = temp->next;    //mergi la urmatorul nod
        }

        if (!temp)return;   //daca nu s a gasit valoarea in lista, iesim

        //Daca nodul pe care vrem sa il stergem este capul
        if (temp == head) {
            head = head->next;
            if (head)head->prev = nullptr; //actualizeaza next pentru capul listei
        }

        //Daca nodul pe care vrem sa il stergem este coada
        if (temp == tail) {
            tail = tail->next;
            if (tail)tail->next= nullptr; //actualizeaza next pentru coada listei
        }


        //daca nodul sters este la mijlocul listei
        if (temp->prev) temp->prev->next = temp->next;
        if (temp->next)temp->next->prev = temp->prev;

        delete temp; //eliberam memoria
    }

    void afisare() {
        Nod* temp = head;
        while (temp) {
            cout << temp->data << endl;  //afisaza valoarea nodului
            temp = temp->next;         //mergi la nodul urmator
        }
    }

    ~Lista() {
        Nod* temp = head;
        while (temp) {
            Nod* next = temp->next;
            delete temp;
            temp = next;
        }
    }

};


int main() {


    Lista lista;

    lista.adaugare_sfarsit(10);
    lista.adaugare_sfarsit(20);
    lista.adaugare_sfarsit(30);
    lista.adaugare_sfarsit(40);
    lista.adaugareinceput(5);

    lista.afisare();

    lista.stergere(20);

    lista.afisare();

    return 0;
}
*/




















/*
struct Nod {
    int data;                         //valodare stocata in nod
    Nod* next;                        //pointer catre urmatorul nod


    //constructor pentru a initializa nodul
    Nod(int val):data(val), next(nullptr){}
};


class Lista {
private:
    Nod* head;

public:
Lista():head(nullptr){}


void adaugareinceput(int val) {

    Nod* nouNod = new Nod(val);
    nouNod->next = head;        //noul nod indica spre vechiul cap al listei
    head = nouNod;              //noul nod devide capul listei
}


void adaugaresfarsit(int val) {
    Nod* nouNod = new Nod(val);
    if (!head) {
        head = nouNod;        //daca lista este goala, noul nod devine capul listei
    }
    else {
        Nod* temp = head;
        while (temp->next) {
            temp = temp->next;   ///mergi la ultimul nod
        }
        temp->next = nouNod; //adauga noul nod la finalul listei
    }

}


void stergere(int val){
    if (!head)return;    //daca lista este goala, nu exista nimic de sters

    if (head->data == val) {
        Nod* temp = head;
        head = head->next;  //muta capul listei la urmatorul nod
        delete temp;        //eliberam memoria
        return;
    }

    Nod* temp = head;
    while (temp->next && temp->next->data != val) {
        temp = temp->next;                      //mergi prin lista pentru a gasi nodul cu valoarea
    }

    //daca am gasit nodul cu valoare de sters
    if (temp->next) {
        Nod* nod_sters = temp->next;
        temp->next = temp->next->next;     //sterge nodul gasit
        delete nod_sters;                  //eliberam memoria
    }
}

void afisare() {
    Nod* temp = head;
    while (temp) {
        cout << temp->data << endl;  //afisaza valoarea nodului
        temp = temp->next;         //mergi la nodul urmator
    }
}

//destructor pentru a elibera memoria
~Lista() {
    Nod* temp = head;
    while (temp) {
        Nod* next = temp->next;
        delete temp;
        temp = next;
    }
}
};

int main() {
    Lista lista;

    lista.adaugaresfarsit(10);
    lista.adaugaresfarsit(20);
    lista.adaugaresfarsit(50);
    lista.adaugareinceput(2);


    lista.afisare();

    lista.stergere(20);

    lista.afisare();

    return 0;
}
*/

















/*
/// exemplu lista simplu inlantuita.....putem sa parcurgem intr o singura directie

struct  Node {
    int date;       //datele stocate in nod
    Node* next;     //pointer catre urmatorul nod
    Node* prev;     //pointer catre nodul anterior

    Node(int val) :date(val), next(nullptr), prev(nullptr) {}
};


//clasa care reprezinta lista
class listadubluinlantuita {
private:
    Node* head; //primul nod din lista
    Node* tail; //pointer catre nodul anterior

public:
    listadubluinlantuita() :head(nullptr), tail(nullptr) {}

    //adaugam un nod la sfarsitul listei
    void adaugaresf(int value) {
        Node* newNode = new Node(value);     //cream un nou nod
        if (head == nullptr) {
            head = tail = newNode;                  //daca lista este goala, head si tail sunt acelasi nod
        }
        else {
            tail->next = newNode;            //legam nodul existent de noul nod
            newNode->prev = tail;            //setam poinetrul prev al noului nod
            tail = newNode;                  //actualizam coada
        }
    }


    //afisare lista de la inceput la sfarsit
    void printcrescator()const {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->date << "->";
            temp = temp->next;
        }
        cout << "nullptr" << endl;            //sfarsitul listei
    }

    //afisare lista sfarsit la inceput
    void printdescrescator()const {
        Node* temp = tail;
        while (temp != nullptr) {
            cout << temp->date << "->";
            temp = temp->prev;
        }
        cout << "nullptr" << endl;            //sfarsitul listei
    }



    //destructor pentru a elibera memoria

    ~listadubluinlantuita() {
        Node* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};


int main() {
    listadubluinlantuita lista;

    lista.adaugaresf(10);
    lista.adaugaresf(20);
    lista.adaugaresf(30);


    cout <<  "lista dublu inlantuita(de la inceput la sfarsit):";
    lista.printcrescator();

    cout << "lista dublu inlantuita(de la sfarsit la inceput):";
    lista.printdescrescator();

    return 0;
    };
*/