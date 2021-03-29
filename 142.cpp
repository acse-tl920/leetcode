#include "main.h"

using namespace std;

/**
 * Definition for singly-linked list.*/
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head, *fast = head;
        while(slow != fast)
        {
            if(fast == nullptr || fast->next == nullptr)
            {
                return nullptr;
            }
            fast = fast->next->next;
            slow = slow->next;
        }
        slow = head;
        while(slow != fast)
        {
            slow = slow->next;
            fast = fast ->next;
        }
        return fast;
    }
};
