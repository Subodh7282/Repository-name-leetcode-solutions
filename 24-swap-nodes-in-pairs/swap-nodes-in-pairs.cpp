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
    

    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) { //[cite: 1]
            return head; //[cite: 1]
        }

        ListNode* first = head; //[cite: 1]
        ListNode* sec = head->next; //[cite: 1]
        ListNode* prev = NULL; //[cite: 1]

        while(first != NULL && sec != NULL) {
            ListNode* third = sec->next;
            sec->next = first;
            first->next = third;
            
            if(prev != NULL) {
                prev->next = sec;
            } else {
                head = sec; //[cite: 2]
            }

            //update[cite: 2]
            prev = first; //[cite: 2]
            first = third; //[cite: 2]
            if(third != NULL) { //[cite: 2]
                sec = third->next; //[cite: 2]
            } else { //[cite: 2]
                sec = NULL; //[cite: 2]
            }
        }

        return head; //[cite: 2]
    }
};
    
