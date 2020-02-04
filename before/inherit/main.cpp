#include <cstdio>

class A {
public:
    void test() {
        printf("test in A\n");
    }
};

class B : public A {
public:
    void test() {
        printf("test in B\n");
    }

};

int main() {
    A a;
    B b;
    B b1;
    a.test();
    b.test();
    b1.test();
    printf("%x\n", &(B::test));
    return 0;
}
