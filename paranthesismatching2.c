#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char data;
    struct node *next;
} node;

typedef struct stack
{
    int size;
    node *top;
} stack;

void initStack(stack *s)
{
    s->size = 0;
    s->top = NULL;
}

int push(stack *s, char data)
{
    node *newNode = (node *)malloc(sizeof(node));
    if (newNode == NULL)
    {
        return 0;
    }
    else
    {
        newNode->data = data;
        newNode->next = s->top;
        s->top = newNode;
        s->size++;
        return 1;
    }
}

int pop(stack *s)
{
    if (s->top == NULL)
    {
        return 0;
    }
    else
    {
        node *p = s->top;
        s->top = p->next;
        s->size--;
        free(p);
        return 1;
    }
}

int paranthesisCheak(char exp[], stack *s )
{
    int i = 0;
    int valid = 1;
    while (exp[i] != '\0')
    {
        if (exp[i] == '{')
        {
            if (!push(s, exp[i]))
            {
                printf("stack overflow!");
                return 0;
            }
        }
        if (exp[i] == '}')
        {
            if (s->top == NULL)
            {
                    valid = 0;     
            }
            else{
                pop(s);
            }
        }
        i++;
    }
    if(valid && s->top == NULL){
        return 1;
    }
    else return 0;
}
void freeStack(stack *s) {
    node *current = s->top;
    node *nextNode;

    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }

    s->top = NULL;
    s->size = 0;
}


int main()
{
    stack s;
    initStack(&s);
    char exp[] = "{{3+2}*{4*{6-9}}}";
    

   if( paranthesisCheak(exp ,&s)){
    printf("balanced");
   }
   else printf("unbalanced");
   freeStack(&s);
   return 0;
   
}