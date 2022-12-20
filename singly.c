// Singly Linked List

#include <stdio.h>
#include <stdlib.h>

struct Node *head= NULL;

struct Node {
	int data;
	struct Node *add;
};

// 1.CreateLL
struct Node* createLL(struct Node *head) {
	struct Node *Node1 = (struct Node *)malloc(sizeof(struct Node));
	Node1->data = 10;
	Node1->add = NULL;
	struct Node *Node2 = (struct Node *)malloc(sizeof(struct Node));
	Node2->data = 20;
	Node2->add = NULL;
	Node1->add = Node2;
	head = Node1;
  return head;
}

// 2.IF
struct Node* insertatfront(int item, struct Node *head) {
	struct Node *Node3 = (struct Node *)malloc(sizeof(struct Node));
	Node3->data = item;
	Node3->add = NULL;
	Node3->add = head;
	head = Node3;
  return head;
}

// 3.IE
struct Node* insertatend(int item, struct Node *head) {
	struct Node *s;
	struct Node *Node3 = (struct Node *)malloc(sizeof(struct Node));
	Node3->data = item;
	Node3->add = NULL;
	if (head == NULL)
		head = Node3;
	s = head;
	while (s->add != NULL)
		s = s->add;
	s->add = Node3;
  return head;
}

// 4.IALoc
struct Node* insertafterLoc(int dataAfter, struct Node *head, int item) {
	struct Node *s;
	struct Node *Node3 = (struct Node *)malloc(sizeof(struct Node));
	Node3->data = item;
	Node3->add = NULL;
	s = head;
	while (s->data != dataAfter)
		s = s->add;
	Node3->add = s->add;
	s->add = Node3;
  return head;
}

// 5.PrintLL
struct Node* printLL(struct Node *head) {
	struct Node *s = head;
	if (s == NULL) {
		printf("\nLL is empty");
		return 0;
	}
	while (s != NULL) {
		printf("\n%d ", s->data);
		s = s->add;
	}
  return head;
}

// 6.DltAtH
struct Node* deleteAtHead(struct Node *head) {
	struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
	temp = head;
	head = temp->add;
	printf("\n Deleted head value=%d", temp->data);
	free(temp);
  return head;
}

// 7.DltAtE
void deleteAtEnd(struct Node *head) {
	struct Node *s = (struct Node *)malloc(sizeof(struct Node));
	s = head;
	while (s->add->add != NULL) {
		s = s->add;
    	free(s->add);
		s->add = NULL;
	}
	printf("\n Deleted end value=%d", s->data);
}

//8.DltAtPos
struct Node* deleteAtPos(struct Node* head,int pos){
	struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
	struct Node* s;
	pos--;
	s=head;
	while(pos>1){
		s=s->add;
		pos--;
      
	}
	temp=s->add;
	s->add=s->add->add;
	free(temp);
  return head;
}

//9.Mid
void Mid(struct Node *head){
    struct Node* s,*f;
    s=head;
    f=head;
    while(f!=NULL && f->add!=NULL && f->add->add!=NULL){
       s=s->add;
       f=f->add->add;
    }
    printf("\nMiddle node value is=%d",s->data);
}

//10.NthNodeEND
void NthNodeEnd(struct Node* head,int loc){
	struct Node* s,*t;
  if( head==NULL)
    return;
	s=head;
	t=head;
	while(loc>0 && s!=NULL){
		s=s->add;
		loc--;
	}
	while(s){
		t=t->add;
		s=s->add;
    }
  printf("\n nth Node value is:%d",t->data);
}

//MAIN PROGRAM
int main() {
	int choice, item, dataAfter, pos,loc;
	while (1) {
		printf("\nEnter the choice:");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			head=createLL(head);
			break;
		case 2:
			printf("Enter value:");
			scanf("%d", &item);
			head=insertatfront(item,head);
			break;
		case 3:
			printf("Enter value:");
			scanf("%d", &item);
			head=insertatend(item,head);
			break;
		case 4:
			printf("Enter value:");
			scanf("%d", &item);
			printf("Enter dataAfter:");
			scanf("%d", &dataAfter);
			head=insertafterLoc(dataAfter,head, item);
		case 5:
			printLL(head);
			break;
		case 6:
			head=deleteAtHead(head);
			break;
		case 7:
			deleteAtEnd(head);
			break;
	  case 8: printf("Enter pos:");
            scanf("%d", &pos);
			    head=deleteAtPos(head,pos);
			    break;
	  case 9: Mid(head);
			    break;
		case 10: printf("Enter Loc:");
          scanf("%d", &loc);
          NthNodeEnd(head,loc);
			    break;
		default:
			exit(1);
		}
	}
}
