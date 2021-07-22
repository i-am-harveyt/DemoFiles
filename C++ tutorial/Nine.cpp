#include<iostream>
using namespace std;

int i;
int bigOne(int, int);
int main(){
    i = bigOne(1, 100);
    printf("%d",i);
}
int bigOne(int a, int b){
    if (a>b)
    {
        return a;
    }
    else {return b;}
    
}