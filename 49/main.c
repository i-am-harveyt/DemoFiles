#include <stdio.h>
#include <stdlib.h>
#define MAX_LENGTH 100010

typedef struct carrier{
    int finished, num;
    int* node;
}Carrier;

typedef struct node{
    int key;
    struct node* next;
}Node;

Carrier arr[MAX_LENGTH];
int fail = 0, resultTop = 0, findingIndex, sum = 0;
Node* deletion;

void finding(int result[resultTop][2], int index, Node* head, Node* tail){
    //printf("start finding\n");
    //必須在第二條件判定前更新 finding index.
    if(arr[index].finished < arr[index].num && arr[arr[index].node[arr[index].finished]].finished < arr[arr[index].node[arr[index].finished]].num){
        findingIndex = arr[index].node[arr[index].finished];
        //this vertex is not fully discovered.
        if(index == arr[findingIndex].node[arr[findingIndex].finished]){
            //match, enqueue
            Node* new = (Node*)malloc(sizeof(Node));
            new->key = findingIndex;
            (tail->next)->next = new;
            new->next = tail;
            tail->next = new;
            //add result
            result[resultTop][0] = index;
            result[resultTop][1] = findingIndex;
            //printf("%d %d\n", index+1, findingIndex+1);
            resultTop += 1;
            //move forward
            arr[index].finished += 1;
            arr[findingIndex].finished += 1;
            //finding(result, findingIndex, head, tail);
        }else{
            //mismatch, dequeue.
            deletion = head->next;
            if(deletion->next == tail)
                tail->next = head;
            head->next = deletion->next;
        }
    }else{
        //this vertex is fully discovered.(dequeue)
        deletion = head->next;
        //exception handling
        if(deletion->next == tail)
            tail->next = head;
        head->next = deletion->next;
    }
    //empty?
    while(head->next != tail)
    //if not, finding, use the top key of the queue.
        finding(result, head->next->key, head, tail);
    //if yes, do nothing.
}

int main(void){
    int all, each, input , index = 0;
    Node* head = (Node*)malloc(sizeof(Node));
    Node* tail = (Node*)malloc(sizeof(Node));
    head->next = tail;
    tail->next = head;
    //Construct the adjacency linked list.
    scanf("%d", &all);
    for(int i = 0;i< all;i++){
        scanf("%d", &each);
        int* nodes = (int*)malloc(each * sizeof(int));
        arr[i].num = each;
        arr[i].node = nodes;
        for(int j = 0; j< each; j++){
            scanf(" %d", &input);
            nodes[j] = input - 1;
        }
        arr[i].finished = 0;
        sum += each;
    }

    //run through
    int result[sum/2 + 1][2];
    for(index = 0; index< all; index++){
        if(arr[index].finished < arr[index].num && arr[arr[index].node[arr[index].finished]].finished < arr[arr[index].node[arr[index].finished]].num){
            findingIndex = arr[index].node[arr[index].finished];
            if(index == arr[findingIndex].node[arr[findingIndex].finished]){
                Node* new = (Node*)malloc(sizeof(Node));
                new->key = index;
                head->next = new;
                tail->next = new;
                new->next = tail;
                finding(result, index, head, tail);
            }
        }
    }
    //Print 'em all
    if(resultTop == sum/2){
        printf("Yes\n");
        for(int i = 0; i< resultTop; i++){
            if(result[i][0] < result[i][1])
                printf("%d %d\n", result[i][0] + 1, result[i][1] + 1);
            else
                printf("%d %d\n", result[i][1] + 1, result[i][0] + 1);
        }
    }else
        printf("No\n");
}
