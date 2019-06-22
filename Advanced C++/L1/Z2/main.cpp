#include <iostream>
#include <cmath>
#include <string>
using namespace std;

const double Pi = 3.14159265359;
int main()
{
    string S;
    double P;
    clog << "Podaj pole: " << endl;
    cin >> S;
    try{
        P = stod(S);
    }
    catch( invalid_argument e1){
        throw(logic_error("nie podano liczby"));
    }
    catch( out_of_range e2){
        throw(logic_error("wartosci poza zasiegiem"));
    }
    bool cont = 1;
    if(P < 0){
        cont = 0;
        cerr << "Pole nie moze byc ujemne." << endl;
    }
    if(cont){
        clog << "Promien wynosi: ";
        cout << sqrt(P/Pi);
    }
    return 0;
}
