#include <iostream>
#include <bits/stdc++.h>
#define fo(i, n) for (long int i = 0; i < n; i++)

using namespace std;

int main()
{
    long int T, N;
    cin >> T;
    fo(i, T)
    {
        cin >> N;
        long int cost = 0, x, minimum;
        map<long int, long int> MapA;
        map<long int, long int> MapB;
        map<long int, long int> MapAA;
        map<long int, long int> MapBB;
        map<long int, long int>::iterator itr;
        map<long int, long int>::iterator itr2;
        vector<long int> foundBoth;
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
        minimum = MapA.begin()->first < MapB.begin()->first ? MapA.begin()->first : MapB.begin()->first;
        bool isMapA = MapA.begin()->first < MapB.begin()->first ? true : false;
        //Creating MapAA and MapBB
        for (itr = MapA.begin(); itr != MapA.end() && cost != -1; ++itr)
        {
            itr2 = MapB.find(itr->first);
            if (itr2 == MapB.end())
            {
                if (itr->second % 2 == 0)
                {

                    MapAA.insert(pair<long int, long int>(itr->first, itr->second / 2));
                }
                else
                {
                    cost = -1;
                }
            }
            else
            {
                foundBoth.push_back(itr->first);
                if ((itr->second + itr2->second) % 2 == 0)
                {

                    if (itr->second > itr2->second)
                    {
                        MapAA.insert(pair<long int, long int>(itr->first, (itr->second - itr2->second) / 2));
                    }
                    else if (itr->second < itr2->second)
                    {
                        MapBB.insert(pair<long int, long int>(itr->first, (itr2->second - itr->second) / 2));
                    }
                }
                else
                {
                    cost = -1;
                }
            }
        }

        //Completing MapBB
        for (itr = MapB.begin(); itr != MapB.end() && cost != -1; ++itr)
        {
            if (find(foundBoth.begin(), foundBoth.end(), itr->first) == foundBoth.end())
            {
                if (itr->second % 2 == 0)
                {
                    MapBB.insert(pair<long int, long int>(itr->first, itr->second / 2));
                }
                else
                {
                    cost = -1;
                }
            }
        }

        //Cost Calculation
        while (!MapAA.empty())
        {
            long int topEleAA = MapAA.begin()->first;
            long int topEleBB = MapBB.begin()->first;
            if (topEleAA < topEleBB)
            {
                if (topEleAA > 2 * minimum)
                {
                    cost = cost + 2 * minimum;

                    if (MapAA.begin()->second == 1)
                    {
                        MapAA.erase(MapAA.begin());
                    }
                    else
                    {
                        MapAA.begin()->second--;
                    }
                    itr = MapBB.end();
                    itr--;
                    if (itr->second == 1)
                    {
                        MapBB.erase(itr);
                    }
                    else
                    {
                        itr->second--;
                    }
                }
                else
                {
                    if (MapAA.begin()->second == 1)
                    {
                        MapAA.erase(MapAA.begin());
                    }
                    else
                    {
                        MapAA.begin()->second--;
                    }
                    itr = MapBB.end();
                    itr--;
                    if (itr->second == 1)
                    {
                        MapBB.erase(itr);
                    }
                    else
                    {
                        itr->second--;
                    }
                    cost = cost + topEleAA;
                }
            }
            else
            {
                if (topEleBB > 2 * minimum)
                {

                    if (MapAA.begin()->second == 1)
                    {
                        MapAA.erase(MapAA.begin());
                    }
                    else
                    {
                        MapAA.begin()->second--;
                    }
                    itr = MapBB.end();
                    itr--;
                    if (itr->second == 1)
                    {
                        MapBB.erase(itr);
                    }
                    else
                    {
                        itr->second--;
                    }
                    cost = cost + 2 * minimum;
                }
                else
                {
                    if (MapBB.begin()->second == 1)
                    {
                        MapBB.erase(MapBB.begin());
                    }
                    else
                    {
                        MapBB.begin()->second--;
                    }
                    itr = MapAA.end();
                    itr--;
                    if (itr->second == 1)
                    {
                        MapAA.erase(itr);
                    }
                    else
                    {
                        itr->second--;
                    }
                    cost = cost + topEleBB;
                }
            }
        }

        cout << cost << endl;
    }
    return 0;
}
