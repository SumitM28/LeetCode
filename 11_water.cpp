// container with most water
#include<bits/stdc++.h>
using namespace std;

int maxArea(vector<int> &height)
{
    int area = 0;
    int left = 0;
    int right = height.size() - 1; // rightmost element
    while (left < right)
    {
        int h = min(height[left], height[right]);
        area = max(area, h * (right - left));

        if (height[left] < height[right])
            left++;
        else
            right--; // else decreasing rightmost element
    }
    return area;
}