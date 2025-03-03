#include <iostream>
#include <memory>

using namespace std;


/*class Test {
private:
	int data;

public:
	Test() : data(0) { cout << "\tTest constructor (" << data << ")" << endl; }
	Test(int data) : data(data) { cout << "\tTest constructor (" << data << ")" << endl; }
	int getData() const { return data; }
~Test() { cout << "\tTest destructor (" << data << ")" << endl; };

int main()
{
	//Test* t1 = new Test{ 1000 };
	//delete t1;



	unique_ptr<Test> t1 = make_unique<Test>(1000);
	unique_ptr<Test> t2 = make_unique<Test>(1000);

	shared_ptr<Test> t3 = make_shared<Test>(1000);
	cout << t3.use_count() << endl;

	p1.reset();

	cout << t3.use_count() << endl;


	return 0;
}*/

class myClass {
public:
	myClass() { cout << "Constructor" << endl; }
	~myClass() { cout << "Destructor" << endl; }

	void say_hello() { cout << "Hello" << endl; }
};


int main() {

	shared_ptr<myClass> sharedPTR = make_shared<myClass>(); // Constructor
	weak_ptr<myClass> weakPTR = sharedPTR;


	cout << "sharedPTR use cout" << sharedPTR.use_count() << endl; // 1

	shared_ptr<myClass>lokedPTR = weakPTR.lock();


	if (lokedPTR) {
		lokedPTR->say_hello();
		cout << "sharedPTR use cout" << sharedPTR.use_count() << endl; // 2
	}
	else {
		cout << "Pointer is expired" << endl;
	}
	sharedPTR = weakPTR.lock();
	if (lokedPTR) {
		cout << "lokedPTR este valid" << endl;
	}
	else {
		cout << "lokedPTR este invalid" << endl;

	}
	return 0;
}