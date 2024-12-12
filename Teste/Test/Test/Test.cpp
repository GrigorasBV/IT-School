#include <iostream>

using namespace std;

int main()
{

	int n, c, ogl=0;

	cin >> n;

	while (n != 0) {
		c = n % 10;
		if (c % 2 == 1) ogl =ogl*10+ c * 10 + c;
		else ogl = ogl * 10 + c;
		n /= 10;
		cout << ogl << endl;
	}

	cout << ogl;
	return 0;

}
