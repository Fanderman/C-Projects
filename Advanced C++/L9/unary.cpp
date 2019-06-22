#include "header.h"

double unary::load(stack<double>* numbers){
    if(numbers->empty())
        throw invalid_argument("Not enough arguments for operands.");

    double a = numbers->top();
    numbers->pop();

    return a;
}

void abs1::calculate(stack<double> *numbers) {
    double a;
    a = load(numbers);
    if(a < 0)
        numbers->push(-a);
    else
        numbers->push(a);
}

void sgn1::calculate(stack<double> *numbers) {
    double a;
    a = load(numbers);
    if(a < 0)
        numbers->push(-1);
    else
        numbers->push(1);
}

void floor1::calculate(stack<double> *numbers) {
    double a;
    a = load(numbers);
    numbers->push(floor(a));
}

void ceil1::calculate(stack<double> *numbers) {
    double a;
    a = load(numbers);
    numbers->push(ceil(a));
}

void frac1::calculate(stack<double> *numbers) {
    double a;
    a = load(numbers);
    numbers->push(a-floor(a));
}

void sin1::calculate(stack<double> *numbers) {
    double a;
    a = load(numbers);
    numbers->push(sin(a));
}

void cos1::calculate(stack<double> *numbers) {
    double a;
    a = load(numbers);
    numbers->push(cos(a));
}

void atan1::calculate(stack<double> *numbers) {
    double a;
    a = load(numbers);
    numbers->push(atan(a));
}

void acot1::calculate(stack<double> *numbers) {
    double a;
    a = load(numbers);
    numbers->push(pow(1/tan(a),-1));
}

void ln1::calculate(stack<double> *numbers) {
    double a;
    a = load(numbers);
    numbers->push(log(a));
}

void exp1::calculate(stack<double> *numbers) {
    double a;
    a = load(numbers);
    numbers->push(exp(a));
}