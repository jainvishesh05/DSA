#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct stack
{
    int capacity;
    int size;
    Node *top;
} stack;

void initStack(stack *s, int capacity)
{
    s->capacity = capacity;
    s->size = 0;
    s->top = NULL;
}

int isFull(stack s)
{
    return (s.size == s.capacity);
}

int isEmpty(stack s)
{
    return (s.top == NULL);
}

void push(stack *s, int value)
{
    if (isFull(*s))
    {
        printf("stack overflow\n");
        return;
    }
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
    s->size++;
}

int pop(stack *s)
{
    int data;
    if (isEmpty(*s))
    {
        printf("stack underflow\n");
        return -1;
    }

    else
    {
        Node *p = s->top;
        data = p->data;
        s->top = p->next;
        free(p);
        s->size--;
        return data;
    }
}

int peek(stack s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty\n");
        return -1; // or some error value
    }
    return s.top->data;
}
void traverse(stack s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty\n");
        return;
    }

    Node *current = s.top;
    printf("Stack contents (top to bottom): ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
int getBottom(stack s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty\n");
        return -1; // Or some error value
    }

    Node *current = s.top;
    while (current->next != NULL)
    {
        current = current->next;
    }

    return current->data;
}

int main()
{
    stack s;
    initStack(&s, 3);
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    traverse(s);
    printf("Top element is: %d\n", peek(s));
    printf("%d and %d popped from the stack \n", pop(&s), pop(&s));

    printf("Bottom element is: %d\n", getBottom(s));
}
