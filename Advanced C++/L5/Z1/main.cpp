#include "header.hpp"
using namespace std;
int main() {

    polynomial x;
    double a[5]={10,9,8,7,6};
    polynomial z(4,a);
    polynomial c = {1, 2, 3, 4, 5};
    cout <<"Konstruktor podstawowy " << x << endl << "Konstruktor z tablicy " << z << endl << "Konstruktor z lista inicjalizacyjna " << c << endl;
    x=z;
    cout<< x << " i "<< z<<endl;
    polynomial k;
    std::swap(z,k);
    cout<<z<<endl;
    cout<<k<<endl;
    polynomial n = x+c;
    cout <<"Dodawanie "<< n << endl;
    cout <<"Odejmowanie "<< n - c << endl;
    cout <<"Mnozenie przez wielomian " << n * z << endl;
    cout <<"Mnozenie przez skalar "<< 5 * c << endl;
    polynomial q = {1 , 2 , 3};
    cout<<"polynomial q: "<< q <<endl;
    q+=q;
    cout <<"q+=q "<< q << endl;
    q*=q;
    cout <<"q*=q "<< q << endl;
    q*=2;
    cout <<"q*=2 "<< q << endl;
    q-=q;
    cout <<"q-=q "<< q << endl;
    cout<<"polynomial "<< c << endl;
    cout << "rozmiar " <<c.size() <<endl;
    c.set(0,5);
    cout << "c.set(0,5) " << c <<endl;
    cout <<"Obliczenie wyrazen " << c(1) << endl;
    cout << "Obliczenie i-tego wspolczynnika " << c[1] << endl;
    return 0;
}
