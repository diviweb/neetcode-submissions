/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return nullptr;
        Node* list1 = head;
        while(list1) {
            Node* list2 = new Node(list1 -> val);
            list2 -> next = list1 -> next;
            list1 -> next = list2;
            list1 = list2 -> next;
        }
        Node* newHead = head -> next;
        list1 = head;
        while(list1) {
           if (list1->random != nullptr) {
                list1->next->random = list1->random->next;
            }
            list1 = list1 -> next -> next;
        }
        list1 = head;
        while(list1) {
            Node* list2 = list1 -> next;
            list1 -> next = list2 -> next;
            if (list2->next != nullptr) {
                list2->next = list2->next->next;
            }
            list1 = list1 -> next;
        }
        return newHead;
    }
};
