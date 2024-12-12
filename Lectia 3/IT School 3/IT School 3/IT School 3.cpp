#include <iostream>
using namespace std;

int main()
{
	/*int i, n, a, b;
	cout << "Introduceti limita inferioara a intervalului " << endl;
	cin >> a;
	cout << "Introduceti valoarea superioara a intervalului"<< endl;
	cin >> b;
	cout << "Introduceti numarul pe care doriti sa il verificati "<< endl;
	cin >> n;
	i = 0;
	bool ok = true;

	while (ok!=0) {
		if (a < n && n < b) {
			cout  << " APARTINE INTERVALULUI "<<a<<"_"<<b << endl;
			ok = false;
		}
		else {
			cout << " NU APARTINE INTERVALULUI "<<a<<"_"<<b << endl;
			ok = false;
		}
	}*/
	int  n, j, i, a[30][30]{};

	do {
		cin >> n;
		if (n == 1) {
			for (i = 1; i <= 5; i++)
				for (j = 1; j <= 5; j++)
					if (i != j)cout << a[i][j] << " ";
					else cout << a[i][j] << " " << endl;
		}
		else if (n == 2) {
			for (i = 1; i <= 10; i++)
				for (j = 1; j <= 10; j++)
					cout << a[i][j] << "_";
		}
		else if (n == 3) {
			for (i = 1; i <= 15; i++)
				for (j = 1; j <= 15; j++)
					cout << a[i][j] << "_";
		}
		else cout << "nu avem acest caz";

	} while (n == 1 || n == 2 || n == 3);


	return 0;
}
