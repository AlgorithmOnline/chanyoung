#define INF 987654321
#define Tuple tuple<int,int,int,int>
#define EMPTY 0
#define WALL 1
#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int dy[] = {-1,1,0,0};
int dx[] = {0,0,-1,1};

int N,M,K;
vector<vector<int>> board;
int visited[11][1001][1001];

bool isSafe(int y, int x)
{
    return (0 <= y && y < N && 0 <= x && x < M);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M >> K;

    board.resize(N,vector<int>(M,0));
    for (int i = 0; i < 11; ++i)
    {
        for (int j = 0; j < 1001; ++j)
        {
            fill(visited[i][j], visited[i][j] + 1001, INF);
        }
    }

    for (int i = 0; i < N; ++i)
    {
        string line;
        cin >> line;
        for (int j = 0; j < line.size(); ++j)
        {
            if (line[j] == '0') board[i][j] = EMPTY;
            else board[i][j] = WALL;
        }
    }

    int ret = INF;
    queue<Tuple> q;
    q.push({0,0,1,K});  //Y,X,CNT,K

    while (!q.empty())
    {
        Tuple now = q.front(); q.pop();
        
        int y,x,cnt,rest;
        tie(y,x,cnt,rest) = now;

        if (y == N-1 && x == M-1)
        {
            ret = min(ret,cnt);
            break;
        }

        for (int dir = 0; dir < 4; ++dir)
        {
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            
            if (!isSafe(ny,nx)) continue;

            if (board[ny][nx] == EMPTY && cnt + 1 < visited[rest][ny][nx])
            {
                visited[rest][ny][nx] = cnt + 1;
                q.push({ny,nx,cnt+1,rest});
            }
            else 
            {
                if (rest >= 1 && cnt + 1 < visited[rest-1][ny][nx])
                {
                    visited[rest-1][ny][nx] = cnt + 1;
                    q.push({ny,nx,cnt+1,rest-1});
                }
            }
        }
    }    
    
    if (ret == INF) 
    {
        cout << -1 << "\n";
    }
    else 
    {
        cout << ret << "\n";   
    }

    return 0;
}