#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *Prev;
    int Data;
    struct Node *Next;
}*first=NULL;

void Create_circulaire(int A[], int n)
{
    struct Node *t, *last;
    int i;

    first = (struct Node *)malloc(sizeof(struct Node));
    first->Data = A[0];
    first->Prev = first;
    first->Next = first;
    last = first;

    for(i=1;i<n;i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->Data = A[i];
        t->Next = first;
        last->Next = t;
        t->Prev = last;
        last = t;
    }
}

int Length_circulaire(struct Node *p)
{
    int len=0;
    p = first;
    do
    {
        len++;
        p = p->Next;
    } while (p != first);
    return len;
}

void Create(int A[], int n)
{
    struct Node *t, *last;
    int i;
    
    first = (struct Node *)malloc(sizeof(struct Node));
    first->Data = A[0];
    first->Prev = first->Next = NULL;
    last=first;

    for(i=1; i<n; i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->Data = A[i];
        t->Next = last->Next;
        t->Prev = last;
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
        if (first) first->Prev=NULL;

        x = p->Data;
        free(p);
    }
    else
    {
        for(i=0; i<index-1; i++)
            p = p->Next;
        p->Prev->Next = p->Next;
        if(p->Next)
            p->Next->Prev = p->Prev;
        x = p->Data;
        free(p);
    }
    return x;
}

int Delete_circulaire(struct Node *p, int index)
{
    struct Node *t;
    int i,x;

    if (index < 0 || index > Length_circulaire(p))
        return;
    if (index == 1)
    {
        while(p->Next != first) p = p->Next;
        x = first->Data;
        if (p == first)
        {
            free(first);
            first == NULL;
        }
        else
        {
            p->Next = first->Next;
            first->Next->Prev = p;
            free(first);
            first = p->Next;
        }
    }
    else
    {
        for(i=0;i<index-2;i++) p = p->Next;
        t = p->Next;
        p->Next = t->Next;
        t->Next->Prev = p;
        x = t->Data;
        free(t);
    }
    return x;
}

void Insert_circulaire(struct Node *p, int index, int x)
{
    struct Node *t;
    int i;

    if(index < 0 || index > Length_circulaire(p))
        return;
    if (index == 0)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->Data = x;
        if (first == NULL)
        {
            first = t;
            first->Prev = first;
            first->Next = first;
        }
        else
        {
            while(p->Next != first) p = p->Next;
            p->Next = t;
            t->Prev = p;
            t->Next = first;
            first->Prev = t;
            first = t;
        }
    }
    else
    {
        for(i=0;i<index-1;i++) p = p->Next;
        t = (struct Node *)malloc(sizeof(struct Node));
        t->Data = x;
        t->Prev = p;
        t->Next = p->Next;
        p->Next->Prev = t;
        p->Next = t;
    }
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
        t->Prev = NULL;
        t->Next = first;
        first->Prev = t;
        first = t;
    }
    else
    {
        for(i=0; i<index-1; i++)
            p = p->Next;
        t = (struct Node *)malloc(sizeof(struct Node));
        t->Data = x;
        t->Prev = p;
        t->Next = p->Next;

        if(p->Next) p->Next->Prev = t;
        p->Next = t;
    }
}

void Reverse(struct Node *p)
{
    struct Node *temp;

    while(p != NULL)
    {
        temp = p->Next;
        p->Next = p->Prev;
        p->Prev = temp;
        p = p->Prev;
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

void Display_circulaire(struct Node *p)
{
    struct Node *q;
    q = first;
    do
    {
        printf("%d ", q->Data);
        q = q->Next;
    } while (q != first);
    
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
    Create_circulaire(A,5);
    Insert_circulaire(first,3,15);
    printf("voici le nombre supprimé : %d \n", Delete_circulaire(first, 3));
    Display_circulair(first);

    return 0;
}