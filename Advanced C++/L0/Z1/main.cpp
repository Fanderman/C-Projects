#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main()
{
    double bok[3];
    string S;
    clog << "wpisz boki: " << endl;
    for(int i = 0; i != 3; i++){
        cin >> S;
        try{
            bok[i] = stod(S);
        }
        catch( invalid_argument e1){
            throw(logic_error("nie podano liczby"));
        }
        catch( out_of_range e2){
            throw(logic_error("wartosci poza zasiegiem"));
        }
    }
    bool cont = 1;
    for(int i = 0; i != 3; i++){
        if(cont && bok[i] < 0){
            cont = 0;
            cerr << "Boki nie moga byc ujemne";
        }
        if(cont && bok[i] >= bok[(i+1)%3] + bok[(i+2)%3]){
            cont = 0;
            cerr << "Trojkat musi miec poprawne dlugosci";
        }
    }
    if(cont){
        double s = (bok[0] + bok[1] + bok[2])/2;
        double P = sqrt(s*(s-bok[0])*(s-bok[1])*(s-bok[2]));
        long PP = P*1000;
        clog << "Pole wynosi: ";
        cout << (double)(PP)/1000 << endl;
    }
    return 0;
}
