#include <iostream>
#include <string>
using namespace std;

// Structura pentru a reprezenta un produs
struct Product {
    string name;
    double price;
    int quantity;
    Product* next;
    Product(string n, double p, int q) : name(n), price(p), quantity(q), next(nullptr) {}
};

class ProductList {
private:
    Product* head;

public:
    ProductList() : head(nullptr) {}

    void addProduct(string name, double price, int quantity) {
        Product* newProduct = new Product(name, price, quantity);
        if (!head) {
            head = newProduct;
            return;
        }
        Product* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newProduct;
    }

    void displayProducts() {
        Product* temp = head;
        while (temp) {
            cout << "Nume: " << temp->name << ", Pret: " << temp->price << ", Cantitate: " << temp->quantity << endl;
            temp = temp->next;
        }
    }

    ProductList copyList() {
        ProductList newList;
        Product* temp = head;
        while (temp) {
            newList.addProduct(temp->name, temp->price, temp->quantity);
            temp = temp->next;
        }
        return newList;
    }

    void deleteProduct(string name) {
        if (!head) return;
        if (head->name == name) {
            Product* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Product* temp = head;
        while (temp->next && temp->next->name != name) {
            temp = temp->next;
        }
        if (temp->next) {
            Product* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
    }

    Product* searchProduct(string name) {
        Product* temp = head;
        while (temp) {
            if (temp->name == name)
                return temp;
            temp = temp->next;
        }
        return nullptr;
    }

    void updateQuantity(string name, int newQuantity) {
        Product* product = searchProduct(name);
        if (product)
            product->quantity = newQuantity;
    }

    void sortByPrice() {
        if (!head || !head->next) return;
        bool swapped;
        do {
            swapped = false;
            Product* temp = head;
            while (temp->next) {
                if (temp->price > temp->next->price) {
                    swap(temp->name, temp->next->name);
                    swap(temp->price, temp->next->price);
                    swap(temp->quantity, temp->next->quantity);
                    swapped = true;
                }
                temp = temp->next;
            }
        } while (swapped);
    }
};

int main() {
    ProductList list;
    list.addProduct("Laptop", 3000, 5);
    list.addProduct("Mouse", 100, 20);
    list.addProduct("Monitor", 800, 10);

    cout << "Lista de produse initiala:" << endl;
    list.displayProducts();

    list.sortByPrice();
    cout << "\nLista sortata dupa pret:" << endl;
    list.displayProducts();

    list.updateQuantity("Mouse", 25);
    cout << "\nLista dupa actualizarea cantitatii Mouse:" << endl;
    list.displayProducts();

    list.deleteProduct("Monitor");
    cout << "\nLista dupa stergerea Monitorului:" << endl;
    list.displayProducts();

    return 0;
}
