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
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return NULL;
        }
        ListNode* temp = head;
        int counter = 0;
        while(temp!= NULL){
            counter++;
            temp = temp->next;
        }

        int var = counter/2;

        temp = head;
        while(temp!= NULL){
            var--;
            if(var == 0){
                break;
            }
            temp = temp->next;
        }

        ListNode* delnode = temp->next;
        temp->next = temp->next->next;
        delete delnode;

        return head;   
    }
};