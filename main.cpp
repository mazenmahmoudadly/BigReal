#include<iostream>
#include"BigReal.cpp"
using namespace std;
int main(){
    BigReal b1("-20.90000000000001");
    BigReal b2("19.567222222222");
    cout<<b1+b2<<endl;
    cout<<b1-b2<<endl;
BigReal n1 ("20.90000000000001");
BigReal n2 ("19.56722222222");
BigReal n3 = n1 - n2;
cout << n3<<endl;
   
 
}