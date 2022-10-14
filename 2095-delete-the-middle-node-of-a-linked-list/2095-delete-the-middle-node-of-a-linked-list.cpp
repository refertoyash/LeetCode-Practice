/**
 *Definition for singly-linked list.
 *struct ListNode {
 *int val;
 *ListNode * next;
 *ListNode() : val(0), next(nullptr) {}
 *ListNode(int x) : val(x), next(nullptr) {}
 *ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        int length(ListNode *head)
        {
            int ct = 0;
            ListNode *temp = head;
            while (temp->next != NULL)
            {
                ct++;
                temp = temp->next;
            }
            return ct + 1;
        }
    ListNode* deleteMiddle(ListNode *head)
    {
        int a = length(head);
        if (a == 1) return NULL;
        int mid = a / 2;
        int ct = 0;
        ListNode *temp = head;

        while (ct != mid - 1)
        {
            ct++;
            temp = temp->next;
        }
        ListNode *todelete = temp->next;
        temp->next = temp->next->next;
        delete(todelete);
        return head;
    }
};