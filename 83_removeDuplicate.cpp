// remove duplicate from the sorted array

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *deleteDuplicates(ListNode *head)
{
    ListNode *curr = head;

    while (curr != NULL)
    {
        if (curr->next != NULL && curr->val == curr->next->val)
        {
            curr->next = curr->next->next;
        }
        else
        {
            curr = curr->next;
        }
    }
    return head;
}