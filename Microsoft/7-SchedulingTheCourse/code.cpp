#include<bits/stdc++.h>
using namespace std;

bool canFinish(int numCourses, vector<vector<int>> &prerequisites){
    vector<int> adj[numCourses];
    vector<int> indegree(numCourses, 0);
    queue<int> q;
    vector<int> topo;

    for(int i=0; i<prerequisites.size(); i++){
        adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
    }

    for(int i=0; i<numCourses; i++){
        for(auto &j : adj[i]){
            indegree[j]++;
        }
    }

    for(int i =0;i<numCourses;i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int node = q.front(); q.pop();
        topo.push_back(node);

        for(auto &i : adj[node]){
            indegree[i]--;
            if(indegree[i] == 0){
                q.push(i);
            }
        }
    }
    return topo.size() == numCourses;
}

int main(){
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1,0}};
    bool answer = canFinish(numCourses,prerequisites);
    cout<<answer;

    return 0;
}