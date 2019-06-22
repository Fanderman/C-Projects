#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <utility>
using namespace std;

class expression {
    virtual double Compute() = 0;
    virtual string toString() = 0;

};

class number:public virtual expression {
private:
    double value;

public:
    number(double value);
    double Compute() override;
    string toString() override;
};

class constant:public virtual expression {
private:
    const static vector< pair <string, double> > consts;
    string key;
    double value;

public:
    constant(string s);
    double Compute() override;
    string toString() override;
};

class variable:public virtual expression {
private:
    const static vector< pair <string, double> > variables;
    string key;
    double value;

public:
    variable(string s);
    void put(string s, double v);
    double Compute() override;
    string toString() override;
};

class uOperator:public virtual expression {
private:
    expression* exp;

public:
    void setExp(expression* exp);
    expression* getExp();
};

class bOperator:uOperator {
private:
    expression* exp2;

public:
    void setExp2(expression* exp);
    expression* getExp2();
};


