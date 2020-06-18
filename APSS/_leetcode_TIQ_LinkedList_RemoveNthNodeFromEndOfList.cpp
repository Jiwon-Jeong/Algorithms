/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* dummyHead = new ListNode(0);
		dummyHead->next = head;
		ListNode* cur = head;

		while (n--) {
			cur = cur->next;
		}

		ListNode* prev = dummyHead;
		while (cur) {
			cur = cur->next;
			prev = prev->next;
		}

		prev->next = prev->next->next;

		return dummyHead->next;
	}
};