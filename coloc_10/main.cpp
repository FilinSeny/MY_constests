#include <iostream>
#include <list>
using std::cout, std::cin, std::endl;
/*
template <class X>
typename X::reverse_iterator f(const X & x, typename X::value_type) {
    typename X::const_reverse_iterator p = x.rbegin();
    while (p != x.rend())
        if (*--p == x.front()) return p;
    return x.end();
}


int main() {
    std::list <int> g;
    g.push_back(1);
    f(g, 7);
    return 0;
}
*/


#include <vector>
#include <iterator>
/*
template < class X >
typename X :: iterator f ( X & x, X * v )
{ typename X::iterator  p = x.end();
    while (p != x.begin ( ) )
        if ( * -- p == * v ) return p;
    return x.end ( );
}
int main(){
    std::vector<int> g;
    g.push_back(1) ;
    f(g,&g);
    return 0;
}
*/
/*
template < class X >
typename X :: const_iterator f ( const X & x, typename X :: value_type v )
{
    typename X :: const_iterator p = x.end ( );
    while (p != x.begin ( ) )
    { std::cout<<"q";
        if ( * (p-=1) == v ) return p;
    }
    return x.end ( );
}
int main(){
    std::vector <int> g;
    g.push_back(1) ;
    f(g,7);
    return 0;
}
 */
/*
class A {
public: static int k;
    A() { k += 2; }
    A(const A&) { k += 2; }
    ~A() { k -= 1; }
};
void f(A & a, int n) {
    try { if (n == 0) throw A(); else throw 1; }
    catch (int x) { f(a, x - 1); }
    catch (A & a) { throw; }
}
int A::k = -1;
int main () {
    try { A a; f (a, 10); }
    catch (A a) { cout << A::k *10 + a.k; }
    return 0;
}*//*struct B {
    static int n;
    B() {
        cout << "B()" << endl;
    }
    virtual ~B(){
        cout << "~B" << endl;
    }
};
struct D : B {
    D() { n++;
    cout << "D()" << endl;}
    D(const D & d){ n = n + 5 ;
    cout << "D &" << endl;}
    ~D(){ --n;
    cout << "~D" << endl;}
};
void f (D d) {
    cout << "f" << endl;
    D* pd = &d;
    throw pd;
}
int B::n = 1;
int main() {
    try {
        D d;
        cout << 1 << endl;
        f(d);
    }
    catch(B *) { cout << B::n << '\n';}
    return 0;
}*//*
#include <iostream>
using namespace std;
#include <iostream>
#include <iostream>
using namespace std;

class A {
public:
    A(int x=0) {cout<<1;}
    A(A&) {cout<<2;}
    A(const A&) {cout<<3;}
    ~A() {cout<<4;}
};

class B: public A{
public:
    B(int x=0) {cout<<5;}
    B(const B& rb):A(rb) {cout<<6;}

};
int main() {
    B b1, b2=1;
    cout<<7;
    return 0;
}*//*
#include <iostream>
using namespace std;

class A {
    int i;
    int & ri;
public:

    A(): ri(i) {};
    A& operator=(const A& ra)  { i=ra.i; return *this;}

};
int main() {
    A a; A b=a; a=b;
    return 0;
}*/


#include<iostream>

#include <iostream>
#include<iostream>
using namespace std;
class Base{
public:
    Base() {cout << 1;}
    virtual ~Base() {cout << 2;}
    void  s() {cout << 3;}
    virtual void q() {cout << 4;}
    virtual void v() {cout << 5;}

};

class Derived: public Base {
public:
    Derived() {cout << 6;}
    ~Derived() {cout << 7;}
    void s() {cout << 8;}
    virtual void q() {cout << 9;}
    virtual void v() {cout << 10;}
};


void f() {
    Derived b;///16
    Base *pa = &b;
    pa->s();///3 or 8
    b.s();///8
    pa->v();///10
    ///72
}


int main()
{
    f();
    return  0;
}