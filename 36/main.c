//reference:
//https://www.geeksforgeeks.org/xor-linked-list-a-memory-efficient-doubly-linked-list-set-2/
//一位不知道名字的高個子戴眼鏡男同學（找助教問問題時遇到的），他告訴了我題目裡面埋的梗（算埋嗎），也就是XOR Linked list，所以我才再去找助教跟查資料。感謝數學所的林同學給了我他寫的測資生產器
#include <stdio.h>
#include <stdlib.h>
int test=0;

//Define struct Cabin
typedef struct cabin{
    int data;
    struct cabin *ptr;
}Cabin;

//The XOR function
Cabin* XOR(Cabin* a, Cabin* b){
    return (Cabin*)((unsigned int)(a)^(unsigned int)(b));
}

//Enter function
void enter(int data, Cabin** headptr, Cabin** tailptr){
    if(test)
        printf("start enter\n");
    Cabin* add = (Cabin*)malloc(sizeof(Cabin));
    add->data = data;
    add->ptr = XOR(*tailptr, NULL);
    //If there is no tail, which means there is no cabin in the rail.
    if (*tailptr == NULL){
        *headptr = add;
    }else{
        //prev of tail is the XOR of the ptr of (old)tail and NULL
        Cabin* prev = XOR((*tailptr)->ptr, NULL);
        //Update the old tail's ptr to XOR of add and prev of tail.
        (*tailptr)->ptr = XOR(add, prev);
    }
    //Update the tail to the new add one.
    *tailptr = add;
    if(test)
        printf("end enter\n");
}

//Leave function
void leave(Cabin** headptr, Cabin** tailptr){
    if(test)
        printf("start leave\n");
    Cabin* oldTail = *tailptr;
    //tail == head, which means there is only one or no cabin(NULL == NULL) in the rail.
    if(*tailptr == *headptr){
        *tailptr = NULL;
        *headptr = NULL;
    }else{
        //The new tail, which means the prev of old tail, is XOR of old tail's ptr and NULL.
        Cabin* newTail = XOR(oldTail->ptr, NULL);
        //The new tail's prev is XOR of the ptr of new tail and old tail.
        Cabin* prev = XOR(newTail->ptr, oldTail);
        //Update the ptr of new tail to XOR of prev of new tail and NULL.
        newTail->ptr = XOR(prev, NULL);
        //Update tail to new tail.
        *tailptr = newTail;
    }
    free(oldTail);
    if(test)
        printf("end leave\n");
}

//Migrate function
void migrate(Cabin** fromHead, Cabin** fromTail, Cabin** toHead, Cabin** toTail){
    //from is not empty, to is empty
    if((*fromHead != NULL)&&(*toHead == NULL)){
        *toTail = *fromHead;
        *toHead = *fromTail;
        *fromHead = NULL;
        *fromTail = NULL;
    }
    //from is not empty, to is not empty
    else if((*fromHead != NULL)&&(*toHead != NULL)){
        Cabin* fromTailPrev = XOR((*fromTail)->ptr, NULL);
        Cabin* toTailPrev = XOR((*toTail)->ptr, NULL);
        (*fromTail)->ptr = XOR(fromTailPrev, *toTail);
        (*toTail)->ptr = XOR(toTailPrev, *fromTail);;
        *toTail = *fromHead;
        *fromTail = NULL;
        *fromHead = NULL;
    }
}

//printData function
void printData(Cabin* head){
    if(test)
        printf("start print\n");
    Cabin* current = head;
    Cabin* prev = NULL;
    Cabin* next;
    //If currnet is not NULL, then we can examine whether next == NULL
    while(current != NULL){
        next = XOR(prev, current->ptr);
        //If next == NULL, which means current is tail.
        if(next == NULL){
            printf("%d\n", current->data);
            break;
        }else{
            printf("%d ", current->data);
            //update
            prev = current;
            current = next;
        }
    }
    if(test)
        printf("end print\n");
}

int main(void){
    int rails, steps;
    scanf("%d %d", &rails, &steps);
    Cabin* headptrs[rails];
    Cabin* tailptrs[rails];
    for(int i  = 0; i< rails; i++){
        headptrs[i] = NULL;
        tailptrs[i] = NULL;
    }
    char command[10];
    int input1, input2;
    while(steps>0){
        scanf("%s", command);
        switch(command[0]){
            case'e':
                scanf(" %d %d", &input1, &input2);
                if(test)
                    printf("%s %d %d\n", command, input1, input2);
                enter(input2, &headptrs[input1], &tailptrs[input1]);
                break;
            case'l':
                scanf(" %d", &input1);
                if(test)
                    printf("%s %d\n", command, input1);
                leave(&headptrs[input1], &tailptrs[input1]);
                break;
            case'm':
                scanf(" %d %d", &input1, &input2);
                if(test)
                    printf("%s %d %d\n", command, input1, input2);
                migrate(&headptrs[input1], &tailptrs[input1], &headptrs[input2], &tailptrs[input2]);
                break;
        }
        steps -= 1;
    }
    if(test)
        printf("start print\n");
    for (int i = 0; i < rails; i++){
        if (tailptrs[i] != NULL){
            printData(headptrs[i]);
        }else{
            printf("\n");
        }
    }
}
