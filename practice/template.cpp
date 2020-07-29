#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#define fo(i, a, n) for (long int i = a; i < n; i++)

using namespace std;

void PrintArr(long int *Arr, long int N)
{
    cout << "Printing:" << endl;
    fo(j, 0, N)
    {
        cout << *(Arr + j) << " ";
    }
}
void PrintVec(vector<long int> &vec)
{
    vector<long int>::iterator itr;
    cout << "Printing:" << endl;
    for (itr = vec.begin(); itr != vec.end(); ++itr)
    {
        cout << *itr << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    long int T, N;
    cin >> T;
    while (T--)
    {
        cin >> N;
    }
    return 0;
}
