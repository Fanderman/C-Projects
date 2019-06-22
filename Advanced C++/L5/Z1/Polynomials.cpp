#include "header.hpp"

polynomial::polynomial(int st, const double wsp[]) : n(st){
    a = new double[st+1];
    for(int i = 0; i <= st; i++)
        a[i] = wsp[i];
}

polynomial::polynomial(int st, double wsp) : n(st){
    a = new double[st+1];
    a[0] = wsp;
}

polynomial::polynomial(initializer_list<double> wsp){
    n = wsp.size()-1;
    a = new double[n+1];
    for(int i = 0; i <= n; i++)
        a[i] = *(wsp.begin()+i);

}

polynomial::polynomial(const polynomial &w) : n(w.n){
    if(a != nullptr)
        delete [] a;
    a = new double[n+1];
    for(int i = 0; i <= n; i++)
        a[i] = w.a[i];
}

polynomial::polynomial(polynomial &&w) : n(w.n), a(w.a){
    w.a = nullptr;
}

polynomial&polynomial::operator= (const polynomial &w){
    n = w.n;
    if(a != nullptr)
        delete [] a;
    a = new double[n+1];
    for(int i = 0; i <= n; i++)
        a[i] = w.a[i];
    return *this;
}

polynomial&polynomial::operator= (polynomial &&w){
    n = w.n;
    a = w.a;
    w.a = nullptr;
    return *this;
}

polynomial::~polynomial(){
    delete [] a;
}


int polynomial::size() const{
    return n;
}

double polynomial::get(int i) const{
    if(i > n)
        throw invalid_argument("Out of bounds.");
    return a[i];
}

void polynomial::set(int i, double l){
    if(i > n)
        throw invalid_argument("Out of bounds.");
    if(i == n && l == 0)
        throw invalid_argument("Can not make the polynomial redundant.");
    a[i] = l;
}


istream &operator>>(istream &we, polynomial &w) {
    we >> w.n;
    if(w.a != nullptr)
        delete [] w.a;
    w.a = new double[w.n+1];
    for(int i = 0; i <= w.n; i++)
        we >> w.a[i];
    return we;
}

ostream &operator<<(ostream &wy, const polynomial &w) {
    wy << w.n << " ";
    for(int i = 0; i <= w.n; i++)
        wy << w.a[i] << " ";
    return wy;
}


polynomial operator+(const polynomial &u, const polynomial &v) {
    polynomial x;
    if(u.n >= v.n)
        x = u;
    else
        x = v;
    for(int i = 0; i <= x.n; i++){
        double a1 = 0;
        double a2 = 0;
        if(i <= u.n)
            a1 = u.a[i];
        if(i <= v.n)
            a2 = v.a[i];
        x.a[i] = a1 + a2;
    }
    return x;
}

polynomial operator-(const polynomial &u, const polynomial &v) {
    polynomial x;
    if(u.n >= v.n)
        x = u;
    else
        x = v;
    for(int i = 0; i <= x.n; i++){
        double a1 = 0;
        double a2 = 0;
        if(i <= u.n)
            a1 = u.a[i];
        if(i <= v.n)
            a2 = v.a[i];
        x.a[i] = a1 - a2;
    }
    return x;
}

polynomial operator*(const polynomial &u, const polynomial &v) {
    polynomial x;
    if(u.n >= v.n)
        x = u;
    else
        x = v;
    for(int i = 0; i <= x.n; i++){
        double a1 = 1;
        double a2 = 1;
        if(i <= u.n)
            a1 = u.a[i];
        if(i <= v.n)
            a2 = v.a[i];
        x.a[i] = a1 * a2;
    }
    return x;
}

polynomial operator*(const polynomial &u, double c) {
    polynomial x(u);
    for(int i = 0; i <= x.n; i++)
        x.a[i] *= c;
    return x;
}

polynomial operator*(double c, const polynomial &u) {
    polynomial x(u);
    for(int i = 0; i <= x.n; i++)
        x.a[i] *= c;
    return x;
}

polynomial&polynomial::operator+=(const polynomial &v) {
    for(int i = 0; i <= n; i++){
        double a1 = 0;
        if(i <= v.n)
            a1 = v.a[i];
        a[i] = a[i] + a1;
    }
    return *this;
}

polynomial&polynomial::operator-=(const polynomial &v) {
    for(int i = 0; i <= n; i++){
        double a1 = 0;
        if(i <= v.n)
            a1 = v.a[i];
        a[i] = a[i] - a1;
    }
    return *this;
}

polynomial&polynomial::operator*=(const polynomial &v) {
    for(int i = 0; i <= n; i++){
        double a1 = 1;
        if(i <= v.n)
            a1 = v.a[i];
        a[i] = a[i] * a1;
    }
    return *this;
}

polynomial&polynomial::operator*=(double c) {
    for(int i = 0; i <= n; i++)
        a[i] *= c;
    return *this;
}

double polynomial::operator()(double x) const {
    double result = 0;
    for(int i = 0; i <= n; i++)
        result += pow(x,i)*a[i];
    return result;
}

double polynomial::operator[](int i) const {
    return get(i);
}
