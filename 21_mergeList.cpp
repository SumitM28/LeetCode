// Merge two sorted linked list.
/* You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list. */
#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void addAtTail(ListNode *&head, ListNode *&tail, int data)
{
    ListNode *newNode = new ListNode(data);
    if (head == NULL)
    {
        head = newNode;
        tail = head;
        return;
    }
    tail->next = newNode;
    tail = tail->next;
}
ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    if (list1 == NULL && list2 == NULL)
    {
        return NULL;
    }
    if (list1 == NULL && list2 != NULL)
    {
        return list2;
    }
    if (list1 != NULL && list2 == NULL)
    {
        return list1;
    }

    ListNode *head = NULL;
    ListNode *tail = head;

    while (list1 != NULL && list2 != NULL)
    {

        if (list1->val < list2->val)
        {
            addAtTail(head, tail, list1->val);
            list1 = list1->next;
        }
        else
        {
            addAtTail(head, tail, list2->val);
            list2 = list2->next;
        }
    }
    while (list1 != NULL)
    {
        addAtTail(head, tail, list1->val);
        list1 = list1->next;
    }
    while (list2 != NULL)
    {
        addAtTail(head, tail, list2->val);
        list2 = list2->next;
    }
    return head;
}
