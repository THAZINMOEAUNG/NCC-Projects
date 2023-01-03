//
// Created by Dell on 12/31/2022.
//
#include "stdio.h"
#include "stdlib.h"

#define MAXOFSTACK 10
int toCount=0;
struct stack{
   int data[MAXOFSTACK];
   int top;

};
typedef struct stack st;
int isStackFull(st *myStack){
    if (myStack -> top == MAXOFSTACK-1){
        return 1;
    }else{
        return 0;
    }
}
int isStackIsEmpty(st *myStack){
    if (myStack ->top == -1){
        return 1;
    }else{
        return 0;
    }
}
void emptyStack(st *myStack){
    myStack ->top = -1;
}
void pushToStack(st *myStack , int value){
    if (isStackFull(myStack)){
        printf("Stack is Full!");
    }else{
        myStack -> top++;
        myStack -> data[myStack -> top] = value;
    }
         toCount++;
    printf("Push to stack data is : %d\n",myStack -> data[myStack -> top]);

}
void popFromStack(st *myStack){
if (isStackIsEmpty(myStack)){
    printf("Stack is Empty!");
}else{
    printf("Pop from stack data is : %d\n",myStack -> data[myStack -> top]);
    myStack -> top--;
}
toCount--;
}
int main(){
    st *myStack=(st*)malloc(sizeof(st));
    emptyStack(myStack);

    pushToStack(myStack,10);
    pushToStack(myStack,11);
    pushToStack(myStack,12);
    pushToStack(myStack,13);
    pushToStack(myStack,14);
    printf("\n");
    popFromStack(myStack);
    popFromStack(myStack);
    popFromStack(myStack);
    popFromStack(myStack);
    popFromStack(myStack);


    return 0;
}