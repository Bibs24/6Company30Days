#include <bits/stdc++.h>
using namespace std;

int findUnsortedSubarray(vector<int> &nums)
{
    int n = nums.size();
    vector<int> res;
    res = nums;
    int i = 0;
    int j = n - 1;
    sort(res.begin(), res.end());

    for (; i < n; i++)
    {
        if (nums[i] != res[i])
        {
            break;
        }
    }

    for (; j >= 0; j--)
    {
        if (nums[j] != res[j])
        {
            break;
        }
    }
    int cnt = 0;
    for (int k = i; k <= j; k++)
    {
        cnt++;
    }
    return cnt;
}

int main(){
    vector<int> nums = {2,6,4,8,10,9,15};
    int answer = findUnsortedSubarray(nums);
    cout<<answer;
    return 0;
}