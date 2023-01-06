#include<bits/stdc++.h>
using namespace std;
int countPaths(int n, vector<vector<int>> &roads){
    long long mod = (long long)(1e9+7);
    vector<pair<long long,long long>> adj[n];

    for(auto it : roads){
        adj[it[0]].push_back({it[1],it[2]});
        adj[it[1]].push_back({it[0],it[2]});
    }
    priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>> pq;
    vector<long long> dist(n, 1e18), ways(n, 0);
    dist[0] = 0;
    ways[0] = 1;
    pq.push({0,0});

    while(!pq.empty()){
        long long dis = pq.top().first;
        long long node = pq.top().second;
        pq.pop();

        for(auto it : adj[node]){
            long long adjNode = it.first;
            long long adw = it.second;
            if(dis + adw < dist[adjNode]){
                dist[adjNode] = dis + adw;
                pq.push({dis + adw , adjNode});
                //first traversal
                ways[adjNode] = ways[node];
            }else if(dis + adw == dist[adjNode]){
                ways[adjNode] = (ways[adjNode] + ways[node])%mod;
            }
        }
    }
    return ways[n-1]%mod;
    
}

int main(){
    int n = 7;
    vector<vector<int>> roads = {{0,6,7},{0,1,2},{1,2,3},{1,3,3},{6,3,3},{3,5,1},{6,5,1},{2,5,1},{0,4,5},{4,6,2}};
    int answer = countPaths(n,roads);
    cout<<answer;
    return 0;
}