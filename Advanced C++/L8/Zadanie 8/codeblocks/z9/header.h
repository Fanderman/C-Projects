#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <tuple>
#include <map>
#include <cmath>
using namespace std;

tuple<int, double> parse(string x);

class parsable{
public:
    virtual void calculate(stack<double>* numbers) = 0;
};


class numbers : public parsable{
private:
    double number;
public:
    numbers(double number);
    void calculate(stack<double>* numbers);
};

class stale : public parsable{
private:
    double number;
public:
    static map <string, double> value;
    stale(string name);
    void calculate(stack<double>* numbers);
};

class variable : public parsable{
private:
    double number;
public:
    static map <string, double> value;
    variable(string name);
    void calculate(stack<double>* numbers);
};

class unary : public parsable{
public:
    static double load(stack<double>* numbers);
};

class binary : public parsable{
public:
    static tuple <double, double> load(stack<double>* numbers);
};

class add : public binary{
public:
    void calculate(stack<double>* numbers);
};

class sub : public binary{
    void calculate(stack<double>* numbers);
};

class mul : public binary{
    void calculate(stack<double>* numbers);
};

class divi : public binary{
    void calculate(stack<double>* numbers);
};

class modulo : public binary{
    void calculate(stack<double>* numbers);
};

class min1 : public binary{
    void calculate(stack<double>* numbers);
};

class max1 : public binary{
    void calculate(stack<double>* numbers);
};

class log1 : public binary{
    void calculate(stack<double>* numbers);
};

class pow1 : public binary{
    void calculate(stack<double>* numbers);
};


class abs1 : public unary{
    void calculate(stack<double>* numbers);
};

class sgn1 : public unary{
    void calculate(stack<double>* numbers);
};

class floor1 : public unary{
    void calculate(stack<double>* numbers);
};

class ceil1 : public unary{
    void calculate(stack<double>* numbers);
};

class frac1 : public unary{
    void calculate(stack<double>* numbers);
};

class sin1 : public unary{
    void calculate(stack<double>* numbers);
};

class cos1 : public unary{
    void calculate(stack<double>* numbers);
};

class atan1 : public unary{
    void calculate(stack<double>* numbers);
};

class acot1 : public unary{
    void calculate(stack<double>* numbers);
};

class ln1 : public unary{
    void calculate(stack<double>* numbers);
};

class exp1 : public unary{
    void calculate(stack<double>* numbers);
};

