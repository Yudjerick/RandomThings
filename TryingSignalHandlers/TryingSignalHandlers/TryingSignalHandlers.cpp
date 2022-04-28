#include <iostream>
#define TYPE_HANDLER(a) void (Transceiver::*a) (string s)
#define TYPE_SIGNAL(a) void (Transceiver::*a) (TYPE_HANDLER(h),string s)
using namespace std;

/*struct Connection
{
    Transceiver* connected;
    TYPE_SIGNAL(signal);
    TYPE_HANDLER(handler);
};*/

class Transceiver
{
public:
    string name;
    Transceiver* connected;
    Transceiver(string s) 
    {
        name = s;
    }

    void signal1(TYPE_HANDLER(a), string msg) 
    {
        cout << "signal 1 called on " << name << endl;
        (connected->*a)(msg);
    }
    void signal2(TYPE_HANDLER(a), string msg) 
    {
        cout << "signal 2 called on " << name << endl;
        (connected->*a)(msg);
    }

    void handler1(string s) {
        cout << "handler 1 called on "<< name << " message: " << s << endl;
    }
    void handler2(string s) {
        cout << "handler 2 called on " << name << " message: " << s << endl;
    }
};

int main()
{
    Transceiver A("A");
    Transceiver B("B");
    A.connected = &B;
    B.connected = &B;
    A.signal1(&Transceiver::handler2, "HELLO");
    B.signal2(&Transceiver::handler1, "HI");
}