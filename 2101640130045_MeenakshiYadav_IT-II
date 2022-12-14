//Singly Linked List

#include<stdio.h>
#include<stdlib.h>

struct Node *start=NULL;
struct Node{
	int data;
	struct Node *add;
};

//1.IF
void insertatfront(int item,struct Node *head)
{	
    struct Node *Node3;
    Node3=(struct Node *)malloc(sizeof(struct Node));
	Node3->data=item;
	Node3-> add = NULL;
	Node3->add=head;
	head = Node3;
}

//2.IE
void insertatend(int item,struct Node *head)
{
    struct Node *s,*Node3;
    s = (struct Node *)malloc(sizeof(struct Node));
	Node3 = (struct Node *)malloc(sizeof(struct Node));
	Node3->data=item;
	Node3-> add = NULL;
	if(head==NULL)
		head = Node3;
	else{
	    s=head;
	while(s->add!=NULL){
		s=s->add;
		s->add = Node3;
	}
	}
}

//3.IALoc
void insertafterLoc(int dataAfter,struct Node *head,int item){
	struct Node *s,*Node3;
	s = (struct Node*)malloc(sizeof(struct Node));
	Node3 = (struct Node*)malloc(sizeof(struct Node));
	Node3->data=item;
	Node3-> add = NULL;
	s=head;
	while(s->data!=dataAfter)
		s=s->add;
	Node3->add= s->add;
	s->add = Node3;
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

//7.DltAtPos
void deleteAtPos(struct Node* head,int pos){
	struct Node* temp;
	temp=(struct Node*)malloc(sizeof(struct Node));
	struct Node* s;
	s=(struct Node*)malloc(sizeof(struct Node));
	
	pos--;
	s=head;
	while(pos>1){
		s=s->add;
		pos--;
	}
	temp=s->add;
	s->add=s->add->add;
	free(temp);
}

//8.Mid
struct Node *Mid(struct Node *head){
    struct Node *s,*f;
    s=(struct Node*)malloc(sizeof(struct Node));
    f=(struct Node*)malloc(sizeof(struct Node));
    s=head;
    f=head;
    while(f!=NULL && f->add!=NULL && f->add->add!=NULL){
       s=s->add;
       f=f->add->add;
    }
    return s;
}

//9.NthNodeEND
void NthNodeEnd(struct Node* head,int loc){
	struct Node* s=(struct Node*)malloc(sizeof(struct Node));
	struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
	s=head;
	temp=head;
	while(loc>0){
		s=s->add;
		loc--;
	}
	while(s->add!=NULL){
		temp=temp->add;
		s=s->add;
	}
}

//MAIN PROGRAM
int main()
{
	
	struct Node *Node1,*Node2,*head;
	Node1 = (struct Node*)malloc(sizeof(struct Node));
	Node2 = (struct Node *)malloc(sizeof(struct Node));
	Node1->data=10;
	Node1-> add = NULL;
	Node2->data=20;
	Node2-> add = NULL;
	Node1->add = Node2;
	head = Node1;
	
	int choice,item,dataAfter,pos,loc;
	scanf("%d%d",&pos,&loc);
	while(1){
	printf("\nEnter the choice:");
	scanf("%d",&choice);
	
	switch(choice){
		case 1: printf("Enter value:");
		        scanf("%d",&item);
		        insertatfront(item,start);    
		        break;
		case 2: printf("Enter value:");
		        scanf("%d",&item);
		        insertatend(item,start);    
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
	    case 7: printf("Enter pos:");
			    deleteAtPos(start,pos);
			    break;
	   	case 8: Mid(start);
			    break;
		case 9: NthNodeEnd(start,loc);
			    break;
		default : exit(1);
	}					
	}
}
