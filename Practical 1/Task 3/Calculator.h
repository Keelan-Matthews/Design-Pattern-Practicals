#ifndef CALCULATOR_H
#define CALCULATOR_H

template <typename T>
class Calculator {
    private:
        T num1;
        T num2;
    public:
        Calculator(T n1, T n2);
        T add();
        T subtract();
        T multiply();
        T divide();
};

#endif