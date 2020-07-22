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
        long int cost = 0, x, minimum, foundcount = 0;
        map<long int, long int> MapA;
        map<long int, long int> MapB;
        map<long int, long int>::iterator itr;
        map<long int, long int>::iterator itr2;
        map<long int, long int>::iterator tempItr;
        long int foundBoth[N];

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
        //Creating MapB
        fo(j, N)
        {
            cin >> x;
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

        minimum = min(MapA.begin()->first, MapB.begin()->first);
        bool eraseA = false;

        //Updating MapA and MapB
        for (itr = MapA.begin(); itr != MapA.end() && cost != -1; ++itr)
        {
            if (eraseA)
            {
                MapA.erase(tempItr);
                eraseA = false;
            }
            itr2 = MapB.find(itr->first);
            if (itr2 == MapB.end())
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
            else
            {
                foundBoth[foundcount] = itr->first;
                foundcount++;
                if ((itr->second + itr2->second) % 2 == 0)
                {

                    if (itr->second > itr2->second)
                    {
                        itr->second = (itr->second - itr2->second) / 2;
                        MapB.erase(itr2);
                    }
                    else if (itr->second < itr2->second)
                    {
                        itr2->second = (itr2->second - itr->second) / 2;
                        eraseA = true;
                        tempItr = itr;
                    }
                    else
                    {
                        MapB.erase(itr2);
                        eraseA = true;
                        tempItr = itr;
                    }
                }
                else
                {
                    cost = -1;
                }
            }
        }
        if (eraseA)
        {
            MapA.erase(tempItr);
            eraseA = false;
        }
        x = 0;
        //Completing MapB
        for (itr = MapB.begin(); itr != MapB.end() && cost != -1; ++itr)
        {
            if (find(foundBoth + x, foundBoth + foundcount, itr->first) == foundBoth + foundcount)
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
            else
            {
                x++;
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
