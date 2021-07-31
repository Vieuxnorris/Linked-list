#include <stdio.h>
#include <stdlib.h>

struct Node
{
        int Data;
        struct Node *Next;
}*first=NULL, *second=NULL, *last=NULL, *last_second=NULL, *third=NULL;

void create_circular(int A[], int n)
{
        int i;
        struct Node *t;
        first = (struct Node *)malloc(sizeof(struct Node));
        first->Data = A[0];
        first->Next = first;
        last = first;

        for(i=1;i<n;i++)
        {
                t=(struct Node *)malloc(sizeof(struct Node));
                t->Data = A[i];
                t->Next = last->Next;
                last->Next = t;
                last = t;
        }
}


void create(int A[], int n)
{
        int i;
        struct Node *t;
        first=(struct Node *)malloc(sizeof(struct Node));
        last=(struct Node *)malloc(sizeof(struct Node));
        first->Data = A[0];
        first->Next = NULL;
        last = first;

        for(i=1;i<n;i++)
        {
                t = (struct Node *)malloc(sizeof(struct Node));
                t->Data = A[i];
                t->Next = NULL;
                last->Next = t;
                last = t;
        }
}

void create_2(int B[], int n)
{
        int i;
        struct Node *t;
        second = (struct Node *)malloc(sizeof(struct Node));
        last_second = (struct Node *)malloc(sizeof(struct Node));
        second->Data = B[0];
        second->Next = NULL;
        last_second = second;

        for(i=1;i<n;i++)
        {
                t = (struct Node *)malloc(sizeof(struct Node));
                t->Data = B[i];
                t->Next = NULL;
                last_second->Next = t;
                last_second = t;
        }
}

void Display_circulaire(struct Node *h)
{
        do
        {
                printf("%d ", h->Data);
                h = h->Next;
        } while (h != first);
        printf("\n");        
}

void RDisplay_circulaire(struct Node *h)
{
        static int flag = 0;
        if (h != first || flag == 0)
        {
                flag = 1;
                printf("%d ", h->Data);
                RDisplay_circulaire(h->Next);
        }
        flag = 0;
}

int length_circulaire(struct Node *p)
{
        int len=0;
        do
        {
                len++;
                p = p->Next;
        } while (p!=first);
        return len;
}

void Display(struct Node *p)
{
        while(p != NULL)
        {
                printf("Current Node --> %d\t| Data --> %d\t| Next Node --> %d\n", p ,p->Data, p->Next);
                p = p->Next;
        }
}

void RDisplay(struct Node *p)
{
        if(p != NULL)
        {
                RDisplay(p->Next);
                printf("%d ", p->Data);
        }
}

int Count_Node(struct Node *p)
{
        int count=0;
        while(p != NULL)
        {
                count++;
                p = p->Next;
        }
        return count;
}

int Sum_Node(struct Node *p)
{
        int sum=0;
        while(p != NULL)
        {
                sum += p->Data;
                p = p->Next;
        }
        return sum;
}

int Max_Node(struct Node *p)
{
        int max = -32768;
        while(p != NULL)
        {
                if(p->Data > max)
                        max = p->Data;
                p = p->Next;
        }
        return max;
}

int Min_Node(struct Node *p)
{
        int min = 32768;
        while(p != NULL)
        {
                if(p->Data < min)
                        min= p->Data;
                p = p->Next;
        }
        return min;
}

int Search_Node(struct Node *p, int key)
{
        while(p != NULL)
        {
                if(key == p->Data)
                        return 1;
                p = p->Next;
        }
        return 0;
}

int Improve_Search_Node(struct Node *p, int key)
{
        struct Node *q;
        q = NULL;
        while (p != NULL)
        {
                if(key == p->Data)
                {
                        q->Next = p->Next;
                        p->Next = first;
                        first = p;
                        return 1;
                }
                q = p;
                p = p->Next;
        }
        return 0;
}

void Insert_Node_Circulaire(struct Node *p, int index, int x)
{
        struct Node *t;
        int i;
        if (index < 0 || index > length_circulaire(p))
                return;
        
        if(index == 0)
        {
                t = (struct Node *)malloc(sizeof(struct Node));
                t->Data = x;
                if(first == NULL)
                {
                        first = t;
                        first->Next = first;
                }
                else
                {
                        while (p->Next != first) p = p->Next;
                        p->Next = t;
                        t->Next = first;
                        first = t;
                }
        }
        else
        {
                for (i=0;i<index-1;i++) p = p->Next;
                t = (struct Node *)malloc(sizeof(struct Node));
                t->Data = x;
                t->Next = p->Next;
                p->Next = t;
        }
}

int Delete_circulaire(struct Node *p, int index)
{
        struct Node *q;
        int i,x;

        if (index < 0 || index > length_circulaire(first))
                return -1;
        if (index == 1)
        {
                while(p->Next != first) p=p->Next;
                x = first->Data;
                if (first == p)
                {
                        free(first);
                        first = NULL;
                }
                else
                {
                        p->Next = first->Next;
                        free(first);
                        first = p->Next;
                }
        }
        else
        {
                for (i=0;i<index-2;i++)
                        p = p->Next;
                q = p->Next;
                p->Next = q->Next;
                x = q->Data;
                free(q);
        }
        return x;
}

