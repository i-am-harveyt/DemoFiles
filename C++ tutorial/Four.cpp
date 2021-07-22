#include<iostream>

using namespace std;

int main(void){
    int n = 11;
    cout << n << endl;

    int *np = &n;
    cout << np << endl;
    cout << *np << endl;

    int t = *np;
    cout << t << endl;
    cout << &t << endl;
    cout << &n << endl;
    cout << &np << endl;
    
    return 0;
}