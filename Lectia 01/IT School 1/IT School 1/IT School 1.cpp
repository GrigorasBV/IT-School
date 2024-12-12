// IT School 1.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>
#include <string>


using namespace std;

int my_func_ex1(int a ) {
    int my_number = a ;//atribuire valoare 50 ex1
    ++my_number;//incrementare ex3
    return my_number;
}

float my_func_ex2(float my_number_1) {
   my_number_1 = 76.5;//atribuire valoare 75.5 ex 2
   --my_number_1;//decrementare ex3
   return my_number_1;
}
int my_func_ex10_1(int ax, int bx, int cx) {
    if (ax < bx && ax < cx) {
        return ax;
    }
    else if (bx < ax && bx < cx) {
        return bx;
    }
    else {
        return cx;
    }
}
float my_func_ex10_2(float ay,float by,float cy) {
    if (ay > by && ay > cy) {
        return ay;
    }
    else if (by > ay && by > cy) {
        return by;
    }
    else {
        return cy;
    }
}


int main(){

    int a=49,sum_1,ax=7,bx=9,cx=3,rx;
    double b, sum_2, rest_1,ay=72.3,by=1387.12,cy=6,ry;

    const float d = 23.6;

    a = my_func_ex1(a);
    b = my_func_ex2(0.0);
    rx = my_func_ex10_1(ax, bx, cx);
    ry = my_func_ex10_2(ay, by, cy);
    string nume = "Grigoras ";
    string prenume = "Bogdan Vladut";
    string nume_complet = nume + prenume;
    string sirul_meu = "Acesta este continutul initial al sirului";

    sum_1 = a + b;
    sum_2 = a + b;
    rest_1 = ((sum_2 * 5) / 12)-((sum_1 * 5) / 12);//ex5;

    cout <<"numarul incrementat "<< a << " " << " numarul decrementat " << b << endl;
    cout << sum_1 << " de tip int" << endl;// ex4
    cout << sum_2 << " de tip float" << endl;// ex4
    cout << rest_1 << " partea fractionala" << endl;// ex5
    cout << nume_complet << endl;// ex6 7 8 
    cout << sirul_meu << endl;//ex9
    cout << rx <<" cel mai mic nr intreg "<<endl;//ex10.1
    cout << ry <<" cel mai mare nr real " << endl;//ex10.2
         if ((d * 72) > 1500.3)
             cout << d * 72 << endl;
         else cout << 1500.3 << endl;//ex12
    return 0;
}