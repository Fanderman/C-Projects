#include "header.h"

tuple <double, double> binary::load(stack<double>* numbers){
    if(numbers->empty())
        throw invalid_argument("Not enough arguments for operands.");

    double a = numbers->top();
    numbers->pop();

    if(numbers->empty())
        throw invalid_argument("Not enough arguments for operands.");

    double b = numbers->top();
    numbers->pop();

    return make_tuple(b,a);
}

void add::calculate(stack<double>* numbers){
    double a,b;
    tie(a,b) = load(numbers);
    numbers->push(a + b);
}

void sub::calculate(stack<double>* numbers) {
    double a,b;
    tie(a,b) = load(numbers);
    numbers->push(a - b);
}

void mul::calculate(stack<double>* numbers) {
    double a,b;
    tie(a,b) = load(numbers);
    numbers->push(a * b);
}

void divi::calculate(stack<double>* numbers) {
    double a,b;
    tie(a,b) = load(numbers);
    if(b == 0)
        throw invalid_argument("Division by zero.");
    numbers->push(a / b);
}

void modulo::calculate(stack<double> *numbers) {
    double a,b;
    tie(a,b) = load(numbers);
    if(b == 0)
        throw invalid_argument("Division by zero.");
    numbers->push((int)(a) % (int)(b));
}

void max1::calculate(stack<double> *numbers) {
    double a,b;
    tie(a,b) = load(numbers);
    if(a >= b)
        numbers->push(a);
    else
        numbers->push(b);
}

void min1::calculate(stack<double> *numbers) {
    double a,b;
    tie(a,b) = load(numbers);
    if(a <= b)
        numbers->push(a);
    else
        numbers->push(b);
}

void log1::calculate(stack<double> *numbers) {
    double a,b;
    tie(a,b) = load(numbers);
    if(a == 0)
        throw invalid_argument("Division by zero.");
    numbers->push(log(b)/log(a));
}

void pow1::calculate(stack<double> *numbers) {
    double a,b;
    tie(a,b) = load(numbers);
    numbers->push(pow(a,b));
}