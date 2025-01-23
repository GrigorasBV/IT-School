#include <iostream>

using namespace std;

/*void swapval(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void swapref(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

void swapadd(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;

}
const in* k = nullptr;
int const* k = nullptr;
const const int* k = nullptr;



*/


int main()
{
		char f[20];

		cin >> f;

		int g = strlen(f);
		int i = 0;
		int j = g - 1;

		while (i < j && f[i] == f[j]) {
			i++;
			j--;
		}

		if (i == j)
			cout << f << " este palondrom";
		else
			cout << f << " nu este palindrom";
    return 0;
}