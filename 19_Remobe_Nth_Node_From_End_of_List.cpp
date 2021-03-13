#include "main.h"

using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* newHead = head;
        ListNode* pre;
        ListNode* nextNode;
        vector<ListNode*> indexOfNode;
        while(newHead!=nullptr)
        {
            indexOfNode.push_back(newHead);
            newHead=newHead->next;
        }
        int listSize = indexOfNode.size();
         if(listSize == 1)
        {
            return nullptr;
        }
        if(n == 1) // remove the last one
        {
            pre = indexOfNode[listSize-2];
            pre->next = nullptr;
        }
        else if (n == listSize) // remove the head of list
        {
            head = indexOfNode[1];
        }
        else// other situation
        {
            pre = indexOfNode[listSize - n - 1];
            nextNode = indexOfNode[listSize - n + 1];
            pre->next = nextNode;
        }
        return head;
    }
};