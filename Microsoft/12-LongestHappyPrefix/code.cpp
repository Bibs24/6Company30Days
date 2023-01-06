#include<bits/stdc++.h>
using namespace std;

string longestPrefix(string &s){
    int n = s.size();
    vector<int> lps(n, 0);
    int i = 1, j = 0;

    while(i<n){
        if(s[i] == s[j]){
            lps[i] = j + 1;
            i++;
            j++;
        }else{
            if(j > 0){
                j = lps[j-1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        } 
    }
    int longPrefixlen = lps[n-1];
    string answer = s.substr(0, longPrefixlen);
    return answer;
}

int main(){
    string s = "cdacdacdc";
    string answer = longestPrefix(s);
    cout<<answer;
    return 0;
}