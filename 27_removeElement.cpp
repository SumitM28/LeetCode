// remove element form the array of same value
#include <bits/stdc++.h>
using namespace std;

int removeElement(vector<int> &nums, int val)
{
    int s = 0;
    int e = nums.size() - 1;

    while (s <= e)
    {
        if (nums[e] == val)
        {
            e--;
        }
        else if (nums[s] == val)
        {
            swap(nums[s++], nums[e--]);
        }
        else
        {
            s++;
        }
    }
    return s;
}
int main(){
    
}