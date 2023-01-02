#include<bits/stdc++.h>
using namespace std;
void helper(int idx, int len, vector<int> &temp, vector<vector<int>> &result, int size, int sum){
    if(sum == 0 && temp.size() == size){
        result.push_back(temp);
        return;
    }
    for(int i=idx;i<=len;i++){
        temp.push_back(i);
        helper(i+1,len,temp,result,size,sum-i);
        temp.pop_back();
    }
    
}
vector<vector<int>> combinatioSum(int size, int sum){
    vector<vector<int>> result;
    vector<int> temp;
    int len = 9;
    helper(1, len, temp, result, size, sum);
    return result;
}


int main(){
    vector<vector<int>> result;
    int size = 3, sum = 7;
    result = combinatioSum(size, sum);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
    }

    return 0;
}