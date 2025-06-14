#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct circularQueue{
    int *front;
    int*rear;
    int *array;
    int capacity;
    int size;
}list;

void initCircularQueue(list *list , int capacity){
    list->array = (int*)malloc(sizeof(int)*capacity);
    list->capacity  = capacity;
    list->front = list->array;
    list->rear = list->array;
    list->size =0;
}

bool isEmpty(list*list){
    return (list->front == list->rear);
}
bool isFull(list*list){
    return (list->size == list->capacity);
}
void enqueue(list *list,  int data){
    if(isFull(list)){
        printf("queue overflow\n");
        return ;
    }
    else{
        *(list->rear) = data;
        if(list->rear == list->array +list->capacity){
            list->rear  = list->array;
        }
        else{list->rear++;}
        list->size++;
    }
}

void dequeue(list*list){
    if (isEmpty(list)){
        printf("queue underflow\n");
        return ;
    }
    if(list->front == list->array +list->capacity){
         list->front  = list->array;
    }
    else{list->front++;}
    list->size--;
}

void peek(list*list){
    if(isEmpty(list)){
        printf("list is empty\n");
        return ;
    }
    else{
        int* temp = list->front;
        do{
            printf("%d\n",*temp);
             if(temp == list->array +list->capacity){
         temp  = list->array;
    }
    else{temp++;}
        }while(temp != list->rear);
    }
}

int main(){
    list*list = ( struct circularQueue*)malloc(sizeof(struct circularQueue));
    initCircularQueue(list , 4);
    enqueue(list,10);
    enqueue(list,20);
    enqueue(list,30);
    enqueue(list,40);
    enqueue(list,50);
  
    peek(list);
    dequeue(list);
    dequeue(list);
        dequeue(list);
        dequeue(list);
    peek(list);
    enqueue(list , 70);
    enqueue(list , 80);
    enqueue(list , 90);
    peek(list);
    free(list);
}