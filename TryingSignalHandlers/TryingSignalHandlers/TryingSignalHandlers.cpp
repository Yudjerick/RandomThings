#include <iostream>
#define TYPE_SIGNAL(a) void (B::*a) ()
#define FOR(n) for(int i = 0; i < n; i++)
using namespace std;

class B
{
public:
    void handler() {
        cout << "handler called";
    }
};

class A 
{
public:
    B* b;
    void signal(TYPE_SIGNAL(a)) {
        cout << "signal called";
        (b->*a)();
    }
};

int main()
{
    A* obj1 = new A;
    B* obj2 = new B;
    obj1->b = obj2;
    obj1->signal(&B::handler);
}