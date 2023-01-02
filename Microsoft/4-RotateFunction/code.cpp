#include<bits/stdc++.h>
using namespace std;
int maxRotationSum(vector<int>& nums){
    int sum = 0, func = 0;
    for(int i=0; i<nums.size(); i++){
        sum += nums[i];
        func += i * nums[i];
    }
    int finalSum = func;

    for(int i= nums.size()-1 ; i>0 ; i--){
        func = func + sum - nums.size() * nums[i];
        finalSum = max(finalSum, func);
    }
    return finalSum;
}
int main(){
    vector<int> nums = {100};
    int answer = maxRotationSum(nums);
    cout<<answer;
    return 0;
}