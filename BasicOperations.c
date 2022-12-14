//Singly Linked List

#include<stdio.h>
#include<stdlib.h>

struct Node *start=NULL;
struct Node{
	int data;
	struct Node *add;
};

//1.IF
void insertatfront(int item,struct Node **head)
{
	struct Node *Node1,*Node2,*Node3;
	Node1 = (struct Node*)malloc(sizeof(struct Node));
	Node2 = (struct Node *)malloc(sizeof(struct Node));
	Node1->data=10;
	Node1-> add = NULL;
	Node2->data=20;
	Node2-> add = NULL;
	Node1->add = Node2;
	*head = Node1;
	
    Node3=(struct Node *)malloc(sizeof(struct Node));
	Node3->data=item;
	Node3-> add = NULL;
	Node3->add=*head;
	*head = Node3;
}

//2.IE
void insertatend(int item,struct Node **head)
{
    struct Node *s;
    s = (struct Node *)malloc(sizeof(struct Node));
	struct Node *Node1,*Node2,*Node3;
	Node1 = (struct Node*)malloc(sizeof(struct Node));
	Node2 = (struct Node *)malloc(sizeof(struct Node));
	Node1->data=10;
	Node1-> add = NULL;
	Node2->data=20;
	Node2-> add = NULL;
	Node1->add = Node2;
	*head = Node1;
	
	Node3 = (struct Node *)malloc(sizeof(struct Node));
	Node3->data=item;
	Node3-> add = NULL;
	if(*head==NULL)
		*head = Node3;
	else{
	    s=*head;
	while(s->add!=NULL){
		s=s->add;
		s->add = Node3;
	}
	}
}

//3.IALoc
void insertafterLoc(int dataAfter,struct Node *head,int item){
	struct Node *s;
	s = (struct Node*)malloc(sizeof(struct Node));
	struct Node *Node1,*Node2,*Node3;
	Node1 = (struct Node*)malloc(sizeof(struct Node));
	Node2 = (struct Node *)malloc(sizeof(struct Node));
	Node1->data=10;
	Node1-> add = NULL;
	Node2->data=20;
	Node2-> add = NULL;
	Node1->add = Node2;
	head = Node1;
	
	Node3 = (struct Node*)malloc(sizeof(struct Node));
	Node3->data=item;
	Node3-> add = NULL;
	s=head;
	while(s->data!=dataAfter)
		s=s->add;
	Node1->add= s->add;
	s->add = Node1;
}

//4.PrintLL
void printLL(struct Node *head)
{
	if(head==NULL){
		printf("\n LL is empty");
		return;
	}
	while(head!=NULL){
		printf("%d ",head->data);
		head=head->add;
	}
}

//5.DltAtH
void deleteAtHead(struct Node* head){
	struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
	temp=head;
	head=temp->add;
	printf("\n Deleted value=%d",temp->data);
	free(temp);
}

//6.DltAtE
void deleteAtEnd(struct Node* head){
	struct Node* s=(struct Node*)malloc(sizeof(struct Node));
	s=head;
	while(s->add->add!=NULL){
	s=s->add;
	}
	free(s->add);
	s->add=NULL;
}


int main()
{
	int choice,item,dataAfter,pos;
	scanf("%d",&pos);
	while(1){
	printf("\nEnter the choice:");
	scanf("%d",&choice);
	
	switch(choice){
		case 1: printf("Enter value:");
		        scanf("%d",&item);
		        insertatfront(item,&start);    
		        break;
		case 2: printf("Enter value:");
		        scanf("%d",&item);
		        insertatend(item,&start);    
		        break;
		case 3: printf("Enter value:");
		        scanf("%d",&item);
		        printf("Enter dataAfter:");
		        scanf("%d",&dataAfter);
		        insertafterLoc(dataAfter,start,item);
		case 4: printLL(start);
		        break;		
		case 5: deleteAtHead(start);
			    break;
	    case 6: deleteAtEnd(start);
			    break;

		default : exit(1);
	}					
	}
}
