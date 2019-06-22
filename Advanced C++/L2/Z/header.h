#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const double Pi = 3.14159265359;

class Wektor{
    public:
    double x,y;
    Wektor(double x, double y){
        this->x = x;
        this->y = y;
    }
};

class Prosta{
    public:
    double a,b,c;
    Prosta(double a, double b, double c) {
        if(a == 0 && b == 0){
            throw invalid_argument("Nieprawidlowe dane.");
        }
        this->a = a;
        this->b = b;
        this->c = c;
    }
    Prosta przesun(Wektor w){
        double nc = -c/b;
        nc += w.y;
        nc += (-w.x*a);
        nc = -nc*b;
        return Prosta(a,b,nc);
    }
};

class Punkt{

    private:
    double x,y;

    public:

    Punkt(){
        x = 0;
        y = 0;
    }
    Punkt(double x, double y){
        this->x = x;
        this->y = y;
    }

    Punkt(Punkt& p){
        this->x = p.X();
        this->y = p.Y();
    }

    double X(){
        return x;
    }

    double Y(){
        return y;
    }

    void przesun(Wektor w){
        x += w.x;
        y += w.y;
    }

    void obroc(Punkt p, double kat){
        double nx = x - p.x;
        double ny = y - p.y;
        double rx = nx*cos(Pi/180 * kat) - ny*sin(Pi/180 * kat);
        double ry = nx*sin(Pi/180 * kat) + ny*cos(Pi/180 * kat);
        x = rx+p.x;
        y = ry+p.y;
    }

    void odbij(Prosta p){
        if(p.a == 0){
            double nc = -p.c/p.b;
            y = 2*nc -y;
        }
        else if(p.b == 0){
            double nc = -p.c/p.a;
            x = 2*nc - x;
        }
        else{
            double na = -p.a / p.b;
            double nc = -p.c / p.b;
            double mv = -nc / na;
            x = x - mv;
            double d = 1+na*na;
            double nx = ((1-na*na)/d)* x + (2*na/d)*y;
            double ny = (2*na/d)* x + ((1-na*na)/d)*y;
            x = nx + mv;
            y = ny;
        }
    }
};

class Odcinek{
    private:
    Punkt p1,p2;
    public:
    Odcinek(Punkt& p1,Punkt& p2){
        if(p1.X() == p2.X() && p1.Y() == p2.Y())
            throw invalid_argument("Nieprawidlowe dane.");

        this->p1 = Punkt(p1);
        this->p2 = Punkt(p2);
    }
    double X1(){
        return p1.X();
    }
    double Y1(){
        return p1.Y();
    }
    double X2(){
        return p2.X();
    }
    double Y2(){
        return p2.Y();
    }
    void przesun(Wektor w){
        p1.przesun(w);
        p2.przesun(w);
    }
    void obroc(Punkt p, double kat){
        p1.obroc(p, kat);
        p2.obroc(p, kat);
    }
    void odbij(Prosta p){
        p1.odbij(p);
        p2.odbij(p);
    }
};

class Trojkat{
    private:
    Punkt p1,p2,p3;
    public:
    Trojkat(Punkt& p1, Punkt& p2, Punkt& p3){
        if((p1.X() == p2.X() && p1.Y() == p2.Y()) ||(p2.X() == p3.X() && p2.Y() == p3.Y()) || (p1.X() == p3.X() && p1.Y() == p3.Y()))
            throw invalid_argument("Nieprawidlowe dane.");
        if(p1.X() * (p2.Y() - p3.Y()) + p2.X() * (p3.Y() - p1.Y()) + p3.X() * (p1.Y() - p2.Y()) == 0)
            throw invalid_argument("Nieprawidlowe dane.");
        this->p1 = Punkt(p1);
        this->p2 = Punkt(p2);
        this->p3 = Punkt(p3);
    }
    double X1(){
        return p1.X();
    }
    double Y1(){
        return p1.Y();
    }
    double X2(){
        return p2.X();
    }
    double Y2(){
        return p2.Y();
    }
    double X3(){
        return p3.X();
    }
    double Y3(){
        return p3.Y();
    }
    void przesun(Wektor w){
        p1.przesun(w);
        p2.przesun(w);
        p3.przesun(w);
    }
    void obroc(Punkt p, double kat){
        p1.obroc(p, kat);
        p2.obroc(p, kat);
        p3.obroc(p, kat);
    }
    void odbij(Prosta p){
        p1.odbij(p);
        p2.odbij(p);
        p3.odbij(p);
    }
};

double dystans(Punkt& p1, Punkt& p2);
#endif // HEADER_H
