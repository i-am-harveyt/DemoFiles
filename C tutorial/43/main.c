#include<stdio.h>
#include<stdlib.h>

//Define the struct node
typedef struct node{
    int data;
    struct node* leftChild;
    struct node* rightChild;
}Node;


Node* allNode[1000000];
int count = 0;

int maxOf(int a, int b){
    if(a>b)
        return a;
    else
        return b;
}

int minOf(int a, int b){
    if(a<b)
        return a;
    else
        return b;
}

void search(Node* node, int left, int right){
    if(node == NULL){
        
    }else{
        if((node->data <= right)&&(node->data >= left))
            count += 1;
        if(node->data > left)
            search(node->leftChild, left, minOf(right, node->data));
        if(node->data < right)
            search(node->rightChild, maxOf(left, node->data), right);
    }
}

int main(void){
    int times = 0, key = 0;
    scanf("%d", &times);
    int data = 0, left = 0, right = 0, maxData = 0;
    for (int i = 0; i<times; i++) {
        allNode[i] = (Node*)malloc(sizeof(Node));
    }
    while(times - count > 0){
        //Get data
        scanf("%d %d %d", &data, &left, &right);
        if (data>maxData)
            maxData = data;
        //add data
        allNode[key]->data = data;
        if (left == -1)
            allNode[key]->leftChild = NULL;
        else
            allNode[key]->leftChild = allNode[left-1];
        if (right == -1)
            allNode[key]->rightChild = NULL;
        else
            allNode[key]->rightChild = allNode[right-1];
        //finish this round
        key += 1;
        count += 1;
    }
    count = 0;
    left = 0;
    right = maxData;
    int mid = allNode[0]->data;
    //Search
    //Left traversal
    search(allNode[0], left, mid);
    //Right traversal
    search(allNode[0], mid, right);
    //兩個search都會算到root，會多抓一次
    count -= 1;
    printf("%d\n", count);
}
