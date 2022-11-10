#ifndef BIGREAL_BIGDECIMALINTCLASS_H
#define BIGREAL_BIGDECIMALINTCLASS_H
#include<iostream>
#include<deque>
#include<regex>
using namespace std;
class BigReal{
    private:
        string number;
        char sign{};

        static bool checkValidInput(const string& input);
    public:
        friend ostream &operator << (ostream &out, const BigReal& num);
        BigReal operator+(BigReal num2);
        BigReal operator-(BigReal num2);
        void setNumber(const string& numb);
        string getNumber(){return number;}
        BigReal()= default;
        explicit BigReal(string num){setNumber(num);}
};
#endif