#include "header.h"

number::number(double value){
    this->value = value;
}

double number::Compute(){
    return this->value;
}

string number::toString () {
    return "Number(" + to_string(this->value) + ")";
}

    /*boolean equals (Object o) {
        if (o instanceof Constant) {
            return ((Constant) o).value == this.value;
        }
        if (o instanceof Number) {
            return((Number) o).value == this.value;
        }
        if (o instanceof Variable){
            return((Variable) o).value == this.value;
        }
        return false;
    }*/
