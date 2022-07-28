#include "Calculator.cpp"
#include <iostream>
#include <string>
using namespace std;

int main(){
    Calculator<int>* c = new Calculator(741,13);
    cout << c->divide() << endl;
    delete c;

    Calculator<char>* c2 = new Calculator('o','o');
    cout << c2->add() << endl;
    delete c2;
    return 0;
}