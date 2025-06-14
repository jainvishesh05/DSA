#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct stack{
    int top;
    char* arr;
    int capacity;
}stack;

void initStack(stack*s ,  int capacity){
    s->top = -1;
    s->capacity = capacity;
    s->arr = (char*)malloc(sizeof(char) * s->capacity);
    if(s->arr == NULL){
        printf("memory allocation failed\n");
        return;
    }
}

bool isFull(stack* s){
  return s->top == s->capacity-1 ; 
}
bool isEmpty(stack* s){
   return s->top == -1 ;
}

void push(stack *s , char data){
    if(isFull(s)){
        printf("stack overload!\n");
        return ;
    }
    s->top++;
    s->arr[s->top] = data;
}

char pop(stack *s){
    if (isEmpty(s)){
        printf("stack underflow!\n");
        return '\0';
    }
    char temp = s->arr[s->top];
    s->top--;
    return temp;
}


int select(){
    int selection;
    printf("select your operation\n");
    printf("1.infix to postfix\n");
    printf("2.infix to prefix\n");
    printf("3.postfix to prefix\n");
    printf("4.prefix to postfix\n");
    printf("5.postfix to infix\n");
    printf("6.prefix to infix\n");
    scanf("%d",&selection);
    if(selection > 6 || selection < 1){
        printf("\"ENTER A VALID SELECTION !\"\n");
        return 0; 
    }
    printf("your selection is %d \n" , selection);
    return selection ;
}

int precedence(char ch){
    if(ch == '*' || ch == '/'){
        return 3;
    }
    else if(ch == '+' /  ch == '-'){
        return 2;
    }
    else{
        return 0;
    }
}

isOperator(char ch) {
    if(ch =='+' || ch=='-' || ch == '*' || ch == '/'){
        return 1;
    }
    return 0;
}

char* infixToPostfix(char* infix){
    stack s;
    initStack(&s, 100);
    char*postfix = (char*)malloc(sizeof(char)*strlen(infix)+1);
    int i=0;//infix scanner
    int j=0;//postfix filler
    while(infix[i] != '\0'){
        if(!isOperator(infix[i])){
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else{
            if(isEmpty(&s) || precedence(infix[i])>precedence(s.arr[s.top])){
                push(&s , infix[i]);
                i++;
            }
            else{
                postfix[j] = pop(&s);
                j++;
            }
        }
        
    }
    while(!isEmpty(&s)){
            postfix[j] = pop(&s);
            j++;
        }
        postfix[j] = '\0';
    return postfix;
}

char* infixToPrefix(char* infix){
    
}

int main(){
  
   char infix[] = "a+b-c";
   char* postfix = infixToPostfix(infix);
   printf("Postfix: %s\n", postfix);

   return 0;
}