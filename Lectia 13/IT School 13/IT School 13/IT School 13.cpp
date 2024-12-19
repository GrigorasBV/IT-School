#include <iostream>

using namespace std;

class moveClass {
private:
	int* p;
public:
	moveClass(int d) {
		p = new int;
		*p = d;
		cout << "Constructorul default este apelat " << d << endl;
	};
	moveClass(moveClass&& source)
		:p{ source.p }
	{
		cout << "Constructorul move este apelat pentru " << *source.p << endl;
		source.p = nullptr;
	}
	~moveClass() {
		cout << "Destructor release memory " << endl;
	}
};
class pointerThis {
private:
	int x;
	int y;
public:
	void setX(int x,int y)
	{
		this->x = x;
		this->y = y;
	}
	void print() {
		cout << " x= " << x << endl;
		cout << " y= " << y << endl;
	}
	void sum() {
		cout << "Suma= " << x + y << endl;
	}
};
int main()
{
	pointerThis obj1;
	int x = 100;
	int y = 200;
	obj1.setX(x,y);
	obj1.print();
	obj1.sum();


	return 0;
}