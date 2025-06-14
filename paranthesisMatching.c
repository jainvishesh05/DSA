#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int capacity;
    int size;
    char *arr;
    int top;
} stack;

void initStack(stack *s, int capacity)
{
    s->capacity = capacity;
    s->size = 0;
    s->arr = (char *)malloc(capacity * (sizeof(char)));
    s->top = -1;
}

int push(stack *s, char data)
{

    if (s->size == s->capacity)
    {
        return -1;
    }
    if (data == '{')
    {
        s->top++;
        s->arr[s->top] = data;
        s->size++;
        return 0;
    }
    else
    {
        return 1;
    }
}
int pop(stack *s)
{
    if (s->top == -1)
    {
        return -1;
    }
    if (s->arr[s->top] == '{')
    {
        s->top--;
        s->size--;
        return 0;
    }
    else
    {
        return 1;
    }
}

int main()
{
    stack s;
    initStack(&s, 20);
    char expr1[] = "{{3+2}*{4*{6-9}}}";
    int length = sizeof(expr1) / sizeof(char);
   for (int i = 0; expr1[i] != '\0'; i++) {
    if (expr1[i] == '{') {
        if (push(&s, '{') == -1) {
            printf("Stack overflow\n");
            break;
        }
    } else if (expr1[i] == '}') {
        if (pop(&s) == -1) {
           
            printf("Unbalanced expression: extra '}' at position %d\n", i);
           
            free(s.arr);
            return 0; 
        }
    }
}

    if (s.size == 0)
    {
        printf("expression is balanced");
        return 1;
    }
    else{
        printf("expression is unbalanced");
    
    return 0;}
}