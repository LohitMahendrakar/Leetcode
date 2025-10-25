class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        // Count length and make circular
        int n = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            n++;
        }
        tail->next = head;

        // Adjust k
        k = k % n;
        int x = n - k;

        // Find new tail
        ListNode* newTail = head;
        for (int i = 1; i < x; i++) {
            newTail = newTail->next;
        }

        // Set new head and break circle
        head = newTail->next;
        newTail->next = nullptr;

        return head;
    }
};
