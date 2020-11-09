#define IMPOSSIBLE 987654321
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<vector<int>> W, dp;

//dp[][] : 현재 노드의 위치, 방문한 상태
int TSP(int currentNode, int visited) {
    
    if (dp[currentNode][visited] != -1) {
        return dp[currentNode][visited];
    }

    //기저 사례 (모두 노드를 방문한 경우)
    if ((visited == (1<<N) - 1)) {
        if (W[currentNode][0] != 0) return W[currentNode][0];
        else return IMPOSSIBLE;
    }  

    int ret = IMPOSSIBLE;
    
    for (int nxt = 0; nxt < N; ++nxt) {
        if (((1 << nxt) & visited) || (W[currentNode][nxt] == 0)) continue;

        ret = min(ret, TSP(nxt, (visited | (1<<nxt))) + W[currentNode][nxt]);
    }

    return dp[currentNode][visited] = ret;
}
int main(void) {
    
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    W.resize(N,vector<int>(N,0));
    dp.resize(N, vector<int>((1<<N), -1));

    for (int i = 0; i < N; ++i)
    for (int j = 0; j < N; ++j)
        cin >> W[i][j];

    //출발 위치: 0번노드, 출발 상태: 0번 노드만 방문한 상태
    cout << TSP(0, 1) << "\n";
    return 0;

}