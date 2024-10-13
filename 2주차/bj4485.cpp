//
// Created by okim on 2024-10-13.
// https://www.acmicpc.net/problem/4485
//
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
struct Edge{
    int cost;
};

int dijstra(vector<vector<Edge>>& graph, vector<int>& cost_graph, int T){
    fill(cost_graph.begin(), cost_graph.end(), T*T*9);
    cost_graph[0] = graph[0][0].cost;
    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({graph[0][0].cost,0});
    while (!pq.empty()){
        int graph_cost = pq.top().first;
        int graph_node = pq.top().second;


        pq.pop();

        if(cost_graph[graph_node] < graph_cost)
            continue;

        // 네 방향 탐색
        int directions[] = {1, -1, T, -T};
        for (int dir : directions) {
            int new_graph_node = graph_node + dir;
            // 경계 조건 확인
            if (new_graph_node >= 0 && new_graph_node < T * T) {
                int current_row = graph_node / T;
                int current_col = graph_node % T;
                int new_row = new_graph_node / T;
                int new_col = new_graph_node % T;

                // 상하좌우로만 이동 가능, 대각선 이동 금지
                if (abs(current_row - new_row) + abs(current_col - new_col) != 1) {
                    continue;  // 대각선 방향은 무시
                }
                int next_graph_cost = graph_cost + graph[new_graph_node / T][new_graph_node % T].cost;

                // 최소 비용 갱신
                if (cost_graph[new_graph_node] > next_graph_cost) {
                    cost_graph[new_graph_node] = next_graph_cost;
                    pq.push({next_graph_cost, new_graph_node});
                }
            }
        }
    }
    return cost_graph[T*T-1];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int count = 1;
    while (true){
        int T;
        cin >> T;

        if(T == 0)
            break;

        vector<vector<Edge>> graph(T, vector<Edge>(T));
        for(int i = 0; i < T; i++){
            for(int j = 0; j < T; j++){
                int N;
                cin >> N;
                graph[i][j].cost = N;
            }
        }
        vector<int> cost_graph(T*T);
        int result = dijstra(graph, cost_graph, T);
        cout << "Problem "<< count++ << ": " << result << "\n";
    }
    return 0;
}
