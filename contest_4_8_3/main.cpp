#include <iostream>


using std::cin;

class S {
    int val = 0;
    bool fl, fl0 = true;
public :
    S() {
        if (cin >> val)
            fl = true;
        else {
            fl = false;
            fl0 = false;
        }

    }
    S( S && cp) {
        if(cin >> val) {
            fl = true;
        } else {
            fl = false;
        }
        val += cp.val;
    }

    operator bool () {
        return fl;
    }

    ~S() {
        if (!fl && fl0)
            std::cout << val <<  std::endl;
    }
};
/*
using namespace std;
void func(S v)
{
    if (v) {
        func(move(v));
    }
}

int main()
{
    func(S());
}*/
