// Reverse Single Linked List
#include <iostream>
using namespace std;

typedef struct Node {
	int data;
	Node * next;
}Node;


void makeList(Node *list, int n);
Node* reverseList(Node *list);
void printList(Node *list);

int main() {
	Node * list = (Node *)malloc(sizeof(Node));
	list->data = 0; list->next = NULL;
	makeList(list, 10);
	printList(list);
	list = reverseList(list);
	printList(list);

	Node * tmp = list;
	while (list != NULL) {
		tmp = list;
		list = list->next;
		free(tmp);
	}
	return 0;
}

void makeList(Node *list, int n) {
	Node *tmp = list;
	list->data = 0;
	for (int i = 1; i < n; i++) {
		Node *newNode = (Node *)malloc(sizeof(Node));
		newNode->data = i; newNode->next = NULL;
		tmp->next = newNode;
		tmp = tmp->next;
	}
}

Node * reverseList(Node *list) {
	Node *tmp = list;
	Node *nextNode = list->next;
	tmp->next = NULL;
	while (nextNode != NULL) {
		list = nextNode->next;
		nextNode->next = tmp;
		tmp = nextNode;
		nextNode = list;
	}
	return tmp;
}
void printList(Node *list) {
	Node * nextNode = list;
	while (nextNode != NULL) {
		cout << nextNode->data <<"->";
		nextNode = nextNode->next;
	}
	cout<<"NULL"<< endl;
}
