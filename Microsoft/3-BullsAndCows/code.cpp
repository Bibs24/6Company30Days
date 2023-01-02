#include<bits/stdc++.h>
using namespace std;
string getHint(string secret, string guess){
    int bulls = 0, cows = 0;
    map<int,int> mp;

    for(int i=0; i< secret.size(); i++){
        int s = secret[i];
        int g = guess[i];

        if(s == g) bulls++;
        else{
            if(mp[s] < 0) cows++;
            if(mp[g] > 0) cows++;

            mp[s]++;
            mp[g]--;
        }
    }
    return to_string(bulls) + "A" + to_string(cows) + "B";
}
int main(){
    string secret = "1807";
    string guess = "7810";
    string answer;
    answer = getHint(secret,guess);
    cout<<answer;
    return 0;
}