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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* prev = NULL;
        ListNode* head2;
        while(l1 && l2) {
            int num = l1->val + l2->val + carry;
            ListNode *head = new ListNode(num % 10, NULL);
            carry = num / 10;
            if(prev) {
                prev -> next = head;
            }
            else
                head2 = head;
            prev = head;
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        while(l1) {
            int num = carry + l1->val;
            ListNode *head = new ListNode(num % 10, NULL);
            prev -> next = head;
            l1 = l1 -> next;
            carry = num / 10;
            prev = head;
        }
        while(l2) {
            int num = carry + l2->val;
            ListNode *head = new ListNode(num % 10, NULL);
            prev -> next = head;
            l2 = l2 -> next;
            carry = num / 10;
            prev = head;
        }
        if(carry) {
            ListNode *head = new ListNode(carry, NULL);
            prev -> next = head;
        }
        return head2;
    }
};
