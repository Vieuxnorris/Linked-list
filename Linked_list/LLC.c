#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int Data;
	struct Node *Next;
}*first=NULL, *last=NULL;

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

int main()
{
	int A[] = {3,5,7,8,9,30,30,30};
	create(A,8);

	//Display(first);
	//Insert_Node(first,4,100);
	//Insert_Sorted_List(first, 100);
	printf("Sorted ?  %d\n",Link_Sorted(first));
	Reversing_Node_V2(first);
	Display(first);
	return 0;
}
