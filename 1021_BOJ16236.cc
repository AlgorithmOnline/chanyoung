#define Y first
#define X second
#define Pair pair<int,int>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef struct Tuple {
    int e1,e2,e3,e4;    //Y,X,size,EatCnt
    Tuple() : e1(0), e2(0), e3(0), e4(0) {}
    Tuple(int y, int x) : e1(y), e2(x), e3(2), e4(0) {}
    Tuple(int ee1, int ee2, int ee3, int ee4) : e1(ee1), e2(ee2), e3(ee3), e4(ee4) {}
}Tuple;

typedef struct Comp {
    bool operator()(Tuple t1, Tuple t2) {
        if (t1.e3 == t2.e3)
        {
            if (t1.e1 == t2.e1)
            {
                return t1.e2 > t2.e2;
            }
            else
            {
                return t1.e1 > t2.e1;
            }
        }
        else
        {
            return t1.e3 > t2.e3;
        }
    }
}Comp;

const int dy[] = {-1,0,1,0};
const int dx[] = {0,-1,0,1};

const int DUMMY = -1;   //사용안하는 값
const int EMPTY = 0;
const int SHARK = 99999;

int N,ans, fishCnt;
Tuple sk;
vector<vector<int>> board;
vector<vector<bool>> visited;
bool isSafe(int y, int x)
{
    return (0 <= y && y < N && 0 <= x && x < N);
}
Tuple isFindFish()
{
    if (fishCnt == 0) 
        return Tuple(-1,-1,DUMMY,DUMMY);

    //bfs
    for (int i = 0; i < N; ++i)
        fill(visited[i].begin(), visited[i].end(), false);

    priority_queue<Tuple, vector<Tuple>, Comp> pq;
    visited[sk.e1][sk.e2] = true;
    pq.push(Tuple(sk.e1,sk.e2,0,DUMMY));
    
    while (!pq.empty())
    {
        Tuple now = pq.top(); pq.pop();

        if (board[now.e1][now.e2] != EMPTY && board[now.e1][now.e2] < sk.e3)
        {
            board[now.e1][now.e2] = EMPTY;
            return Tuple(now.e1,now.e2,now.e3,DUMMY);
        }
        
        for (int dir = 0; dir < 4; ++dir)
        {
            int ny = now.e1 + dy[dir];
            int nx = now.e2 + dx[dir];

            if (!isSafe(ny,nx)) continue;
            else if (visited[ny][nx]) continue;
            else if (board[ny][nx] > sk.e3) continue;

            visited[ny][nx] = true;
            pq.push(Tuple(ny,nx,now.e3 + 1, DUMMY));
        }
    }

    return Tuple(-1,-1,DUMMY,DUMMY);
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    board.resize(N,vector<int>(N,0));
    visited.resize(N,vector<bool>(N,false));

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == 9)
            {
                sk = Tuple(i,j);
                board[i][j] = 0;
            }
            else if (board[i][j] != EMPTY)
            {
                fishCnt += 1;
            }
        }
    }

    //LOOP
        //1. 상어가 이동할 다음 칸 찾기
        //2. 상어 이동
        //2. 상어 정보 갱신
    do {

        //find
        Tuple ret = isFindFish();

        if (ret.e1 == -1 && ret.e2 == -1)
            break;

        //move
        sk.e1 = ret.e1;
        sk.e2 = ret.e2;

        //update
        sk.e4 += 1;
        fishCnt--;
        ans += ret.e3;
        
        if (sk.e4 == sk.e3)
        {
            sk.e3 += 1;
            sk.e4 = 0;
        }

    } while (true);

    cout << ans;

    return 0;
}