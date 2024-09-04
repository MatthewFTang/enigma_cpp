
void doSomething() {}
void doSomethingElse() {}
void foo() {}
#include <iostream>
void main2() {
    std::cout << "hello" << std::endl;
    int myVariable = 2;

    switch (myVariable) {
        case 1:
            foo();
            break;
        case 2:  // Both 'doSomething()' and 'doSomethingElse()' will be
            doSomething();
    }
}
