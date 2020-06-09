//Linked List
#include <iostream>
using namespace std;

int n, k;

typedef struct Node {
	int data;
	Node * next;
} Node;


void deleteNode(Node *node) {
	Node *tmp = node->next;
	node->data = tmp->data;
	node->next = tmp->next;
	delete tmp;
	return;
}

void sol(Node * node) {
	printf("<");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k - 1; j++)
			node = node->next;
		if (i == n - 1)
			printf("%d", node->data);
		else
			printf("%d, ", node->data);
		deleteNode(node);
	}
	printf(">");
	return;
}

int main() {
	scanf("%d %d", &n, &k);
	Node* list = (Node*)malloc(sizeof(Node));
	list->data = n; list->next = NULL;
	//삽입 1 ... n 링크드리스트 생성
	for (int i = n-1; i >= 1; i--) {
		Node *newNode = (Node *)malloc(sizeof(Node));
		newNode->data = i;
		newNode->next = list;
		list = newNode;
	}
	//원형으로 만들어
	Node *tmp = list;
	if (tmp != NULL) {
		while (tmp->next != NULL)
			tmp = tmp->next;
	}

	if (tmp != NULL)
		tmp->next = list;
	
	sol(list);

	return 0;
}