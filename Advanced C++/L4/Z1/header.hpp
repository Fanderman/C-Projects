#include <iostream>
#include <vector>
#include <initializer_list>
#include <cmath>
using namespace std;

class polynomial{

private:
    int n;
    double *a = nullptr;

public:
    polynomial (int st=0, double wsp=1.0); // konstruktor tworzący jednomian
    polynomial (int st, const double wsp[]); // konstruktor tworzący wielomian
    polynomial (std::initializer_list<double> wsp); // lista współczynników
    polynomial (const polynomial &w); // konstruktor kopiujący
    polynomial (polynomial &&w); // konstruktor przenoszący
    polynomial& operator = (const polynomial &w); // przypisanie kopiujące
    polynomial& operator = (polynomial &&w); // przypisanie przenoszące
    ~polynomial (); // destruktor

    int size() const;
    double get (int i) const;
    void set (int i, double l);

    friend istream& operator >> (istream &we, polynomial &w);
    friend ostream& operator << (ostream &wy, const polynomial &w);

    friend polynomial operator + (const polynomial &u, const polynomial &v);
    friend polynomial operator - (const polynomial &u, const polynomial &v);
    friend polynomial operator * (const polynomial &u, const polynomial &v);
    friend polynomial operator * (const polynomial &u, double c);
    friend polynomial operator * (double c,const polynomial &u);
    polynomial& operator += (const polynomial &v);
    polynomial& operator -= (const polynomial &v);
    polynomial& operator *= (const polynomial &v);
    polynomial& operator *= (double c);
    double operator () (double x) const; // obliczenie wartości wielomianu dla x
    double operator [] (int i) const; // odczytanie i-tego współczynnika

};
