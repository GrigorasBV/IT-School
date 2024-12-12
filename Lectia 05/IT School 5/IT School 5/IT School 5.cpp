#include <iostream>


using namespace std;


int main()
{
   
    int* int_ptr{ nullptr };
    double* double_ptr{ nullptr };
    char* char_ptr{ nullptr };
    //string* string_ptr{ nullptr };

    cout << "|sizeof int_ptr:           |" << sizeof int_ptr << endl;
    cout << "|sizeof double_ptr:           |" << sizeof double_ptr << endl;
    cout << "|sizeof char_ptr:           |" << sizeof char_ptr << endl;
    //cout << "|sizeof string_ptr:           |" << sizeof string_ptr << endl;


    cout << "==============================" << endl;
    int num{ 10 };
     
    int_ptr = &num;

    cout << "valoarea lui num este:" << num << endl;
    cout << "sizeof num:" << sizeof num << endl;
    cout << "adresa lui num este: 0x" << &num << endl;

    int score{ 10 };
    double dscore{ 100.1 };

    cout << "==============================" << endl;

    int* score_ptr{ nullptr };
    score_ptr = &score;
    cout << "valaoare:" << score << endl;
    cout << "adresa of score" << &score << endl;

    *score_ptr = 200;

    cout << "valoarea lui score_ptr  " << *score_ptr << endl;

    cout << "==============================" << endl;

    double h{ 10.2 };
    double l{ 2.2 };

    double* t_ptr{ &h };

    cout << *t_ptr << endl;

    t_ptr = &l; 

    cout << *t_ptr << endl;

    cout << "==============================" << endl;
    
    string nume{ "Grigoras" };
    string* string_ptr{ &nume };

cout << *string_ptr << endl;

nume = "Vladut";

cout << *string_ptr << endl;


cout << "==============================" << endl;

int a = 10, b = 20;
int* a_ptr{ &a };
int* b_ptr{ &b };


cout << *a_ptr << " " << *b_ptr << endl;

a_ptr = &b;

b_ptr = &a;


cout << *a_ptr << " " << *b_ptr << endl;

cout << "==============================" << endl;

int scor[]{ 100, 95, 85 };
cout << scor << endl;
cout << *scor << endl;

int* scor_ptr{ scor };
cout << scor_ptr << endl;
cout << *scor_ptr << endl;

cout << scor_ptr[0] << endl;
cout << scor_ptr[1] << endl;
cout << scor_ptr[2] << endl;

cout << "sau" << endl;

cout << *scor_ptr << endl;
cout << *(scor_ptr + 1) << endl;
cout << *(scor_ptr + 2) << endl;

cout << &scor_ptr[0] << endl;
cout << &scor_ptr[1] << endl;
cout << &scor_ptr[2] << endl;

cout << "sau" << endl;

cout << scor_ptr << endl;
cout << (scor_ptr + 1) << endl;
cout << (scor_ptr + 2) << endl;


cout << "==============================" << endl;

int scorre[]{ 100, 95, 87, 68, -1 };

int* scorre_ptr{ scorre };

while (*scorre_ptr != -1) {
    cout << *scorre_ptr << endl;
    scorre_ptr++;
}

cout << "==============================" << endl;


int vec[]{ 10,15,20,48,30,40 };
int s = 0, i = 0;
int* vec_ptr{ vec };
int* s_ptr{ &s };
do {
    *s_ptr += *vec_ptr;
    vec_ptr++;
    i++;

} while (i <= 5);
cout << s << endl;
cout << "==============================" << endl;


int ax = 0;
int* const  ax_ptr{ &ax };
const int* ax_ptr1{ &ax };
const int* const ax_ptr2{ &ax };


cout << ax << endl;
cout << *ax_ptr << endl;

ax = 2;

cout << ax << endl;
cout << *ax_ptr1 << endl;
cout << *ax_ptr2 << endl;

return 0;
}
/* #include <iostream>  
    using namespace std;
    void swap(int* x, int* y) {
        int temp = *x;
        *x = *y;
        *y = temp;
    }
    int main() {
        int x = 8, y = 98;
        cout << &x << endl;
        cout << &y << endl;
        cout << "inainte de swap x = " << x << ", y = " << y << endl;
        swap(&x, &y);
        cout << "dupa x = " << x << ", y = " << y << endl;
        return 0;
    }
}*/