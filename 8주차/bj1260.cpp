//
// Created by kdh on 2024-11-22.
//https://www.acmicpc.net/problem/1260
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void DFS(vector<vector<int>>& graph, vector<bool>& isVisited, int V){
    cout << V+1 << " ";
    isVisited[V] = true;
    for(int i = 0; i < graph[V].size(); i++){
        if(!isVisited[graph[V][i]]){
            DFS(graph, isVisited, graph[V][i]);
        }
    }
}

void BFS(vector<vector<int>>& graph, vector<bool>& isVisited, int V){
    queue<int> q;
    q.push(V);
    isVisited[V] = true;

    while (!q.empty()){
        cout << q.front() + 1 << " ";
        for(int i = 0; i < graph[q.front()].size(); i++){
            if(!isVisited[graph[q.front()][i]]){
                isVisited[graph[q.front()][i]] = true;
                q.push(graph[q.front()][i]);
            }
        }
        q.pop();
    }
}
int main(){
    int N, M, V;
    cin >> N >> M >> V;

    vector<vector<int>> graph(N);
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }
    for(int i = 0; i < N; i++){
        sort(graph[i].begin(), graph[i].end());
    }
    vector<bool> isVisited(graph.size(), false);
    DFS(graph, isVisited, V-1);
    cout << "\n";
    std::fill(isVisited.begin(), isVisited.end(),false);
    BFS(graph, isVisited, V-1);
    return 0;
}
