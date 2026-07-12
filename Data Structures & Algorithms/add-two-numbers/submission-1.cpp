class Solution {
   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;

        int carr = 0;
        while (l1 != NULL || l2 != NULL || carr != 0) {
            int v1 = (l1 != NULL) ? l1->val : 0;
            int v2 = (l2 != NULL) ? l2->val : 0;

            int val = v1 + v2 + carr;
            carr = val / 10;
            val = val % 10;
            cur->next = new ListNode(val);

            cur = cur->next;

            l1 = (l1 != NULL) ? l1->next : NULL;
            l2 = (l2 != NULL) ? l2->next : NULL;
        }
        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};