class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = l1;
        ListNode* prev = NULL;
        int carry = 0;

        while (l1 || l2) {
            int sum = carry;

            if (l1) {
                sum += l1->val;
            }
            if (l2) {
                sum += l2->val;
            }

            carry = sum / 10;
            int rem = sum % 10;

            if (l1) {
                l1->val = rem;
                prev = l1;
                l1 = l1->next;
            } else {
                prev->next = new ListNode(rem);
                prev = prev->next;
            }

            if (l2) l2 = l2->next;
        }

        if (carry) {
            prev->next = new ListNode(carry);
        }

        return head;
    }
};