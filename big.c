#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};

struct node* Create(int x)
{
	struct node *temp;
      
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data=x;
	temp->next = NULL;
	return temp;
}
struct node* reverse(struct node* r)
{
        struct node* current = r;
        struct node *prev = NULL, *next = NULL;
        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
}
void Display(struct node*ptr)
{

	if(ptr==NULL)
	{
		printf("Empty Linked list");
	}
	else
	{
	 while(ptr!=NULL)
	 {
	   printf("%d",ptr->data);
	   ptr=ptr->next;	
	 }	
	}
}
struct node* subtract(struct node* head_1, struct node* head_2) {
    struct node* result = NULL;
    struct node* temp;
    int borrow = 0;

    while (head_1 != NULL || head_2 != NULL) {
        int dif = borrow;
        if (head_1 != NULL) {
            dif += head_1->data;
            head_1 = head_1->next;
        }
        if (head_2 != NULL) {
            dif -= head_2->data;
            head_2 = head_2->next;
        }

        if (dif < 0) {
            dif += 10;
            borrow = -1;
        } else {
            borrow = 0;
        }

        struct node* newNode =Create(dif);
        if (result == NULL) {
            result = newNode;
            temp = result;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }
    return result;
}
struct node*addTwoLists(struct node *head_1,struct node *head_2)
{  
    struct node *r,*temp, *prev = NULL;
    int carry = 0, sum;
    while (head_1 != NULL || head_2!= NULL) {
        
        sum = carry + (head_1 ? head_1->data : 0)+(head_2 ? head_2->data : 0);
        carry = (sum >= 10) ? 1 : 0;
        sum = sum % 10;
        temp = Create(sum);
        if (r == NULL)
            r= temp;
        else
            prev->next = temp;
        prev = temp;
        if (head_1)
            head_1 = head_1->next;
        if (head_2)
            head_2 = head_2->next;
    }
    if (carry > 0)
        temp->next = Create(carry);
    return r;    
}
int multiply(struct node*head_1,struct node*head_2)
{
	struct node*p=head_1;
	int x=0,y=0;
	while(p!=NULL){
		x=x*10+p->data;
		p=p->next;
	}
	p=head_2;
		while(p!=NULL){
		y=y*10+p->data;
		p=p->next;
	}
	return x*y;
}
