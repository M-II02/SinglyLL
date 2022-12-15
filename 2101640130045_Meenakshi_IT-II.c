// Singly Linked List

#include <stdio.h>
#include <stdlib.h>

struct Node *start = NULL;

struct Node {
	int data;
	struct Node *add;
};

// 1.CreateLL
void createLL(struct Node **head) {
	struct Node *Node1 = (struct Node *)malloc(sizeof(struct Node));
	Node1->data = 10;
	Node1->add = NULL;
	struct Node *Node2 = (struct Node *)malloc(sizeof(struct Node));
	Node2->data = 20;
	Node2->add = NULL;
	Node1->add = Node2;
	*head = Node1;
}

// 2.IF
void insertatfront(int item, struct Node **head) {
	struct Node *Node3 = (struct Node *)malloc(sizeof(struct Node));
	Node3->data = item;
	Node3->add = NULL;
	Node3->add = *head;
	*head = Node3;
}

// 3.IE
void insertatend(int item, struct Node **head) {
	struct Node *s;
	struct Node *Node3 = (struct Node *)malloc(sizeof(struct Node));
	Node3->data = item;
	Node3->add = NULL;
	if (*head == NULL)
		*head = Node3;
	s = *head;
	while (s->add != NULL)
		s = s->add;
	s->add = Node3;
}

// 4.IALoc
void insertafterLoc(int dataAfter, struct Node **head, int item) {
	struct Node *s;
	struct Node *Node3 = (struct Node *)malloc(sizeof(struct Node));
	Node3->data = item;
	Node3->add = NULL;
	s = *head;
	while (s->data != dataAfter)
		s = s->add;
	Node3->add = s->add;
	s->add = Node3;
}

// 5.PrintLL
void printLL(struct Node *head) {
	struct Node *s = head;
	if (s == NULL) {
		printf("\nLL is empty");
		return;
	}
	while (s != NULL) {
		printf("\n%d ", s->data);
		s = s->add;
	}
}

// 6.DltAtH
void deleteAtHead(struct Node *head) {
	struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
	temp = head;
	head = temp->add;
	printf("\n Deleted head value=%d", temp->data);
	free(temp);
}

// 7.DltAtE
void deleteAtEnd(struct Node *head) {
	struct Node *s = (struct Node *)malloc(sizeof(struct Node));
	s = head;
	while (s->add->add != NULL) {
		s = s->add;
		s->add = NULL;
	}
	printf("\n Deleted end value=%d", s->data);
	free(s->add);
}

//8.DltAtPos
void deleteAtPos(struct Node* head,int pos){
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
}

//9.Mid
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

//10.NthNodeEND
void NthNodeEnd(struct Node* head,int loc){
	struct Node* s;
	struct Node* t;
	s=head;
	t=head;
	while(loc>0){
		s=s->add;
		loc--;
	}
	while(s->add!=NULL){
		t=t->add;
		s=s->add;
    }
}

//MAIN PROGRAM
int main() {
	int choice, item, dataAfter, pos,loc;
	while (1) {
		printf("\nEnter the choice:");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			createLL(&start);
			break;
		case 2:
			printf("Enter value:");
			scanf("%d", &item);
			insertatfront(item, &start);
			break;
		case 3:
			printf("Enter value:");
			scanf("%d", &item);
			insertatend(item, &start);
			break;
		case 4:
			printf("Enter value:");
			scanf("%d", &item);
			printf("Enter dataAfter:");
			scanf("%d", &dataAfter);
			insertafterLoc(dataAfter, &start, item);
		case 5:
			printLL(start);
			break;
		case 6:
			deleteAtHead(start);
			break;
		case 7:
			deleteAtEnd(start);
			break;
	  case 8: printf("Enter pos:");
            scanf("%d", &pos);
			    deleteAtPos(start,pos);
			    break;
	  case 9: Mid(start);
			    break;
		case 10: printf("Enter Loc:");
          scanf("%d", &loc);
          NthNodeEnd(start,loc);
			    break;
		default:
			exit(1);
		}
	}
}
