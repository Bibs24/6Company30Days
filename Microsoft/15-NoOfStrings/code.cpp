#include <bits/stdc++.h>
using namespace std;

int numberOfSubstrings(string s)
{
    int left = 0, right = 0, end = s.size() - 1;
    int cnt = 0;
    unordered_map<char, int> mp;

    while (right != s.size())
    {
        mp[s[right]]++;
        while (mp['a'] && mp['b'] && mp['c'])
        {
            cnt += 1 + (end - right);
            mp[s[left]]--;
            left++;
        }
        right++;
    }
    return cnt;
}

int main()
{
    string s = "abcabc";
    int answer = numberOfSubstrings(s);
    cout << answer;
    return 0;
}