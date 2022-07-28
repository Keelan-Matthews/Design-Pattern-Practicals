#ifndef MAIN_H
#define MAIN_H

#include <iostream>
class ClassA {
    public:
    ClassA(){
        std::cout << "ClassA's Empty Constructor is Called" << std::endl;
    }
    virtual ~ClassA(){
        std::cout << "ClassA's Destructor is Called" << std::endl;
    }
};

class ClassB {
    public:
    ClassB(){
        std::cout << "ClassB's Empty Constructor is Called" << std::endl;
    }
    ~ClassB(){
        std::cout << "ClassB's Destructor is Called" << std::endl;
    }
};

class ClassC : public ClassA {
    public:
    ClassC(){
        std::cout << "ClassC's Empty Constructor is Called" << std::endl;
    }
    ~ClassC(){
        std::cout << "ClassC's Destructor is Called" << std::endl;
    }
};

class ClassD : public ClassA, public ClassB {
    public:
    ClassD(){
        std::cout << "ClassD's Empty Constructor is Called" << std::endl;
    }
    ~ClassD(){
        std::cout << "ClassD's Destructor is Called" << std::endl;
    }
};

class ClassE : public ClassD {
    public:
    ClassE(){
        std::cout << "ClassE's Empty Constructor is Called" << std::endl;
    }
    ~ClassE(){
        std::cout << "ClassE's Destructor is Called" << std::endl;
    }
};

#endif