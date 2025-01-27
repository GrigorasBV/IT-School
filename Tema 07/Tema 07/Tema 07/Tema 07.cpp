#include <iostream>
#include <string>
#include <vector>
#include <utility>

// 1. Implementarea clasei MyClass
class MyClass {
private:
    std::string name;
    std::vector<int> data;

public:
    // Constructor standard
    MyClass(const std::string& n, int size) : name(n), data(size, 0) {
        std::cout << "Constructor standard apelat" << std::endl;
    }

    // Constructor delegat
    MyClass(const std::string& n) : MyClass(n, 10) {
        std::cout << "Constructor delegat apelat" << std::endl;
    }

    // Constructor de mutare
    MyClass(MyClass&& other) noexcept : name(std::move(other.name)), data(std::move(other.data)) {
        std::cout << "Constructor de mutare apelat" << std::endl;
    }

    // Metodă de afișare
    void print() const {
        std::cout << "Nume: " << name << "\nDate: ";
        for (int value : data) {
            std::cout << value << " ";
        }
        std::cout << "\n";
    }
};

// 2. Implementarea clasei Point
class Point {
private:
    int x, y;

public:
    // Constructor
    Point(int xCoord, int yCoord) : x(xCoord), y(yCoord) {}

    // Supraincarcarea operatorului +
    Point operator+(const Point& other) const {
        return Point(x + other.x, y + other.y);
    }

    // Metodă de afișare
    void print() const {
        std::cout << "Point(" << x << ", " << y << ")\n";
    }
};

// 3. Exemplu de constructor de copiere
class MyClassWithCopy {
private:
    int* value;

public:
    // Constructor implicit
    MyClassWithCopy(int v) : value(new int(v)) {}

    // Constructor de copiere
    MyClassWithCopy(const MyClassWithCopy& other) : value(new int(*other.value)) {
        std::cout << "Constructor de copiere apelat" << std::endl;
    }

    // Destructor
    ~MyClassWithCopy() {
        delete value;
    }

    // Metodă de afișare
    void print() const {
        std::cout << "Valoare: " << *value << "\n";
    }
};

int main() {
    // Test pentru 1. MyClass
    MyClass obj1("Test", 5); // Constructor standard
    obj1.print();

    MyClass obj2("AnotherTest"); // Constructor delegat
    obj2.print();

    MyClass obj3 = std::move(obj1); // Constructor de mutare
    obj3.print();

    // Test pentru 2. Point
    Point p1(3, 4);
    Point p2(1, 2);
    Point p3 = p1 + p2; // Supraincarcarea operatorului +
    p3.print();

    // Test pentru 3. Constructor de copiere
    MyClassWithCopy objA(42);
    objA.print();

    MyClassWithCopy objB = objA; // Constructor de copiere
    objB.print();

    return 0;
}
