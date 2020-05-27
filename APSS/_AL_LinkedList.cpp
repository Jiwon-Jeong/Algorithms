#include <stdio.h>
#include <stdlib.h>
struct Node {
	int data;
	Node *next;
};

Node *list; //�������� ����

void init() {
	if (list == NULL) return;
	else { // �ʱ�ȭ
		Node * cur;
		cur = list;
		while (cur != NULL) {
			list = cur->next;
			free(cur);
			cur = list;
		}
	}
}

void insert(int n) {
	Node * new_node = (Node *)malloc(sizeof(Node));
	new_node->data = n;
	new_node->next = NULL;

	if (list == NULL){
		list = new_node;
	}
	else { // �� �տ� �߰�
		new_node->next = list;
		list = new_node;
	}
}

void insert_asc(int n) {
	Node * new_node = (Node *)malloc(sizeof(Node));
	new_node->data = n;
	new_node->next = NULL;

	if (list == NULL) {
		list = new_node;
	}
	else { //������ ��ġ ã�Ƽ� �ֱ�
		Node * cur = list;
		Node * pre = NULL;

		//ù��° �ڸ��� �ٷ� �ְ� ��
		if (cur->data > new_node->data) {
			new_node->next = cur;
			list = new_node;
		}
		else { // �ƴϸ� ã�Ƽ� �־�� ��
			// while ���� ���� cur�� ���� �ڸ� �ٷ� ����
			while (cur != NULL && cur->data<new_node->data) {
				pre = cur;
				cur = cur->next;
			}
			// ���� �ڸ��� ���̸� ���� �߰�
			if (cur == NULL) {
				pre->next = new_node;
			}
			// �ƴϸ� cur�տ� �־��ְ� pre�� ����
			else {
				new_node->next = cur;
				pre->next = new_node;
			}
		}
	}
}


bool del(int n) {
	//�� ����Ʈ�� false
	if (list == NULL) return false;
	//ù��° ���Ҹ� �ٷ� �����ϰ� ��
	if (list->data == n) {
		Node * cur = list;
		list = list->next;
		free(cur);
		return true;
	}
	// ã�� �����ϱ�
	else {
		Node * pre = list;
		Node * cur = list->next;
		//cur�� ã�� ���̾����
		while (cur != NULL && cur->data != n) {
			pre = cur;
			cur = cur->next;
		}
		//��ã������ 
		if (cur == NULL) return false;
		//ã������
		else {
			pre->next = cur->next;
			free(cur);
			return true;
		}
	}
}


void print() {

	Node * cur = list;
	while (cur != NULL) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");

}


int main() {

	int arr[9] = { 2, 4, 6, 8, 1, 3, 5, 7, 9 };
	int arr_duplicated[18] = { 8, 1, 3, 2, 4, 6, 8, 1, 3, 5, 7, 9, 2, 4, 6, 5, 7, 9 };
	int arr_rmv[4] = { 2, 9, 8, 100 };


	// Add to list 1
	init();
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
		insert(arr[i]);
	}
	printf("After add(normal) : ");
	print();


	// Add to list 2
	init();
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
		insert_asc(arr[i]);
	}
	printf("After add(ascending) : ");
	print();


	return 0;

}