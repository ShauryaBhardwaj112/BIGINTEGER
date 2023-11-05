#include<stdio.h>
#include<stdlib.h>
#include"logic.h"
int main()
{
	struct node *head=NULL,*current=NULL,*head_2=NULL,*res=NULL;
	char arr[100],arr_1[100];
	long int ress;int ch;
	printf("1 Addtion \n");
	printf("2 Subtraction \n");
	printf("3 Multiply \n");
	scanf("%d",&ch);
	
	printf("enter the number \n");
	scanf("%s",arr);
	
	int i=0;
	while(arr[i]!='\0')
	{
	if(head==NULL)
	{
		head=Create(((int)(arr[i])-48));
		current=head;
	}
	else
	{
		current->next=Create(((int)(arr[i])-48));
		current = current->next;
	}
	i++;
    }
    printf("enter the 2 number \n");
	scanf("%s",arr_1);
	i=0;
	while(arr_1[i]!='\0')
	{
	if(head_2==NULL)
	{
		head_2=Create(((int)(arr_1[i])-48));
		current=head_2;
	}
	else
	{
		current->next=Create(((int)(arr_1[i])-48));
		current = current->next;
	}
	i++;
    }
    switch(ch)
    {
    	case 1:{   head=reverse(head);
		           head_2=reverse(head_2);
    	           res=addTwoLists(head,head_2);
                   res=reverse(res);
                   printf("sum"); 
                   Display(res);	break; }
                   
    	case 2: { head=reverse(head);
		          head_2=reverse(head_2);        
		          res=subtract(head,head_2);
                  res=reverse(res);
                  printf("sum  "); 
                  Display(res); 	break; }
                  
        case 3: {    ress=multiply(head,head_2);
                     printf("sum %ld",ress);
					 break; }
 
        default : {  printf("wrong input");
			break;
		}		
	}
   
}
