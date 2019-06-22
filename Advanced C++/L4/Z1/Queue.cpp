#include "header.hpp"

void Queue::put(string s){
    if(amount >= length){
        throw invalid_argument("Nieprawidlowe dane.");
    }
    else{
        que[(start+amount)%length]=s;
        amount++;
    }
}

string Queue::take(){
    if(amount <= 0){
        throw invalid_argument("Nieprawidlowe dane.");
    }
    else{
        start=(start+1)%length;
        amount--;
        return que[(start-1+length)%length];
    }
}

string Queue::check(){
    if(amount <= 0){
        throw invalid_argument("Nieprawidlowe dane.");
    }
    else
        return que[start];
}

int Queue::size(){
    return amount;
}
