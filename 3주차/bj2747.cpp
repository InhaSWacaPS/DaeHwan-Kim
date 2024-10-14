//
// Created by okim on 2024-10-14.
// https://www.acmicpc.net/problem/2747
//

#include <iostream>

using namespace  std;

void Fibonachi(int n){
    int fibonachi_array[n+1];
    fibonachi_array[0] = 0;
    fibonachi_array[1] = 1;

    for(int i = 2; i <= n; i++){
        fibonachi_array[i] = fibonachi_array[i-1] + fibonachi_array[i-2];
    }
    cout << fibonachi_array[n];
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    Fibonachi(n);
    return 0;
}
