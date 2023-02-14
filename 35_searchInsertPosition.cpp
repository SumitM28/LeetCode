// Search Insert Position
#include <bits/stdc++.h>
using namespace std;

int searchInsert(vector<int> &nums, int target)
{
    int s = 0;
    int e = nums.size() - 1;
    int ans = -1;

    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        if (nums[mid] == target)
        {
            ans = mid;
            break;
        }

        else if (nums[mid] > target)
        {
            e = mid - 1;
            ans = mid;
        }
        else
        {
            s = mid + 1;
            ans = mid + 1;
        }
    }
    return ans;
}