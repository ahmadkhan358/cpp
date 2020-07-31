#include<iostream>
using namespace std;

int main(){

    int a = 5;
    int b = 10;

    a = a + b;

    cout<<a<<endl;

    b = a - b;

    cout<<b<<endl;
    
    a = a - b;

    cout<<a<<endl;

    cout<<a<<endl<<b<<endl;

    system("pause");
    return 0;
}