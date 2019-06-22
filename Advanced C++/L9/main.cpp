#include "header.h"

int main() {
    stale::value["e"] = 2.718281828459;
    stale::value["pi"] = 3.141592653589;
    stale::value["fi"] = 1.618033988750;

    int result = 0;
    double answer = 0;
    while(result != -1)
    {
        cout << "State your quarry:" << endl;
        string quarry;
        getline(cin, quarry);

        tie(result, answer) = parse(quarry);
        if(result == 0)
            cout << answer << endl;
        if(result == 1)
            cout << answer << " is now assigned." << endl;
        if(result == 2) {
            variable::value.clear();
            cout << "Cleared." << endl;
        }
    }
    return 0;
}