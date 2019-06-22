#include "header.h"
//#include "objects.cpp"


int main(){
    Punkt p1(2,5);
    cout << p1.Y() << endl;
    Punkt p2(p1);
    cout << p2.X() << endl;
    Punkt p3(5,6);
    cout << dystans(p2,p3) << endl;
    try{
        Trojkat(p1,p1,p3);
    }
    catch(invalid_argument e){
        cout << "cought" << endl;
    }
    p2.przesun(Wektor(1,1));
    Trojkat tr(p1,p2,p3);
    cout << tr.X1() << " " << tr.Y1() << endl;
    cout << tr.X2() << " " << tr.Y2() << endl;
    cout << tr.X3() << " " << tr.Y3() << endl;
    tr.obroc(p1,90);
    cout << endl;
    cout << tr.X1() << " " << tr.Y1() << endl;
    cout << tr.X2() << " " << tr.Y2() << endl;
    cout << tr.X3() << " " << tr.Y3() << endl;
    tr.odbij(Prosta(1,1,1));
    cout << endl;
    cout << tr.X1() << " " << tr.Y1() << endl;
    cout << tr.X2() << " " << tr.Y2() << endl;
    cout << tr.X3() << " " << tr.Y3() << endl;
    return 0;
}
