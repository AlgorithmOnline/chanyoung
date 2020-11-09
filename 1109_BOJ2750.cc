#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int NMAX = 1005;
int arr[NMAX];
int tmp[NMAX];

void merge(int st, int en)
{
    int head, tail, idx, mid; 

    mid = (st + en) / 2;
    head = idx = st;
    tail = mid + 1;        

    while (head < tail)
    {
        if (arr[head] < arr[tail]) 
            tmp[idx++] = arr[head++];
        else
            tmp[idx++] = arr[tail++];
    }

    for (int i = head; i <= mid; ++i)
    {
        tmp[idx++] = arr[i];
    }

    for (int i = tail; i <= en; ++i)
    {
        tmp[idx++] = arr[i];
    }

    for (int i = st; i <= en; ++i)
        arr[i] = tmp[i];
}

void mergeSort(int st, int en)
{
    if (st >= en)
        return;
    else if (st + 1 == en)
    {
        if (arr[st] > arr[st+1])
            swap(arr[st], arr[st+1]);

        return;
    }
    else
    {
        int mid = (st + en) / 2;
        mergeSort(st,mid);
        mergeSort(mid+1,en);
        merge(st,en);
    }
}

int main(void) {

    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    mergeSort(0, n-1);

    for (int i = 0; i < n; ++i)
        cout << arr[i] << "\n";

    return 0;
}