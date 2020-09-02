#define Pair pair<int,int>
#define WEIGHT first
#define VALUE second
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int NMAX = 105;
const int WEIGHT_MAX = 100005;
int N,K;

int dp[NMAX][WEIGHT_MAX];
vector<Pair> items;
int func(int idx, int weight)
{
    if (weight < 0)
        return 0;
        
    if (idx < 0)
        return 0;

    if (dp[idx][weight] != -1)
        return dp[idx][weight];
        
    int ret = 0;
    ret = func(idx-1,weight);
    if (weight >= items[idx].WEIGHT)
        ret = max(ret, func(idx-1,weight-items[idx].WEIGHT) + items[idx].VALUE);

    return dp[idx][weight] = ret;
}
int main(void) {

    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K;
    memset(dp,-1,sizeof(dp));

    for (int w,v,i = 0; i < N; ++i)
    {
        cin >> w >> v;
        items.push_back(make_pair(w,v));
    }
    
    cout << func(N-1,K) << endl;
    return 0;
}