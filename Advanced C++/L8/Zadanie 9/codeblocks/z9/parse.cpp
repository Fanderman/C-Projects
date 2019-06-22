#include "header.h"

tuple <int, double> parse(string x){
    queue <parsable*> calls;
    string word = "";
    string var = "";
    bool used_to = false;

    int command = 0;

    for(int i = 0; i != x.length()+1; i++){
        if(i == x.length() || x[i] == ' '){
            if (word != " "){
                if(command == 0){
                    if(word == "print")
                        command = 1;
                    else if(word == "assign")
                        command = 2;
                    else if(word == "clear")
                        command = 3;
                    else if(word == "exit")
                        command = 4;
                    else
                        throw invalid_argument("The command was not recognised.");
                }
                else{
                    if(word == "to") {
                        if (command == 2) {
                            used_to = true;
                        }
                        else
                            throw invalid_argument("Used key word 'to' without assign.");
                    }
                    else if(word == "+")
                        calls.push(new add());
                    else if(word == "-")
                        calls.push(new sub());
                    else if(word == "*")
                        calls.push(new mul());
                    else if(word == "/")
                        calls.push(new divi());
                    else if(word == "e" || word == "pi" || word == "fi")
                        calls.push(new stale(word));
                    else if(word == "modulo"){
                        calls.push(new modulo());
                    }
                    else if(word == "min"){
                        calls.push(new min1());
                    }
                    else if(word == "max"){
                        calls.push(new max1());
                    }
                    else if(word == "log"){
                        calls.push(new log1());
                    }
                    else if(word == "pow"){
                        calls.push(new pow1());
                    }
                    else if(word == "abs"){
                        calls.push(new abs1());
                    }
                    else if(word == "sgn"){
                        calls.push(new sgn1());
                    }
                    else if(word == "floor"){
                        calls.push(new floor1());
                    }
                    else if(word == "ceil"){
                        calls.push(new ceil1());
                    }
                    else if(word == "frac"){
                        calls.push(new frac1());
                    }
                    else if(word == "sin"){
                        calls.push(new sin1());
                    }
                    else if(word == "cos"){
                        calls.push(new cos1());
                    }
                    else if(word == "atan"){
                        calls.push(new atan1());
                    }
                    else if(word == "acot"){
                        calls.push(new acot1());
                    }
                    else if(word == "ln"){
                        calls.push(new ln1());
                    }
                    else if(word == "exp"){
                        calls.push(new exp1());
                    }
                    else{
                        string::size_type end;
                        double number;
                        if(((int)(word[0]) >= 48 && (int)(word[0]) <= 57) || (int)(word[0]) == '-'){
                            number = stod(word, &end);
                            if(word.substr(end) == ""){
                                calls.push(new numbers(number));
                            }
                            else{
                                if(used_to){
                                    var = word;
                                    break;
                                }
                                else{
                                    calls.push(new variable(word));
                                }
                            }
                        }
                        else{
                            if(used_to){
                                var = word;
                                break;
                            }
                            else{
                                calls.push(new variable(word));
                            }
                        }
                    }
                }
            }
            word = "";
        }
        else
            word += x[i];
    }

    if(command == 4)
        return make_tuple(-1,0);

    if(command == 3)
        return make_tuple(2,0);

    stack <double> numbers;
    while(!calls.empty()){
        parsable* call = calls.front();
        calls.pop();
        call->calculate(&numbers);
    }
    if(numbers.empty())
        throw invalid_argument("Not enough arguments.");
    if(command == 1)
        return make_tuple(0, numbers.top());


    if(var == "")
        throw invalid_argument("No variable set.");

    variable::value[var] = numbers.top();
    return make_tuple(1, numbers.top());
}

