// add two numbers 2
#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list. */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    stack<int> st1;
    stack<int> st2;

    while (l1 != NULL)
    {
        st1.push(l1->val);
        l1 = l1->next;
    }
    while (l2 != NULL)
    {
        st2.push(l2->val);
        l2 = l2->next;
    }

    int carry = 0;

    ListNode *ans = NULL;

    while (!st1.empty() || !st2.empty() || carry != 0)
    {

        int x = st1.empty() ? 0 : st1.top();
        int y = st2.empty() ? 0 : st2.top();

        int temp = x + y + carry;
        int digit = temp % 10;
        carry = temp / 10;

        if (ans == NULL)
        {
            ans = new ListNode(digit);
        }
        else
        {
            ListNode *newNode = new ListNode(digit);
            newNode->next = ans;
            ans = newNode;
        }

        if (!st1.empty())
            st1.pop();

        if (!st2.empty())
            st2.pop();
    }
    return ans;
}

int main()
{
}