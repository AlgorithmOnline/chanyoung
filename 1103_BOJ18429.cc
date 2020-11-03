#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N,K,ans;
vector<int> finessList;

int main(void)
{
    cin >> N >> K;
    
    for (int x,i = 0; i < N; ++i)
    {
        cin >> x;
        finessList.push_back(x);
    }

    vector<int> order;

    for (int i = 0; i < N; ++i)
        order.push_back(i);
    
    do {
        bool isAnswer = true;
        int val = 500;
        vector<int> candidate = order;

        for (int i = 0; i < N; ++i)
        {
            int idx = candidate[i];
            int plusValue = finessList[idx];
            val += plusValue;
            val -= K;

            if (val < 500)
            {
                isAnswer = false;
                break;
            }
        }

        if (isAnswer)
            ans += 1;

    } while (next_permutation(order.begin(), order.end()));

    cout << ans << "\n";
    
    return 0;
}