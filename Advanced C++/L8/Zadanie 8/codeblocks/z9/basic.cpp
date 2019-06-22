#include "header.h"

numbers::numbers(double number) {
    this->number = number;
}

void numbers::calculate(stack<double>* numbers) {
    numbers->push(number);
}


map <string, double> stale::value;

stale::stale(string name) {
    this->number = value[name];
}

void stale::calculate(stack<double>* numbers) {
    numbers->push(number);
}


map <string, double> variable::value;

variable::variable(string name) {
    if(value.find(name) == value.end())
        throw invalid_argument("Variable " + name + " could not be found");
    this->number = value[name];
}

void variable::calculate(stack<double>* numbers) {
    numbers->push(number);
}
