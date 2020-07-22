#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#define fo(i, n) for (long int i = 0; i < n; i++)

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long int T, N;
    cin >> T;
    fo(i, T)
    {
        cin >> N;
        long int cost = 0, x, minimum;
        map<long int, long int> MapA;
        map<long int, long int> MapB;
        map<long int, long int>::iterator itr;
        map<long int, long int>::iterator itr2;

        // Creating MapA
        fo(j, N)
        {
            cin >> x;
            itr = MapA.find(x);
            if (itr == MapA.end())
            {
                MapA.insert(pair<long int, long int>(x, 1));
            }
            else
            {
                itr->second++;
            }
        }
        minimum = MapA.begin()->first;
        //Creating MapB
        fo(j, N)
        {

            cin >> x;
            minimum = min(x, minimum);
            itr = MapA.find(x);
            if (itr == MapA.end())
            {

                itr = MapB.find(x);
                if (itr == MapB.end())
                {
                    MapB.insert(pair<long int, long int>(x, 1));
                }
                else
                {
                    itr->second++;
                }
            }
            else
            {
                if (itr->second == 1)
                {
                    MapA.erase(itr);
                }
                else
                {
                    itr->second--;
                }
            }
        }
        for (itr = MapA.begin(); itr != MapA.end() && cost != -1; ++itr)
        {
            if (itr->second % 2 == 0)
            {

                itr->second = itr->second / 2;
            }
            else
            {
                cost = -1;
            }
        }
        for (itr = MapB.begin(); itr != MapB.end() && cost != -1; ++itr)
        {
            if (itr->second % 2 == 0)
            {

                itr->second = itr->second / 2;
            }
            else
            {
                cost = -1;
            }
        }

        //Cost Calculation
        if (cost != -1)
        {
            while (!MapA.empty())
            {
                itr = MapA.begin();
                itr2 = MapB.end();
                itr2--;
                cost = cost + min(min(itr->first, itr2->first), 2 * minimum);
                if (itr->second == 1)
                {
                    MapA.erase(itr);
                }
                else
                {
                    itr->second--;
                }
                if (itr2->second == 1)
                {

                    MapB.erase(itr2);
                }
                else
                {
                    itr2->second--;
                }
            }
        }

        cout << cost << endl;
    }
    return 0;
}
