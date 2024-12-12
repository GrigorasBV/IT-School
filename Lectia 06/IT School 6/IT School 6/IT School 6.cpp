#include <iostream>
using namespace std;


const char* clasa[3] = { "Grigoras", "Bogdan", "Vladut"};

int main()
{

    if (clasa[0] == "Grigoras" && clasa[1] == "Bogdan" && clasa[2] == "Vladut")
                cout << "Prezenta Full" << endl;
    else 
        if (clasa[0] == "Grigoras" || clasa[1] == "Bogdan" || clasa[2] == "Vladut")
                cout << "Partial" << endl;
    else
                cout << "Nimeni " << endl;

	return 0;
}
