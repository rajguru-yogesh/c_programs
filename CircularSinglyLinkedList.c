#include<stdio.h>
#include<stdlib.h>
typedef struct csll{
	int data;
	struct csll *next;
}csll;
struct csll * root = NULL ;

void insert(){
	int data;
	printf("Please enter data.\n");
	scanf("%d",&data);
	csll *newnode = (csll *)malloc(sizeof(csll));
	newnode->data = data;
	
	if( root == NULL){
		root = newnode;
	}
	else{
		csll *temp;
		temp = root;
		while(temp->next != root){
			temp = temp->next;
		}
		temp->next = newnode;
	}
	newnode->next = root;
	printf("Node inserted successfully\n");
}
void display(){
	csll *temp;
	if(root == NULL){
		printf("List is already empty.\n");
	}
	else{
		temp = root;
		while(temp->next != root){
		printf("|%d|",temp->data);
		temp = temp->next;
		}
		printf("|%d|\n",temp->data);
	}
}

void search(){
	int key,c1 = 0,c2 = 0;
	csll *temp;
	temp = root;
	
	printf("Please enter which node you want to search..\n");
	scanf("%d",&key);
	while(temp->next != root){
		c1++;
		if(temp->data == key ){
			printf("Node with data : %d found at position : %d\n",key,c1);
			temp = temp->next;
			break;
		}
		temp = temp->next;
		c2++;
	}
	if(temp->data == key ){
		printf("Node with data : %d found at position : %d\n",key,++c1);	
	} 
	else if (c1 == c2){
		printf("Node with data : %d not found...\n",key);	
	}
}

void delete(){
	int key,c1 = 0,c2 = 0;
	csll *temp1,*temp2;
	temp1 = root ;
	printf("Please enter which node you want to delete..\n");
	scanf("%d",&key);

		while(temp1->next != root){
			
			c1++;
			if(temp1->data == key ){
				temp2->next = temp1->next;
				printf("Node delete with data : %d And  position : %d\n",key,c1);
				temp1 = temp1->next;
				break;
			}
			temp2 = temp1;
			temp1 = temp1->next;
			c2++;
		}
	if(temp1->data == key ){
		temp2->next = temp1->next;
		printf("Node delete with data : %d And  position : %d\n",key,++c1);	
	}else if (c1 == c2){
		printf("Node with data : %d not found...\n",key);	
	}
}

int reverse(){
	int arr[100],cnt = 0;
	int i = 0 ;
	csll *temp;
	temp = root;
	while(temp->next != root){
		arr[cnt] = temp->data;
		cnt++;
		temp = temp->next;
	}
	arr[cnt] = temp->data;
	for(i = cnt; i >= 0 ; i--){
		printf("|%d|",arr[i]);
	}
	return 0 ;
}

int main(){
	int choice,helper;;
	printf("*********Circular SinglyLink List Operations********\n");
	printf("(1)Insert.\n(2)Insert multiple.\n(3)Display.\n(4)Search.\n(5)Delete.\n(6)Print in reverse order.\n(7)Exit.\n");
	while(1){
		printf("Enter you choice.\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				insert();
				break;

			case 2:
				
				printf("Enter how many nodes you want to add.\n");
				scanf("%d",&helper);
				for(int  i = 0 ;i < helper ; i++ ){
					insert();	
				}
				break;	
			
			case 3:
				display();				
				break;
			
			case 4:
				search();				
				break;
			
			case 5:
				delete();				
				break;

			case 6:
				reverse();				
				break;

			case 7:
				exit(0);				
				break;				
		}

	}
	return 0 ;
}