#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

class Queue{
    private:
    string *que = nullptr;
    int length;
    int start;
    int amount;
    //bool exists = false;

    public:

    Queue(int length){
        this -> length = length;
        this -> start = 0;
        this -> amount = 0;
        //this -> exists = true;
        que = new string[length];
    }

    Queue() : Queue(1){}

    Queue(Queue &k){
        this -> length = k.length;
        this -> start = k.start;
        this -> amount = k.amount;
        if(this -> que != nullptr)
            delete [] que;
        //this -> exists = true;
        que = new string[length];
        for(int i=0; i<length; i++){
            que[i]=k.que[i];
        }
    }

    Queue &operator=(Queue &k){
        this -> length = k.length;
        this -> start = k.start;
        this -> amount = k.amount;
        if(this -> que != nullptr)
            delete [] que;
        //this -> exists = true;
        que = new string[k.length];
        for(int i=0; i<length; i++){
            que[i]=k.que[i];
        }
    }

    Queue (Queue &&k) : length(k.length),start(k.start), amount(k.amount), que(k.que){
        k.que = nullptr;
    }

    ~Queue(){
        delete [] que;
    }

    void put(string s);

    string take();

    string check();

    int size();
};
