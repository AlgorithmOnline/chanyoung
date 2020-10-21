#define Y first
#define X second
#define Pair pair<int,int>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

const int EMPTY = 0;
const int HOUSE = 1;
const int CHICKEN_SHOP = 2;
const int INF = 987654321;
int N,M;
vector<vector<int> > map;
vector<Pair> houses;
vector<Pair> shops;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    map.resize(N,vector<int>(N,0));

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> map[i][j];
            if (map[i][j] == CHICKEN_SHOP)
            {
                shops.push_back(make_pair(i,j));
            }
            else if (map[i][j] == HOUSE)
            {
                houses.push_back(make_pair(i,j));
            }
        }
    }

    //치킨집 M개 고르기
    int shopSize = shops.size();
    vector<int> picks;
    for (int loop = 0; loop < shopSize - M; ++loop)
        picks.push_back(0);
    
    for (int loop = 0; loop < M; ++loop)
        picks.push_back(1);

    int ans = INF;

    do {

        //calculate
        vector<int> dist(houses.size(), INF);

        for (int i = 0; i < picks.size(); ++i)
        {
            if (picks[i] == 0) continue;

            Pair nowShop = shops[i];

            for (int j = 0; j < houses.size(); ++j)
            {
                int distance = abs(nowShop.Y - houses[j].Y) + abs(nowShop.X - houses[j].X);
                dist[j] = min(distance,dist[j]);
            }
        }

        int candidate = 0;
        for (int num : dist)
            candidate += num;

        ans = min(ans,candidate);

    } while (next_permutation(picks.begin(), picks.end()));

    cout << ans;

    return 0;
}