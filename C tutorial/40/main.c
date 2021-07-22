//reference:
//1. 參考了其中的priority函數以及被提醒do while及while的差異。
//https://lakesd6531.pixnet.net/blog/post/344460826
//2. 在討論板上看到一同學說自己邊做infix轉postfix邊計算而受到啟發，但我沒有跟人討論過這個部分。

#include <stdio.h>
#include <float.h>
#include <stdlib.h>
#define MAX_LENGTH 1000000

//priority
int priority(char opr);
//calculate
double calculate(double a, double b, char opr);
//global variables，那麼大的東西應該要開在全域變數才不會一直吃到stack
char str[MAX_LENGTH] = {'\0'};
double valueStack[MAX_LENGTH] = {0.0};
double output[MAX_LENGTH] = {0.0};
int outputCount = 0;
char stack[(MAX_LENGTH)/2+1] = {' '};
//main
int main(void){
    int valueTop = 0;
    while(~scanf("%s", str)){
        int stackTop = 0;
        //嘗試在infix轉posfix時同時做計算
        for (int i = 0; i < sizeof(str); i++)
        {
            if(str[i] == '\0'){
                while(stackTop>0){
                    valueStack[valueTop-1] = calculate(valueStack[valueTop-1], valueStack[valueTop], stack[stackTop-1]);
                    valueStack[valueTop] = 0;
                    stack[stackTop-1] = ' ';
                    stackTop -= 1;
                    valueTop -= 1;
                }
                break;
            }
            //operators and numbers
            switch(str[i]){
                case '+': case '-': case '*': case '/':
                    while(priority(str[i]) <= priority(stack[stackTop - 1])){
                        valueStack[valueTop-1] = calculate(valueStack[valueTop-1], valueStack[valueTop], stack[stackTop - 1]);
                        stack[stackTop-1] = ' ';
                        stackTop -= 1;
                        valueStack[valueTop] = 0.0;
                        valueTop -= 1;
                    };
                    stack[stackTop] = str[i];
                    stackTop += 1;
                    valueTop += 1;
                    break;
                case '(':
                    stack[stackTop] = '(';
                    stackTop += 1;
                    break;
                case ')':
                    while(stack[stackTop-1] != '('){
                        valueStack[valueTop-1] = calculate(valueStack[valueTop-1], valueStack[valueTop], stack[stackTop-1]);
                        valueStack[valueTop] = 0;
                        valueTop -= 1;
                        stack[stackTop-1] = ' ';
                        stackTop -= 1;
                    }
                    stack[stackTop-1] = ' ';
                    stackTop -= 1;
                    break;
                default:
                    valueStack[valueTop] = 10 * valueStack[valueTop] + (double)(str[i] - '0');
                    break;
            }
            str[i] = '\0'; //initialize
        }
        output[outputCount] = valueStack[0];
        //initialize
        valueStack[0] = 0.0;
        valueTop = 0;
        outputCount += 1;
    }
    for (int i = 0; i < outputCount; i++)
    {
        printf("%.15lf\n", output[i]);
    }
}

int priority(char opr){
    if (opr=='+'||opr=='-') {
        return 1;
    }else if (opr=='*'||opr=='/'){
        return 2;
    }else if (opr==' ')
        return 0;
    else
        return -1;
}

double calculate(double a, double b, char opr){
    switch(opr){
        case '+':
            return a + b;
            break;
        case '-':
            return a - b;
            break;
        case '*':
            return a * b;
            break;
        case '/':
            return a / b;
            break;
        default:
            return 0;
    }
    return 0;
}
