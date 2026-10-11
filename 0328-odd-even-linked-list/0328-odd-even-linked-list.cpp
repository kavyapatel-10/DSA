class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
 
        vector<int> oddValues;
        vector<int> evenValues;
 
        ListNode* current = head;
        int index = 1;
        
        while (current != nullptr) {
            if (index % 2 != 0) {
                oddValues.push_back(current->val);
            } else {
                evenValues.push_back(current->val);
            }
            index++;
            current = current->next;
        }
 
        current = head;
 
        for (int value : oddValues) {
            current->val = value;
            current = current->next;
        }
 
        for (int value : evenValues) {
            current->val = value;
            current = current->next;
        }
 
        return head;
    }
};
