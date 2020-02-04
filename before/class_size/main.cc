#include <cstdio>

class A {
    ~A(){};

    int a;
    virtual int func(){}
    virtual int func1(){}
    virtual int func2(){}

    static int b;

    static int func3() {
        return b;
    }

    int d;

    char c;

};

int main() {

    printf("%d\n", sizeof(A));

    return 0;
}
