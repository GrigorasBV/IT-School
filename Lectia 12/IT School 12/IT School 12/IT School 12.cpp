#include <iostream>
#include <vector>
#include <string>

using namespace std;


/*class Shallow {
private:
    int* data;                          //pointer
public:
    void set_data_value(int d) { *data = d; }
    int get_data_value() { return *data; }

    Shallow(int d);                  //constructor
    Shallow(const Shallow& source); //copy
    ~Shallow();                    //destructor                 
};

Shallow::Shallow(int d) {
    data = new int;                 //alocare de  memorie
    *data = d;
}
Shallow::Shallow(const Shallow &source) 
    :data(source.data){
cout << "destructor release data " << endl;
}
Shallow::~Shallow() {
    delete data;
    cout << "destructor eliberator data" << endl;
}
void display_shallow(Shallow s) {
    cout << s.get_data_value() << endl;
}*/

class Deep {
private:
    int* data;
public:
    void set_data_value(int d) { *data = d; }
    int get_data_value() { return *data; }
    Deep(int d);
    Deep(const Deep& source);
    ~Deep();
};
Deep::Deep(int d) {
    data = new int;
    *data = d;
}
Deep::Deep(const Deep& source)
    :Deep(*source.data) {
    cout << "destructor realese data-deep copy" << endl;
}
Deep::~Deep() {
    delete data;
    cout << "destructor eliberator data" << endl;
}
void display_deep(Deep s) {
    cout << s.get_data_value() << endl;
}




int main()
{
  /*  Shallow obj1(100);
    display_shallow(obj1);

    Shallow obj2(obj1);
    obj2.set_data_value(1000);

    */
    Deep obj1(100);
    display_deep(obj1);

    Deep obj2(obj1);
    obj2.set_data_value(1000);

    
    return 0;
}
class Move {
private:
    int* data; //raw pointer
public:
    void set_data_value(int d) { *data = d }
    int get_data_value() { return *data; }
    Move(int d);
    Move(const Move& source);
    ~Move();
};
Move::Move(const Move& source) {
    data = *new int;
    *data = *source.data;
}