#include<stdio.h>
#include<stdlib.h>


typedef struct Node {
	int data;
	struct Node *next;
}node;
 node* root = NULL;

 void insert(){
	int NewData;
	node* temp;
	printf("Please New Enter Data to be entered:\n");
	scanf("%d",&NewData);
	node* NewNode = (node*)malloc(sizeof(node));
	NewNode->data = NewData;
	NewNode->next = NULL ;
	if(root == NULL){
		root = NewNode;
	}
	else{
		temp = root;
		while(root->next != NULL){
			root = 	root->next;
		}
		root->next = NewNode;
		root = temp;
	}
	printf("Node %d Inserted Successfully.\n",NewNode->data);
	
}

void display(){
	node* temp;
	temp = root;

	while(temp->next != NULL){
			printf("|%d|%p|->",temp->data,temp->next);
			temp = 	temp->next;	
		}
		printf("|%d|NULL|\n",temp->data);
		
}

void delete (){
	node* temp1;
	node* temp2;
	if (root == NULL)
		printf("List already empty.\n");
	else if(root->next == NULL){
		root = NULL;
		printf("Node deleted. List Now empty.\n");
	}
	else{
		temp1 = root;
		temp2 = root->next;
		while (temp2->next != NULL){
			temp2 = temp2->next;
			temp1 = temp1->next;
		}
		printf("%d element deleted Successfully.\n",temp2->data);	
		temp1->next = NULL;

	}

}
void search(){
	int key,c1 = 0,c2 = 0;
	printf("Enter Number to be searched.\n");
	scanf("%d",&key);
	node* temp;
	temp = root;
	while(temp->next != NULL){
		c1++;
		if(temp->data == key){
			printf("Element found at position %d. \n",c1);
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

int main(){
	int choice,CreateBulk;
	
	printf("########singly linked list Operations#######\n");
	printf("1]Create\n2]Insert\n3]Delete\n4]Display\n5]Search\n6]Exit\n");
	while(1){
		printf("Please Enter your choice:\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Enter how many nodes you want to enter:\n");
				scanf("%d",&CreateBulk);

				for (int i = 0 ;i < CreateBulk ;i++){
					insert();	
				}
				break;

			case 2:
				insert();
				break;
			
			case 3:
				delete();
				break;
			
			case 4:
				display();
				break;

			case 5:
				search();
				break;
			case 6:
				printf("Exit:\n");
				exit(0);
				break;	
		}
	}
	return 0 ;
}