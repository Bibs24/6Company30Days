#include<bits/stdc++.h>
using namespace std;

string longestPrefix(string &s){
    string answer = "";
    int n = s.size();
    vector<int> lps(n, 0);
    int i = 1, j = 0;

    for(; i< n ; i++){
        while(s[i] != s[j] && j > 0){
            j = lps[j-1];
        }
        if(s[i] == s[j]){
            lps[i] = j + 1;
            j++;
        }
    }
    for(int k = 0; k < lps[n-1]; k++){
        answer += s[k]; 
    }
    return answer;
}

int main(){
    string s = "cdacdacdc";
    string answer = longestPrefix(s);
    cout<<answer;
    return 0;
}