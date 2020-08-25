#include <iostream>
#include <queue>
using namespace std;

const int NMAX = 100 + 2;
int ans,N, edgeCnt;
bool trip[NMAX];
int graph[NMAX][NMAX];
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> edgeCnt;

    for (int i = 0; i <edgeCnt; ++i)
    {
        int src,dst;
        cin >> src >> dst;
        graph[src][dst] = 1;
        graph[dst][src] = 1;
    }

    queue<int> q;
    q.push(1); 
    trip[1] = true;

    while (!q.empty())
    {
        int now = q.front(); q.pop();

        for (int i = 0; i < NMAX; ++i)
        {
            if (i == now) continue;
            if (graph[i][now] == 1 && (trip[i] == false))
            {
                trip[i] = true;
                ans += 1;
                q.push(i);
            }
        }
    }

    cout << ans << "\n";
    return 0;
}