#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#define fo(i, n) for (int i = 0; i < n; i++)

using namespace std;

void PrintArr(long int *Arr, long int N)
{
    cout << "Printing:" << endl;
    fo(j, N)
    {
        cout << *(Arr + j) << " ";
    }
}
void PrintVec(vector<long int>::iterator itr, vector<long int>::iterator end)
{
    cout << "Printing:" << endl;
    for (itr; itr != end; ++itr)
    {
        cout << *itr << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T, N;
    cin >> T;
    fo(i, T)
    {
    }
    return 0;
}
