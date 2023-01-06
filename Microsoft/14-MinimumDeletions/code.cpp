#include <bits/stdc++.h>
using namespace std;

int minOperations(vector<int> &nums, vector<int> &numsDivide)
{
    int gcd = numsDivide[0];
    sort(begin(nums), end(nums));
    for (int i = 1; i < numsDivide.size(); i++)
    {
        gcd = __gcd(gcd, numsDivide[i]);
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (gcd % nums[i] == 0)
            return i;
    }
    return -1;
}

int main(){
    vector<int> nums = {2,3,2,4,3};
    vector<int> numsDivide = {9,6,9,3,15};
    int answer = minOperations(nums, numsDivide);
    cout<<answer;
    return 0;
}