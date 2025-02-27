#include <iostream>

using namespace std;

// Structura nod
struct nod {
	int data;
	nod* next;
	nod* prev;

	// Constructor
	nod(int val) : data(val), next(nullptr), prev(nullptr) {}
};

// Clasa lista dublu-înlănțuită
class lista {
	nod* head;
	nod* tail;
public:
	// Constructor
	lista() : head(nullptr), tail(nullptr) {}

	// Metodă pentru adăugarea unui nod la sfârșitul listei
	void adauga(int val) {
		nod* temp = new nod(val);
		if (!head) {
			head = temp;
			tail = temp;
		}
		else {
			tail->next = temp;
			temp->prev = tail;
			tail = temp;
		}
	}

	// Metodă pentru afișarea elementelor listei
	void afisare() {
		nod* temp = head;
		while (temp) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}

	// Metodă pentru ștergerea unui nod din listă
	void sterge(int val) {
		nod* temp = head;
		while (temp) {
			if (temp->data == val) {
				if (temp->prev) {
					temp->prev->next = temp->next;
				}
				else {
					head = temp->next;
				}
				if (temp->next) {
					temp->next->prev = temp->prev;
				}
				else {
					tail = temp->prev;
				}
				delete temp;
				return;
			}
			temp = temp->next;
		}
	}
};

int main() {
	// Crearea unei liste și adăugarea unor elemente
	lista l;
	l.adauga(1);
	l.adauga(2);
	l.adauga(3);
	l.afisare(); // Output: 1 2 3

	// Ștergerea unui element din listă
	l.sterge(2);
	l.afisare(); // Output: 1 3

	return 0;
}