#include <iostream>
using namespace std;
//clas 3 atribute int min max middle ,3 constructori
// 1 pasam parametru mymax
// primul un parma al 2-lea 2 si al 3 lea 3
//primul constructor primeste param min

//max = parametrulpasat > 0 ? parametrulpasat : 10;
//min = my_nim > 0 && my min < max ? my_min : 1;
//middle= my_middle< max&& my_middle >min ? my_middle:5;
class deleg {
public:
    int max;
    int min;
    int middle;

    int get_max() { return max; }
    int get_min() { return min; }
    int get_mid() { return middle; }

    deleg(int my_max) {
        max = my_max > 0 ? my_max : 10;
    }
    deleg(int my_max, int my_min) :deleg(my_max){
        min = my_min > 0 && my_min < max ? my_min : 1;
    }
    deleg(int my_max, int my_min, int my_middle):deleg(my_max, my_min) {
        middle = my_middle < max && my_middle > min ? my_middle : 5;
    }
};
void display_deleg(deleg p) {
    cout << "max:" << p.get_min() << endl;
    cout << "min:" << p.get_max() << endl;
    cout << "middle:" << p.get_min() << endl;
}

int main()
{

    deleg obj(5);
    display_deleg(obj);

    deleg obj1(7, 2);
    display_deleg(obj1);

    deleg obj2(7, 2, 6);
    display_deleg(obj2);


    return 0;
}
/*class delegating {
public:
    int max;
    int min;
    int middle;

    int get_name() { return max; }
    int get_health() { return min; }
    int get_xp() { return middle; }

    delegating(int my_max) {
        max = my_max > 0 ? my_max : 10;
    }
    delegating(int my_max, int my_min) : delegating(my_max) {
        min = my_max > 0 ? my_max : 10;
    }
    delegating(int my_max, int my_min, int my_middle) : delegating(my_max, my_min) {
        middle = my_middle < max && my_middle > min ? my_middle : 5;
    }
};


void display_player(delegating p) {
    cout << "max:" << p.get_name() << endl;
    cout << "min:" << p.get_health() << endl;
    cout << "middle:" << p.get_xp() << endl;
}

int main()
{
    /*
    delegating obj(5);
    display_player(obj);

    delegating obj1(7,2);
    display_player(obj1);
    
    delegating obj2(7, 2, 6);
    display_player(obj2);


    return 0;
}*/
