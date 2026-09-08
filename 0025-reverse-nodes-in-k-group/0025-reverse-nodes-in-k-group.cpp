class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // 1. Count length of the list
        int len = 0;
        ListNode* temp = head;  // must be a pointer
        while (temp != nullptr) {
            len++;
            temp = temp->next;
        }

        // 2. If remaining nodes < k, don't reverse
        if (len < k) {
            return head;
        }

        // 3. Reverse first k nodes
        ListNode* prev = nullptr;
        ListNode* curr = head;

        for (int i = 0; i < k; ++i) {
            ListNode* forward = curr->next;
            curr->next = prev;   // reverse the link
            prev = curr;
            curr = forward;
        }

        // 4. Recursively reverse the rest
        ListNode* recursionAnsKaHead = reverseKGroup(curr, k);
        head->next = recursionAnsKaHead;  // head is now tail of this group

        return prev;  // prev is new head of this reversed group
    }
};