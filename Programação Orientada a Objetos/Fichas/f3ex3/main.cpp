// Ana Videira | 2015012218 | 2020/2021

#include "Rectangulo.h"

using namespace std;

int main(int argc, char** argv) {
    ostringstream os;
    
    Rectangulo r(Ponto(2, 4), 2, 5);

    r.getInfo(os);

    cout << os.str();

    return 0;
}

