#include"BigReal.h"
void makeEqualAtFront(deque<int>& A,
                      deque<int>& B)
{
    int n = A.size();
    int m = B.size();
    int diff = abs(n - m);
   
    if (n < m) {
        for (int i = 0; i < diff; i++) {
            A.insert(A.begin(), 0);
        }
    }
    else {
        for (int i = 0; i < diff; i++) {
            B.insert(B.begin(), 0);
        }
    }
}


void makeEqualAtback(deque<int>& A,
                     deque<int>& B)
{
    int n = A.size();
    int m = B.size();
    int diff = abs(n - m);
   
    if (n < m) {
        for (int i = 0; i < diff; i++) {
            A.push_back(0);
        }
    }
    else {
        for (int i = 0; i < diff; i++) {
            B.push_back(0);
        }
    }
}

 
// Function for find difference of larger numbers
string subraction(string num1, string num2){
    int i;
   string res;
    // To store the integer and
    // fractional part of numbers
    deque<int> Ints1, Ints2;
    deque<int> Fracs1, Fracs2;
   
    // Separating integer and
    // fractional part of num1
    for (i = num1.length() - 1; i > -1; i--) {
   
        // If decimal occurs break
        if (num1[i] == '.') {
            break;
        }
        Fracs1.push_back(num1[i] - '0');
    }
   
    i--;
    for (; i > -1; i--) {
        Ints1.push_back(num1[i] - '0');
    }
   
    // Separating integer and
    // fractional part of num2
    for (i = num2.length() - 1; i > -1; i--) {
   
        // If decimal occurs break
        if (num2[i] == '.') {
            break;
        }
        Fracs2.push_back(num2[i] - '0');
    }
   
    i--;
    for (; i > -1; i--) {
        Ints2.push_back(num2[i] - '0');
    }
   
    // Making number of digits in
    // fractional and Integer
    // part equal
    makeEqualAtFront(Fracs1, Fracs2);
    makeEqualAtback(Ints1, Ints2);
   
    // Adding fractional parts of
    // num1 and num2
    int n = Fracs1.size();
    int m = Fracs2.size();
    i = 0;
    int carry = 0;
   
    while (i < n && i < m) {
   
        // Traverse the Fracs1[] and
        // Fracs2[] and add the digit
        // and store the carry
        int sum = Fracs1[i]
                  - Fracs2[i]
                  + carry;
        if(sum<0){
            carry=-1;
            Fracs1[i]=(10+sum)%10;
        }
        else{
        Fracs1[i] = sum % 10;
        carry = sum / 10;
        }
        i++;
    }
   
    int N = Ints1.size();
    int M = Ints2.size();
    i = 0;
   
    // Adding integer part of
    // num1 and num2
    while (i < N && i < M) {
        int sum = Ints1[i]
                  - Ints2[i]
                  + carry;
        if(sum<0){
            carry=-(1);
            Ints1[i]=(10+sum)%10;
        }
        else{
        Ints1[i] = sum % 10;
        carry = sum / 10;
        }
        i++;
    }
   
    // Print the result by appending
    // Integer and decimal part stored
    // in Ints1[] and Fracs1[]
    
    for (int i = Ints1.size() - 1; i > -1; i--) {
      res+=to_string( Ints1[i]);
    }
   res+='.';
    for (int i = Fracs1.size() - 1; i > -1; i--) {
        res+=to_string(Fracs1[i]);
    }
    return res;
}


