// Ana Videira | 2015012218 | 2020/2021

#include "Triangulo.h"

using namespace std;

int main(int argc, char** argv) {

    Triangulo t;
    ostringstream os;

    t.getInfo(os);
    cout << os.str() << endl;

    return 0;
}

