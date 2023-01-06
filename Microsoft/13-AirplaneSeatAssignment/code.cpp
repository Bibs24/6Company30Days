#include <bits/stdc++.h>
using namespace std;

double nthPersonGetsNthSeat(int n)
{
    if (n == 1)
        return 1;
    else
        return 0.5;
}

int main(){
    int n = 100;
    double answer;
    answer = nthPersonGetsNthSeat(n);
    cout<<answer;
    return 0;
}