#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


int N;
vector<bool> isPrime;
vector<int> nums;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> N;

    isPrime.resize(N + 5, true);

    for (int i = 2; i <= sqrt(N); ++i)
    {
        if (isPrime[i] == false) 
            continue;

        for (int j = i + i; j <= N; j+=i)
            isPrime[j] = false;
    }

    for (int i = 2; i < N+5; ++i)
        if (isPrime[i])
            nums.push_back(i);


    int st = 0, en = 0;
    int answer = 0, currSum= 0;
    int nSize = nums.size();

    while (st < nSize)
    {
        if (currSum > N || en == nSize) {
            currSum -= nums[st++];
        }
        else if (currSum < N) {
            currSum += nums[en++];
        }

        if (currSum == N) {
            answer += 1;
            currSum -= nums[st++];
        }
    }

    cout << answer << "\n";
    
    return 0;
}