string addition(string num1,string num2){
int i;
   string res;
    // To store the integer and
    // fractional part of numbers
    deque<int> Ints1, Ints2;
    deque<int> Fracs1, Fracs2;
   
    // Separating integer and
    // fractional part of num1
    for (i = num1.length() - 1; i > -1; i--) {
   
        // If decimal occurs break
        if (num1[i] == '.') {
            break;
        }
        Fracs1.push_back(num1[i] - '0');
    }
   
    i--;
    for (; i > -1; i--) {
        Ints1.push_back(num1[i] - '0');
    }
   
    // Separating integer and
    // fractional part of num2
    for (i = num2.length() - 1; i > -1; i--) {
   
        // If decimal occurs break
        if (num2[i] == '.') {
            break;
        }
        Fracs2.push_back(num2[i] - '0');
    }
   
    i--;
    for (; i > -1; i--) {
        Ints2.push_back(num2[i] - '0');
    }
   
    // Making number of digits in
    // fractional and Integer
    // part equal
    makeEqualAtFront(Fracs1, Fracs2);
    makeEqualAtback(Ints1, Ints2);
   
    // Adding fractional parts of
    // num1 and num2
    int n = Fracs1.size();
    int m = Fracs2.size();
    i = 0;
    int carry = 0;
   
    while (i < n && i < m) {
   
        // Traverse the Fracs1[] and
        // Fracs2[] and add the digit
        // and store the carry
        int sum = Fracs1[i]
                  + Fracs2[i]
                  + carry;
   
        Fracs1[i] = sum % 10;
        carry = sum / 10;
        i++;
    }
   
    int N = Ints1.size();
    int M = Ints2.size();
    i = 0;
   
    // Adding integer part of
    // num1 and num2
    while (i < N && i < M) {
        int sum = Ints1[i]
                  + Ints2[i]
                  + carry;
        Ints1[i] = sum % 10;
        carry = sum / 10;
        i++;
    }
    if (carry != 0)
        Ints1.push_back(carry);
   
    // Print the result by appending
    // Integer and decimal part stored
    // in Ints1[] and Fracs1[]
    
    for (int i = Ints1.size() - 1; i > -1; i--) {
      res+=to_string( Ints1[i]);
    }
   res+='.';
    for (int i = Fracs1.size() - 1; i > -1; i--) {
        res+=to_string(Fracs1[i]);
    }
    return res;
}


void BigReal::setNumber(const string& numb){
    bool validNumber=checkValidInput(numb);
    if(validNumber){
        number=numb;
        if(number[0]=='+'){
            number.erase(0,1);
            sign='+';
        }
        else if(number[0]=='-'){
            number.erase(0,1);
            sign='-';
        }
        else{
            sign='+';
        }
    }
    else{
        cout<<"invalid"<<endl;
        exit(1);
    }
}


bool BigReal::checkValidInput(const string& input){
        regex validInput("[+-]?([0-9]*[.])?[0-9]+");
    return regex_match(input, validInput);
}


ostream &operator << (ostream &out, const BigReal& num)
{
    if(num.sign == '+')
    {
        out << num.number ;
    }
    else
    {
        if(num.number == "0")
        {
            out << num.number ;
        }
        else
        {
            out << num.sign << num.number ;
        }
    }
    return out;
}


BigReal BigReal:: operator-(BigReal number2){
    string strmin = "", res = "";
    string num1 = number, num2 = number2.number;
    char sign1 = sign, sign2 = number2.sign;
BigReal result;
result.number = subraction(num1,num2);

    bool ok = false, is_determined = false;
    if (num1 < num2)
    {
        swap(num1, num2);
        swap(sign1, sign2);
        ok = true;
    }

    if (sign1 == sign2 )
    {
        res = subraction(num1,num2);

        if(sign1=='-')ok = !ok;
    }
    else
    {
        res = addition(num1,num2);
        if(sign == '-')
        {
            result.sign = '-';
            is_determined = true;
        }
        else
        {
            result.sign = '+';
            is_determined = true;
        }

    }

    bool right = false;
    for (long long i = 0; i < res.length(); i++)
    {
        if (res[i] != '-' && res[i] != '0')
        {
            right = true;
        }
        if (!right && res[i] == '0')
        {
            res.erase(i, 1);
            i--;
        }
    }

    if(res.empty()) res = "0";
    if (!is_determined && (ok))
    {
        result.sign = '-';
    }
    else if(!is_determined)
    {
        result.sign = '+';
    }

    result.number = res;
    return result;
return result;


}


BigReal BigReal:: operator+(BigReal number2){
char signNumber1 = sign, signNumber2 = number2.sign;
  string num1 = number, num2 = number2.number;
    BigReal number1 = *this;
BigReal result;

        while (num1.length() < num2.length()){
        num1 = '0' + num1;
    }
    while (num2.length() < num1.length()){
        num2 = '0' + num2;
    }

    if (signNumber1 == signNumber2){
        result.sign = signNumber1;
        result.number = addition(num1,num2);

    }else{

        if(number1.sign == '-')
        {
            number1.sign = '+';
            result = (number2 - number1);
        }
        else{
            number2.sign = '+';
            result = (number1 - number2);
        }
    }
return result;

}
