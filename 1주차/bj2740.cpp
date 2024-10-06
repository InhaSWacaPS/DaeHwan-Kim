/*https://www.acmicpc.net/problem/2740*/
#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> mutiply_mat(vector<vector<int>>& A, vector<vector<int>>& B, int N,int M, int K){
    vector<vector<int>> result(N, vector<int>(K, 0));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < K; j++){
            for(int l = 0; l < M; l++){
                result[i][j] += A[i][l]*B[l][j];
            }
        }
    }
    return result;
}


void fillmat(vector<vector<int>>& A, int N, int M){
    for(int i =0; i< N; i++){
        for(int j =0; j<M; j++){
            int a1;
            cin >> a1;
            A[i][j] = a1;
        }
    }
}

int main(){
    int N, M, K;

    cin >> N >> M;
    vector<vector<int>> A(N, vector<int>(M, 0));
    fillmat(A, N, M);

    cin >> M >> K;
    vector<vector<int>> B(M, vector<int>(K, 0));
    fillmat(B, M, K);

    vector<vector<int>> result = mutiply_mat(A, B, N, M, K);
    for(auto i : result){
        for(auto k : i){
            cout << k << " ";
        }
        cout << endl;
    }
}
