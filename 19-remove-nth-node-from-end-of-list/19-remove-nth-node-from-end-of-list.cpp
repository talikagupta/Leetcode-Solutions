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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      //creating a dummy node to make things easier for us
      ListNode new_head(-1);
      new_head.next = head;

      ListNode *left = &new_head;
      ListNode *right = &new_head;

      while(n--)
        right = right->next;

      while (right->next) 
        {
          right = right->next;
          left = left->next;
        }

        ListNode *del = left->next;
        left->next = left->next->next;
    
        //to avoid memory leak
        delete del;

        return new_head.next;
    }
};