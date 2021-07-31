#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int Data;
    struct Node *Next;
}*first=NULL;

void Create(int A[], int n)
{
    struct Node *t, *last;
    int i;
    
    first = (struct Node *)malloc(sizeof(struct Node));
    first->Data = A[0];
    first->prev = first->Next = NULL;
    last=first;

    for(i=1; i<n; i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->Data = A[i];
        t->Next = last->Next;
        t->prev = last;
        last->Next = t;
        last = t;
    }
}

int Delete(struct Node *p, int index)
{
    struct Node *q;
    int x=-1,i;

    if(index < 1 || index > Length(p))
        return -1;

    if (index == 1)
    {
        first = first->Next;
        if (first) first->prev=NULL;

        x = p->Data;
        free(p);
    }
    else
    {
        for(i=0; i<index-1; i++)
            p = p->Next;
        p->prev->Next = p->Next;
        if(p->Next)
            p->Next->prev = p->prev;
        x = p->Data;
        free(p);
    }
    return x;
}

void Insert(struct Node *p, int index, int x)
{
    struct Node *t;
    int i;

    if(index < 0 || index > Length(p))
        return;
    if(index == 0)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->Data = x;
        t->prev = NULL;
        t->Next = first;
        first->prev = t;
        first = t;
    }
    else
    {
        for(i=0; i<index-1; i++)
            p = p->Next;
        t = (struct Node *)malloc(sizeof(struct Node));
        t->Data = x;
        t->prev = p;
        t->Next = p->Next;

        if(p->Next) p->Next->prev = t;
        p->Next = t;
    }
}

void Reverse(struct Node *p)
{
    struct Node *temp;

    while(p != NULL)
    {
        temp = p->Next;
        p->Next = p->prev;
        p->prev = temp;
        p = p->prev;
        if(p != NULL && p->Next == NULL)
            first = p;
    }
}

void Display(struct Node *p)
{
    while(p != NULL)
    {
        printf("%d ", p->Data);
        p = p->Next;
    }
    printf("\n");
}

int Length(struct Node *p)
{
    int len=0;
    while(p != NULL)
    {
        len++;
        p = p->Next;
    }
    return len;
}

int main()
{
    int A[]={10,20,30,40,50};
    Create(A,5);
    Reverse(first);
    printf("\nLength is : %d\n", Length(first));
    Display(first);

    return 0;
}