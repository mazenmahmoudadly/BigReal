#ifndef BIGREAL_BIGDECIMALINTCLASS_H
#define BIGREAL_BIGDECIMALINTCLASS_H
#include<iostream>
#include<deque>
#include<regex>
using namespace std;
class BigReal {
private:
    string number;
    char sign{};
    string fraction;
    string whole;

    static bool checkValidInput(const string &input);

public:

    friend ostream &operator<<(ostream &out, const BigReal &num);

    BigReal operator+(BigReal num2);

    BigReal operator-(BigReal num2);

    void setNumber(const string &numb);

    string getNumber() { return number; }

    BigReal() = default;

    explicit BigReal(string num);
    bool operator< (BigReal anotherReal);
     bool operator> (BigReal anotherReal);
     char Sign();
     int Size();
    bool operator== (BigReal anotherReal);
    friend istream& operator >> (istream& in, BigReal &num);
};
#endif
