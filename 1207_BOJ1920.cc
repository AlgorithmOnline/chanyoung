#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
vector<int> v, q;

bool binarySearch(int targetNumber)
{
    int st, mid, en;
    st = 0;
    en = v.size();

    while (st <= en)
    {
        mid = (st + en) / 2;

        if (v[mid] == targetNumber) 
				{
						return true;
				}
        else if (v[mid] < targetNumber)
        {
            st = mid + 1;
        }
        else
        {
            en = mid - 1;
        }
    }

    return false;
}
int main(void)
{
    scanf("%d",&N);
    for (int x,i = 0; i < N; ++i)
    {
        scanf("%d",&x);
        v.push_back(x);
    }

    scanf("%d",&M);
    for (int x,i =0; i < M; ++i)
    {
        scanf("%d",&x);
        q.push_back(x);
    }

    sort(v.begin(), v.end());

    for (int num : q)
    {
        if (binarySearch(num))
        {
            printf("1\n");
        }
        else
        {
            printf("0\n");
        }
        
    }
    return 0;
}

