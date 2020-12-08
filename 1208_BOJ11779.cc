#define INF 987654321
#define Pair pair<int,int>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

int n,m,st,en;
vector<vector<Pair>> bus;

void djikstra(int src, int dst)
{
    stack<int> ret;
    vector<int> before(n,INF);
    vector<int> dist(n,INF);
    priority_queue<Pair> pq;
    pq.push(make_pair(0,src));
    dist[src] = 0;
    
    while (!pq.empty())
    {
        Pair now = pq.top(); pq.pop();
        now.first = -now.first;

        if (dist[now.second] < now.first)
            continue;

        for (Pair nxt : bus[now.second])
        {
            int nxtNode = nxt.first;
            int cost = nxt.second;
            
            int nxtCost = now.first + cost;

            if (dist[nxtNode] > nxtCost)
            {
                dist[nxtNode] = nxtCost;
                pq.push(make_pair(-nxtCost,nxtNode));
                before[nxtNode] = now.second;
            }
        }
    }

    int node = dst;
    while (node != src)
    {
        ret.push(node);
        node = before[node];
    }
    ret.push(src);

    cout << dist[dst] << "\n";
    cout << ret.size() << "\n";
    
    while (!ret.empty())
    {
        cout << ret.top() + 1 << " ";
        ret.pop();
    }

    return;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    bus.resize(n);

    for (int loop = 0; loop < m; ++loop)
    {
        int st,en,cost;
        cin >> st >> en >> cost;
        st--; en--;
        bus[st].push_back(make_pair(en,cost));
    }

    cin >> st >> en;
    st--; en--;

    djikstra(st,en);
    return 0;
}