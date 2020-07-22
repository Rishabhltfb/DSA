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
    long int t, n, m;
    bool exist = false;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        set<int> setA;
        set<int> setB;
        int x;
        fo(i, 0, n)
        {
            cin >> x;
            setA.insert(x);
        }
        fo(i, 0, m)
        {
            cin >> x;
            setB.insert(x);
        }
        set<int>::iterator itr;
        bool setABig = true;
        if (setA.size() > setB.size())
        {
            setABig = true;
        }
        else
        {
            setABig = false;
        }

        bool found = false;
        if (setABig)
        {
            for (itr = setB.begin(); itr != setB.end(); ++itr)
            {
                if (setA.find(*itr) != setA.end())
                {
                    found = true;
                    cout << "YES" << endl;
                    cout << 1 << " " << *itr << endl;
                    break;
                }
            }
        }
        else
        {
            for (itr = setA.begin(); itr != setA.end(); ++itr)
            {
                if (setB.find(*itr) != setB.end())
                {
                    found = true;
                    cout << "YES" << endl;
                    cout << 1 << " " << *itr << endl;
                    break;
                }
            }
        }

        if (!found)
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
