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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        ListNode* second = slow -> next;
        ListNode* ptr = second;
        ListNode* prev = NULL;
        while(ptr) {
            ListNode* next = ptr -> next;
            ptr -> next = prev;
            prev = ptr;
            ptr = next;
        }
        slow -> next = NULL;
        ListNode* first = head;
        second = prev;
        while(second) {
            ListNode* tmp1 = first -> next;
            ListNode* tmp2 = second -> next;
            first -> next = second;
            second -> next = tmp1;
            first = tmp1;
            second = tmp2;
        }
    }
};
