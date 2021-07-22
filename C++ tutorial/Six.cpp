#include<iostream>

using namespace std;

int main(){
    int a;
    a = 3;
    cout << a << endl;
    int b = ++a;
    cout << b << endl;
    a = 3;
    int c = a++;
    cout << c << endl;
    a = 3;
    int d = --a;
    cout << d << endl;
    a = 3;
    int e = a--;
    cout << e << endl;
    printf("%d,%d,%d,%d,%d\n",a,b,c,d,e);
}