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

    ListNode* findKthNode(ListNode* temp, int k) {

        k = k - 1;

        while (temp != NULL && k > 0) {
            temp = temp->next;
            k--;
        }

        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* temp = head;
        ListNode* prevNode = NULL;

        while (temp != NULL) {

            // Find kth node
            ListNode* kthNode = findKthNode(temp, k);

            // Less than k nodes remaining
            if (kthNode == NULL) {

                if (prevNode != NULL) {
                    prevNode->next = temp;
                }

                break;
            }

            // Store next group
            ListNode* nextNode = kthNode->next;

            // Reverse current group
            ListNode* prev = nextNode;
            ListNode* curr = temp;

            while (curr != nextNode) {
                ListNode* front = curr->next;
                curr->next = prev;
                prev = curr;
                curr = front;
            }

            // First group
            if (temp == head) {
                head = kthNode;
            }
            else {
                prevNode->next = kthNode;
            }

            // temp is now the last node of reversed group
            prevNode = temp;

            // Move to next group
            temp = nextNode;
        }

        return head;
    }
};