void Insert_Node(struct Node *p, int index,int value)
{
        struct Node *t;
        int i;

        if(index < 0 || index > Count_Node(p))
                return;
        t = (struct Node *)malloc(sizeof(struct Node));
        t->Data = value;

        if(index == 0)
        {
                t->Next = first;
                first = t;
        }
        else
        {
                for(i=0; i<index-1;i++)
                        p = p->Next;
                t->Next = p->Next;
                p->Next = t;
        }
}

void Insert_Last(int value)
{
        struct Node *t;
        t = (struct Node *)malloc(sizeof(struct Node));
        t->Data = value;
        t->Next = NULL;
        if(first == NULL)
                first = last = t;
        else
        {
                last->Next = t;
                last = t;
        }
}

void Insert_Sorted_List(struct Node *p, int value)
{
        struct Node *t,*q=NULL;
        t = (struct Node *)malloc(sizeof(struct Node));
        t->Data = value;
        t->Next = NULL;

        if(first==NULL)
                first=t;
        else
        {
                while(p && p->Data < value)
                {
                        q = p;
                        p = p->Next;
                }
                if(p==first)
                {
                        t->Next = first;
                        first = t;
                }
                else
                {
                        t->Next = q->Next;
                        q->Next = t;
                }
        }
}

void Delete_Node(int index)
{
        struct Node *q,*p;
        int x=0, i=0;
        p = first;
        q = NULL;
        if(index == 0)
                first = p->Next;
        else
        {
                for(i=0; i < index-1 && p; i++)
                {
                        q = p;
                        p = p->Next;
                }
                q->Next = p->Next;
        }
        x = p->Data;
        printf("Index Node delete --> %d | value Node --> %d\n", i, x);
        if (p == last)
                last = q;
        free(p);
}

int Link_Sorted(struct Node *p)
{
        int x=-65536;
        while(p != NULL)
        {
                if(p->Data < x)
                        return 0;
                x = p->Data;
                p = p->Next;
        }
        return 1;
}

void Remove_dup(struct Node *p)
{
        struct Node *q = p;
        p = p->Next;
        while(p != NULL)
        {
                if(p->Data != q->Data)
                {
                        q = p;
                        p = p->Next;
                }
                else
                {
                        q->Next = p->Next;
                        free(p);
                        p = q->Next;
                }
        }
        last = q;
}

void Reversing_Node_V1(struct Node *p)
{
        int *A,i=0;
        struct Node *q=p;

        A = (int *)malloc(sizeof(int)*Count_Node(p));

        while(q != NULL)
        {
                A[i] = q->Data;
                q = q->Next;
                i++;
        }
        q = p;
        i--;
        while(q != NULL)
        {
                q->Data = A[i];
                q = q->Next;
                i--;
        }
}

void Reversing_Node_V2(struct Node *p)
{
        struct Node *q=NULL, *r=NULL;

        while(p != NULL)
        {
                r = q;
                q = p;
                p = p->Next;
                q->Next = r;
        }
        first = q;
}

void Reversing_Node_V3(struct Node *q, struct Node *p)
{
        if(p)
        {
                Reversing_Node_V3(p, p->Next);
                p->Next = q;
        }
        else
                first = q;
}

void Merge(struct Node *p)
{
        while(p->Next != NULL)
                p = p->Next;
        p->Next = second;
        while(p->Next != NULL)
        {
                p = p->Next;
                last = p;
        }
        second = NULL;
        last_second = NULL;
}

void Merge_sorted_Link(struct Node *p, struct Node *q)
{
        struct Node *last_merge;

        if(p->Data < q->Data)
        {
                third = last_merge = p;
                p = p->Next;
                third->Next = NULL;
        }
        else if(p->Data > q->Data)
        {
                third = last_merge = q;
                q = q->Next;
                third->Next = NULL;
        }
        while(p != NULL && q != NULL)
        {
                if(p->Data < q->Data)
                {
                        last_merge->Next = p;
                        last_merge = p;
                        p = p->Next;
                        last_merge->Next = NULL;
                }
                else
                {
                        last_merge->Next = q;
                        last_merge = q;
                        q = q->Next;
                        last_merge->Next = NULL;
                }
        }
        if(p) last_merge->Next = p;
        if(q) last_merge->Next = q;
}

int IsLoop(struct Node *p)
{
        struct Node *t,*q;
        t = q = p;
        do
        {
                p = p->Next;
                q = q->Next;
                q = q != NULL ? q->Next : NULL;
        }while(p && q);
        if(p == q)
                return 1;
        else
                return 0;
}

int main()
{
        int A[] = {2,3,4,5,6};
        int B[] = {1,15,2,3,25,40};
        create_circular(A, 5);
        RDisplay_circulaire(first);
        //create(A,5);
        //create_2(B,5);

        //Insert_Node(first,4,100);
        //Insert_Sorted_List(first, 100);
        //printf("Sorted ?  %d\n",Link_Sorted(first));
        //Merge_sorted_Link(first, second);
        //printf("Loop ? %d\n", IsLoop(first));
        //Display(first);
        //Display(last);
        return 0;
}
