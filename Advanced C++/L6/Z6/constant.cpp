#include "header.h"

constant::constant(string name){
    if(name.equals("pi"))
        val = 3.14159;
    if(name.equals("e"))
        val = 2.71828;
    if(name.equals("phi"))
        val = 1.61803;
}

double constant::Compute(){
    return this->value;
}

string constant::toString () {
    return "(" + this->key + ") = (" + String.valueOf(this->value) + ")";
}
