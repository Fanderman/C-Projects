#include <iostream>
#include "header.hpp"
using namespace std;

int main()
{
    Queue q(2);
    q.put("asd");
    q.put("qwe");
    cout << q.size() << endl;
    cout << q.check() << endl;
    cout << q.take() << endl;
    cout << q.size() << endl;
    q.put("fds");
    cout << q.take() << endl;

    Queue w;
    w = q;
    cout << w.size() << endl;
    cout << w.take() << endl;

    Queue e(q);
    cout << e.take() << endl;
    cout << e.check() << endl;
}
