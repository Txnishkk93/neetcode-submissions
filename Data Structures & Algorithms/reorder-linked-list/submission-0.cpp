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
        if (head == NULL || head->next == NULL) return;
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* secondHalf = reverseList(slow->next);
        slow->next = NULL;

        ListNode* firstHalf = head;
        while (secondHalf != NULL) {
            ListNode* temp1 = firstHalf->next;
            ListNode* temp2 = secondHalf->next;

            firstHalf->next = secondHalf;
            secondHalf->next = temp1;

            firstHalf = temp1;
            secondHalf = temp2;
        }
    }

   private:
    ListNode* reverseList(ListNode* node) {
        ListNode* prev = NULL;
        ListNode* curr = node;

        while (curr != NULL) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    }
};
