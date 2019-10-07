#include<stdio.h>
#include<stdlib.h>
typedef struct dll{
	int data;
	struct dll *next,*prev;
}dll;
dll *root = NULL;

void insert(){
	int newdata;
	dll *temp;
	printf("Please enter data to be entered.\n");
	scanf("%d",&newdata);
	dll *newnode = (dll *)malloc(sizeof(dll));

	newnode->data = newdata;
	newnode->next = newnode->prev = NULL;
	
	if(root == NULL){
		root = newnode;
	}
	else{
		temp = root;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = newnode;
		newnode->prev = temp;
	}
}
void display(){
	dll *temp;
	temp = root ;
	if (root == NULL){
		printf("List is already empty.\n");
	}
	else{
		while(temp->next != NULL){
			printf("|%d|%d|%d|<=>",temp->prev,temp->data,temp->next);
			temp = temp->next;
		}
	printf("|%d|%d|NULL|\n",temp->prev,temp->data);		
	}
}
void search(){
	int key,c1 = 0,c2 = 0;
	dll *temp; 
	printf("Please Enter which node you want to search.\n");
	scanf("%d",&key);
	temp = root;
	if (root == NULL){
		printf("List is already empty.\n");
	}
	else{
		temp = root;
		while(temp->next != NULL){
			c1++;
			if(temp->data == key){
				printf("Element found at position %d. \n",c1);
				temp = temp->next;
				break;
			}
			c2++;
			temp = temp->next;
			} 
			
			if(temp->data == key){
				printf("Element found at postion %d\n",++c1);
			}
			if(c1 == c2){
				printf("Element not found.\n");
		}				
	}
}
void reverse(){
	dll *temp;
	temp = root ;
	if (root == NULL){
		printf("List is already empty.\n");
	}
	else{
		while(temp->next != NULL){
			temp = temp->next;
		}
		while(temp->prev != NULL){
			printf("|%d|",temp->data);
			temp = temp->prev;
		}
		printf("|%d|",temp->data);

	}	 
}
int main()
{
	int choice,helper;
	printf("***********Doubly Linked List Operations***********\n");
	printf("1)Insert multiple\n2)Insert\n3)Delete\n4)Display\n5)Search\n6)print list in reverse\n7)Exit\n");

	while (1){
		
		printf("Enter you choice\n");
		scanf("%d",&choice);

		switch(choice){
			case 1:
				printf("Enter how many node you want to create\n");
				scanf("%d",&helper);
				 for(int i = 0 ; i < helper; i++){
				 	insert();
				}
				break;
			case 2:
				insert();
				break;
			case 3:
				printf("Enter how many node you want to create\n");
				scanf("%d",&helper);
				 for(int i = 0 ; i < helper; i++){
				 	insert();
				}
				break;
			case 4:
				display();
				break;
			case 5:
				search();
				break;
			case 6:
				reverse();
				break;
			case 7:
				exit(0);

			default:
				printf("Please choose proper Operations\n");								
		}
	}	
	return 0;
}