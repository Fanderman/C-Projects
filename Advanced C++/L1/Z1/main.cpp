#include <iostream>
#include <string>
#include <vector>

using namespace std;

const vector<pair<int, string>> rzym = {
    {1000, "M"},
    {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
    {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"},
    {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};

string bin2rzym (int x){
    int i = 0;
    string s = "";
    while(x > 0)
    {
        if( (x - rzym[i].first) >= 0){
            x -= rzym[i].first;
            s += rzym[i].second;
        }
        else i++;
    }
    return s;
}

int main(int argc, char *argv[])
{
    int x;
    for(int i=1; i < argc; i++){
        try{
            x = stoi(argv[i]);
            if(x <= 0 || x >= 4000)
                throw out_of_range("wartosc poza zasiegiem");
            cout << bin2rzym(x) << endl;
        }
        catch( invalid_argument e1){
            //throw(logic_error("nie podano liczby"));
        }
        catch( out_of_range e2){
            //throw(logic_error("wartosc poza zasiegiem"));
        }
    }
    return 0;
}
