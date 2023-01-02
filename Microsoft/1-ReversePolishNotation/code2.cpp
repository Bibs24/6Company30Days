#include<bits/stdc++.h>
using namespace std;

int calculate(vector<string>& tokens){
    string s = tokens.back();
    tokens.pop_back();

    if(s != "+" && s != "-" && s != "/" && s != "*") return stoi(s);

    else{
        long y = calculate(tokens);
        long x = calculate(tokens);
        if(s == "+") return x+y;
        else if(s == "-") return x-y;
        else if(s == "/") return x/y;
        else return x*y;
    }
    return -1;
}

int main(){
    vector<string> s = {"4","13","5","/","+"}; 
    int answer = calculate(s);
    cout<<answer;

    return 0;
}