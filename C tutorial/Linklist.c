#include <stdio.h>
#include <stdlib.h>

//car
typedef struct car{
    int data;
    struct car *next, *previous;
}Car;
//create node
Car *addCar(int data, Car *previous){
    Car *add = (Car*)malloc(sizeof(Car));
    add->data = data;
    add->previous = previous;
    add->next = NULL;
    return add;
}
//delete the node
Car *removeCar(Car *tail){
    Car* newTail = tail->previous;
    newTail->next = NULL;
    tail->previous = NULL;
    free(tail);
    return newTail;
}
//print each node
void printNodes(Car *car){
    for(;car != NULL;car = car->next)
        printf("%d ", car->data);
}
//main
int main(void){
    Car* head;
    Car* tail = head;
    int input;
    while(~scanf("%d", &input)){
        tail->next = addCar(input, tail);
        tail = tail->next;
    }
    printNodes(head->next);
    printf("\n");
    removeCar(tail);
    printNodes(head->next);

}
