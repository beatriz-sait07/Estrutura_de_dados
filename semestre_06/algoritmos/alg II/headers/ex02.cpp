#include "vet.h"
#include <iostream>

using namespace std;

int main(){
    float w = 3, x = 2, y = 6, z = 19;

    cout << w << " + " << x << " = " << func(w, x) << endl;
    cout << "ANS " << " + " << y << " = " << func(w, x, y) << endl;
    cout << "ANS " << y << " + " << z << " = " << func(w, x, y, z) << endl;

    return 0;
}
