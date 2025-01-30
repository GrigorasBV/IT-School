#include <iostream>
#include <string>
#include <vector>

using namespace std;

class base {
private:
	int value;
public:
	base() : value(0) {
		cout << "Base no arg constructor" << endl;
	}
	base(int x) :value{ x } { cout << "Base overloaded constructor" << endl; }
	~base() { cout << "Base destructor" << endl; }
	};
class derived : public base {
private:
	int doubled_value;
public:
	derived(): base{} , doubled_value{0} { cout << "Derived no arg constructor" << endl; }
	derived(int x) :base{x} , doubled_value{x * 2} { cout << "Derived overloaded constructor" << endl; }
	~derived() { cout << "Derived destructor" << endl; }
};



int main()
{
	base obj1;
	//base obj2{ 1000 };

	derived obj3;	
	//derived obj4{ 1000 };

	return 0;
}