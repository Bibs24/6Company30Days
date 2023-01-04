#include<bits/stdc++.h>
using namespace std;

bool isRectangleCover(vector<vector<int>>& rectangles) {
        map<pair<int,int>,int> mp;
        for(auto &it : rectangles){
            mp[{it[0], it[1]}]++;
            mp[{it[2], it[3]}]++;
            mp[{it[0], it[3]}]--;
            mp[{it[2], it[1]}]--;

        }
        int cnt = 0;

        for(auto it= mp.begin() ; it != mp.end() ;it++){
            if(abs(it->second) == 1){
                cnt++;
            }else if(abs(it->second != 1) && it->second != 0){
                return false;
            }
            
        }
        return cnt == 4;
    }

int main(){
    vector<vector<int>> rectangles = {{1,1,3,3},{1,3,2,4},{3,1,4,2},{3,2,4,4},{2,3,3,4}};
    bool answer;
    answer = isRectangleCover(rectangles);
    cout<<answer;
    return 0;
}