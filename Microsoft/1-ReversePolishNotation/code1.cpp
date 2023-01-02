#include<bits/stdc++.h>
using namespace std;

long helpCalculate(int x, int y, char op){
    if(op == '+') return x+y;
    else if(op == '-') return x-y;
    else if(op == '/') return x/y;
    else return (long)x*y;
}
int calculate(vector<string>& tokens){
    stack<long> s;
    int n = tokens.size();
    for(int i=0; i<n ;i++){
        if(tokens[i].size() == 1 && tokens[i][0] < 48){
            long y = s.top(); s.pop();
            long x = s.top(); s.pop();

            string op = tokens[i];

            long ans = helpCalculate(x, y, op[0]);
            s.push(ans);
            
        }else{
            s.push(stol(tokens[i]));
        }
    }

    return s.top();

}

int main(){
    vector<string> s = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"}; 
    int answer = calculate(s);
    cout<<answer;

    return 0;
}