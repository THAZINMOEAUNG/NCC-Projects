//
// Created by Dell on 12/31/2022.
//
//
// Created by Dell on 12/30/2022.
//
#include <stdio.h>
#include <math.h>
int step,j;
int min(int first , int second){
    if (second > first){
        return first;
    }else{
        return second;
    }
}
int oddNumber(int size){
    int i = 1,count=0;
    if (size < 0){
        return -1;
    }
    while (size >= i){
        size = size - i;
        i = i +2;
        count++;
    }
    return count;
}
int jumpSearch(int arr[], int size, int key) {
     step = oddNumber(size);
    int previous = 0;
    while (arr[min(step, size) - 1] < key) {
        previous = step;
        step = step +  oddNumber(size);
        if (previous >= size) {
            return -1;
        }
    }
    if (key == arr [step-1]){
        printf("Step number and key are the same!\n");
        return step-1;
    }else{
        for (int j = previous; j < step; j++) {
            if (arr[j] == key) {
                printf ("Linear Search!\n");
                return j;
            }
        }
    }
    return -1;
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,100,101,102,108,200};
    int size = sizeof(arr) / sizeof(arr[0]);
    int toFind =9;

    int indexNumber = jumpSearch(arr , size , toFind);
    if (indexNumber != -1) {
            printf("We found!\n");
            printf("Found at index: %d\ndata : %d", indexNumber, arr[indexNumber]);
    }else{
        printf("Not found!\n");
    }
    return 0;
}