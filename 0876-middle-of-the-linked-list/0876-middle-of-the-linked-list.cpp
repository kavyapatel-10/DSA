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
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        int counter = 0;
        while(temp!= NULL){
            counter++;
            temp = temp->next;
        }
        int var = 0;

        if(counter % 2 != 0){
            var = counter/2 + 1 ;
        }else{
            var = counter/2 + 1;
        }

        temp = head;
        while(temp!= NULL){
            var--;
            if(var == 0){
                break;
            }
            temp = temp->next;
        }


        return temp;
    }
};