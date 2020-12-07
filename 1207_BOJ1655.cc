#include <iostream>
#include <queue>
using namespace std;

int N;
priority_queue<int> maxheap;
priority_queue<int, vector<int>, greater<int>> minheap;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    
    for (int num,loop = 0; loop < N; ++loop)
    {
        cin >> num;

        //push number
        if (minheap.size() == maxheap.size())
        {
            maxheap.push(num);
        }
        else
        {
            minheap.push(num);
        }

        if (!maxheap.empty() && !minheap.empty())
        {
            if (maxheap.top() >= minheap.top())
            {
                int num1, num2;
                num1 = maxheap.top();
                maxheap.pop();

                num2 = minheap.top();
                minheap.pop();

                maxheap.push(num2);
                minheap.push(num1);
            }
        }

        if (!maxheap.empty())
        {
            cout << maxheap.top() << "\n";
        }        
    }

    return 0;
}