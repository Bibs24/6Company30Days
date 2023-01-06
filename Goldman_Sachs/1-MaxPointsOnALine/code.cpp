#include <bits/stdc++.h>
using namespace std;

int maxPoints(vector<vector<int>> &points)
{
    int n = points.size();
    int maxi = 0;
    if (n < 2)
        return n;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int x1 = points[i][0];
            int y1 = points[i][1];
            int x2 = points[j][0];
            int y2 = points[j][1];
            int cnt = 2;
            for (int k = j + 1; k < n; k++)
            {
                int x3 = points[k][0];
                int y3 = points[k][1];
                if ((x2 - x1) * (y3 - y1) == (x3 - x1) * (y2 - y1))
                {
                    cnt++;
                }
            }
            maxi = max(maxi, cnt);
        }
    }
    return maxi;
}

int main(){
    // vector<vector<int>> points = {{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}};
    vector<vector<int>> points = {{1,1},{2,2},{3,3}};
    int answer = maxPoints(points);
    cout<<answer;
    return 0;
}