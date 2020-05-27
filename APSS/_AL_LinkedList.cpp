#include <stdio.h>
#include <stdlib.h>
struct Node {
	int data;
	Node *next;
};

Node *list; //전역으로 선언

void init() {
	if (list == NULL) return;
	else { // 초기화
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
	else { // 맨 앞에 추가
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
	else { //적절한 위치 찾아서 넣기
		Node * cur = list;
		Node * pre = NULL;

		//첫번째 자리면 바로 넣고 끝
		if (cur->data > new_node->data) {
			new_node->next = cur;
			list = new_node;
		}
		else { // 아니면 찾아서 넣어야 함
			// while 돌고 나면 cur가 넣을 자리 바로 앞임
			while (cur != NULL && cur->data<new_node->data) {
				pre = cur;
				cur = cur->next;
			}
			// 넣을 자리가 끝이면 끝에 추가
			if (cur == NULL) {
				pre->next = new_node;
			}
			// 아니면 cur앞에 넣어주고 pre랑 연결
			else {
				new_node->next = cur;
				pre->next = new_node;
			}
		}
	}
}


bool del(int n) {
	//빈 리스트면 false
	if (list == NULL) return false;
	//첫번째 원소면 바로 삭제하고 끝
	if (list->data == n) {
		Node * cur = list;
		list = list->next;
		free(cur);
		return true;
	}
	// 찾고 삭제하기
	else {
		Node * pre = list;
		Node * cur = list->next;
		//cur이 찾은 값이어야함
		while (cur != NULL && cur->data != n) {
			pre = cur;
			cur = cur->next;
		}
		//못찾았으면 
		if (cur == NULL) return false;
		//찾았으면
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