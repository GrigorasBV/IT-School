#include <iostream>
#include <string>;

using namespace std;

void rez_1() {
	int n;
	int a[100];
	int* a_ptr = a;

	cout << "Cate elemente trebuie sa contina array-ul a? " << endl;
	cin >> n;
	if (n < 0 || n>100) cout << "n trebuie sa apartina intervalului 1-100 " << endl;
	else {
		for (int i = 0; i < n; i++)
		{
			if (i != n - 1) {
				cout << "Elementul " << i+1 << " este ";
				cin >> a[i];
				cout << endl;
			}
			else {
				cout << "Ultimul element este ?" << endl;
				cin >> a[i];
			}
		}
		cout << "Elemntele introduse sunt ";

		for (int i = 0; i < n; i++)
			cout << *(a_ptr + i) << " ";
	}
	cout << endl;
}
void rez_2() {
	int b,p = 1;
	int* b_ptr = &b;

	cout << "Introduceti un numar intreg pozitiv si diferit de 0 ";
	cin >> b;

	if (*b_ptr != 0) {
		for (int i = 1; i <= *b_ptr; i++)
			p *= i;
	}
	else cout << "Numarul nu respecta conditiile";

	cout << "Factorialul lui " << b << " este " << p;
	}
void rez_3() {
	int var_1 = 0, var_2 = 0, var_3;
	char sir[100],vocale[]="aeiouAEIOU";
	cout << "Introduceti sirul de caractere " << endl;
	cin.getline(sir,100);
	var_3 = strlen(sir);
	for (int i = 0; i < var_3; i++)
		if (strchr(vocale, sir[i]))
			var_1++;
		else var_2++;
	cout << "Sirul contine " << var_1 << " vocale si " << var_2 << " consoane" << endl;
}
void rez_4() {
		int n,aux;
		int a[100];
		int* a_ptr = a;

		cout << "Cate elemente trebuie sa contina array-ul a? " << endl;
		cin >> n;
		if (n < 0 || n>100) cout << "n trebuie sa apartina intervalului 1-100 " << endl;
		else {
			for (int i = 0; i < n; i++)
			{
				if (i != n - 1) {
					cout << "Elementul " << i + 1 << " este ";
					cin >> a[i];
					cout << endl;
				}
				else {
					cout << "Ultimul element este ?" << endl;
					cin >> a[i];
				}
			}
			cout << "Elemntele introduse sunt ";

			for (int i = 0; i < n; i++)
				for(int j=0;j<n-i-1;j++)
				if (a[j]>a[j+1])
				{
					aux = a[j];
					a[j] = a[j + 1];
					a[j + 1] = aux;

				}


			for (int i = 0; i < n; i++)
				cout << *(a_ptr + i) << " ";
		}
		cout << endl;
	}


int main()
{
	rez_4();
	rez_3();
	rez_2();
	rez_1();

	return 0;
}