#include "main.h"

using namespace std;

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
    ListNode* reverseList(ListNode* head) {
        stack<ListNode*> listStack;
        while(head)
        {
            listStack.push(head);
            head = head->next;
        }
        ListNode* newList= nullptr;
        ListNode* returnPointer= nullptr;
        while(listStack.empty())
        {
            if(newList == nullptr)
            {
                newList = listStack.pop();
                returnPointer = newList;
            }
            else
            {
                newList->next = listStack.pop();
                newList = newList->next;
            }
        }
        return returnPointer;
    }
};
