//Reference: https://kopu.chat/2017/08/10/%E5%90%88%E4%BD%B5%E6%8E%92%E5%BA%8F-merge-sort/
//Reference:相當感謝討論板上的討論給我莫大啟發 以及數學所的林揚智學長在跟我講述一個討論板上的東西（就是那個對p的預先sort，我一開始看得不是很懂）時幫我釐清觀念。
#include <stdio.h>
#include "generator.h"
#define MAX 1500001

long long resaults[10] = {0};
long long resault = 0;
int tempP1[MAX];
int tempP2[MAX];
int tempQ1[MAX];
int tempQ2[MAX];
int tempR1[MAX];
int tempR2[MAX];

//Merge function for p(take q and r together)
void mergePQR(int* p, int*q, int*r, int left, int mid, int right){
    int lenT1 = mid - left + 1, lenT2 = right - (mid + 1) + 1;

    for(int i = 0; i< lenT1; i++){
        tempP1[i] = p[left + i];
        if(q[left+ i] < r[left + i]){
            tempQ1[i] = q[left + i];
            tempR1[i] = r[left + i];
        }else{
            tempQ1[i] = r[left + i];
            tempR1[i] = q[left + i];
        }
    }
    for(int i = 0; i< lenT2; i++){
        tempP2[i] = p[mid + 1 + i];
        if(q[mid + 1 + i] < r[mid + 1 + i]){
            tempQ2[i] = q[mid + 1 + i];
            tempR2[i] = r[mid + 1 + i];
        }else{
            tempQ2[i] = r[mid + 1 + i];
            tempR2[i] = q[mid + 1 + i];
        }
    }

    int cur1 = 0, cur2 = 0, current = left;
    while(cur1 < lenT1 && cur2 < lenT2){
        if(tempP1[cur1]< tempP2[cur2]){
            p[current] = tempP1[cur1];
            q[current] = tempQ1[cur1];
            r[current] = tempR1[cur1];
            cur1 += 1;
        }else if(tempP1[cur1] == tempP2[cur2]){
            if(tempR1[cur1] >= tempR2[cur2]){
                p[current] = tempP1[cur1];
                q[current] = tempQ1[cur1];
                r[current] = tempR1[cur1];
                cur1 += 1;
            }else{
                p[current] = tempP2[cur2];
                q[current] = tempQ2[cur2];
                r[current] = tempR2[cur2];
                cur2 += 1;
            }
        }else{
            p[current] = tempP2[cur2];
            q[current] = tempQ2[cur2];
            r[current] = tempR2[cur2];
            cur2 += 1;
        }
        current += 1;
    }
    while(cur1 < lenT1){
        p[current] = tempP1[cur1];
        r[current] = tempR1[cur1];
        q[current] = tempQ1[cur1];
        current += 1;
        cur1 += 1;
    }
    while(cur2 < lenT2){
        p[current] = tempP2[cur2];
        r[current] = tempR2[cur2];
        q[current] = tempQ2[cur2];
        current += 1;
        cur2 += 1;
    }
}
//Merge function address to q and r
void mergeQR(int* q, int*r, int left, int mid, int right){
    int lenT1 = mid -left + 1, lenT2 = right - (mid + 1) + 1;
    for(int i = 0; i< lenT1; i++){
        tempQ1[i] = q[left + i];
        tempR1[i] = r[left + i];
    }
    for(int i = 0; i< lenT2; i++){
        tempQ2[i] = q[mid + 1 + i];
        tempR2[i] = r[mid + 1 + i];
    }
    int cur1, cur2, current;
    //merge q
    cur1 = 0;
    cur2 = 0;
    current = left;
    while(cur1 < lenT1 && cur2 < lenT2){
        if(tempQ1[cur1] < tempQ2[cur2]){
            q[current] = tempQ1[cur1];
            cur1 += 1;
        }else{
            q[current] = tempQ2[cur2];
            cur2 += 1;
        }
        current += 1;
    }
    while(cur1 < lenT1){
        q[current] = tempQ1[cur1];
        current += 1;
        cur1 += 1;
    }
    while(cur2 < lenT2){
        q[current] = tempQ2[cur2];
        current += 1;
        cur2  += 1;
    }
    //merge r
    cur1 = 0;
    cur2 = 0;
    current = left;
    while(cur1 < lenT1 && cur2 < lenT2){
        if(tempR1[cur1] < tempR2[cur2]){
            r[current] = tempR1[cur1];
            cur1 += 1;
        }else{
            r[current] = tempR2[cur2];
            cur2 += 1;
        }
        current += 1;
    }
    while(cur1 < lenT1){
        r[current] = tempR1[cur1];
        current += 1;
        cur1 += 1;
    }
    while(cur2 < lenT2){
        r[current] = tempR2[cur2];
        current += 1;
        cur2  += 1;
    }
    //printf("Merge Complete\n");
}

//Merge sort function for p.
void mergeSortPQR(int* p, int* q, int*r, int left, int right){
    if(left < right){
        //Let's merge sort p first and they'll take q and r together
        mergeSortPQR(p, q, r, left, left + (right - left) / 2);
        mergeSortPQR(p, q, r, left + (right - left) / 2 + 1, right);
        mergePQR(p, q, r, left, left + (right - left) / 2, right);
    }
}

//Merge sort function for q and r
void mergeSortQR(int* q, int*r, int left, int right){
    if(left < right){
        //Let's mergeSort q and r
        mergeSortQR(q, r, left, left + (right - left) / 2);
        mergeSortQR(q, r, left + (right - left) / 2 + 1, right);
        //before merging them, check the intersection, CHECK AGAIN!
        int i = 0, j = 0, mid = left + (right - left)/2;
        for(i = 0; i< mid - left + 1; i++){
             while(r[left + i] >= q[mid+1+j]){
                if(j == right - mid)
                    break;
                j += 1;
            }
            resault += j;
        }
        //merge q and r
        mergeQR(q, r, left, mid, right);
    }
}

//main function
int main() {
    generator.init();
    int t = generator.getT();
    int count = 0;
    while (t--) {
        int n, *p, *q, *r;
        generator.getData(&n, &p, &q, &r);
        mergeSortPQR(p, q, r, 0, n - 1);
        mergeSortQR(q, r, 0, n - 1);
        resaults[count] += resault;
        resault = 0;
        count += 1;
    }
    for (int i = 0; i < count; i++) {
        printf("%lld\n", resaults[i]);
    }
}
