#include <bits/stdc++.h>
using namespace std;

vector<int> largestDivisibleSubset(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 1), map(n);
    int lastidx = 0;
    int maxi = 1;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++)
    {
        map[i] = i;
        for (int j = 0; j < i; j++)
        {
            if (nums[i] % nums[j] == 0 && 1 + dp[j] > dp[i])
            {
                dp[i] = 1 + dp[j];
                map[i] = j;
            }
        }
        if (dp[i] > maxi)
        {
            maxi = dp[i];
            lastidx = i;
        }
    }
    vector<int> temp;
    temp.push_back(nums[lastidx]);

    while (map[lastidx] != lastidx)
    {
        lastidx = map[lastidx];
        temp.push_back(nums[lastidx]);
    }
    reverse(temp.begin(), temp.end());
    return temp;
}

int main(){
    vector<int> nums = {1,2,3};
    vector<int> answer;
    answer = largestDivisibleSubset(nums);
    for(auto &i : answer){
        cout<<i<<" ";
    }
    return 0;
}
