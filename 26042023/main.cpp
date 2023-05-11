#include <iostream>

using namespace std;

struct B {
    static int n;
    virtual ~B() {cout << "~B" << endl;};
};
struct D : B {
    D() { n++; cout << "D() " << endl;}
    D(const D & d) { n = n + 4 ; cout << "D&" << endl;}
    ~D() { --n; cout << "~D" << endl;}
};
void f (B & b) {
    cout << "F" << endl;
    D d1 =dynamic_cast <D&> (b);
    cout << "dc" << endl;
    throw d1;

}

int B::n = 1;
int main() {
    try {
        cout << 1 << endl;
        D d;
        f(d);
    }
    catch(B &) { cout << B::n; }
    return 0;
}
