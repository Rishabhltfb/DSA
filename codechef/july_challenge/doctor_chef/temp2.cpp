#include <iostream>
#include <bits/stdc++.h>
#define fo(i, n) for (long int i = 0; i < n; i++)

using namespace std;

vector<pair<long int, long int>>::iterator IsBefore(long int x, vector<pair<long int, long int>>::iterator begin, vector<pair<long int, long int>>::iterator end)
{
    vector<pair<long int, long int>>::iterator itr = lower_bound(begin, end, pair<long int, long int>(x, x));
    if (itr != end)
    {
        if (itr->first != x && itr != begin)
        {
            itr--;
        }
    }
    return itr;
}

void PrintVec(vector<pair<long int, long int>>::iterator itr, vector<pair<long int, long int>>::iterator end)
{
    // cout << "Printing:" << endl;
    for (itr; itr != end; ++itr)
    {
        // cout << itr->first << "   " << itr->second << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long int T, N, x, days = 0, y;
    cin >> T;
    fo(i, T)
    {
        days = 0;
        cin >> N;
        cin >> x;
        vector<pair<long int, long int>> CP;
        vector<pair<long int, long int>>::iterator itr;
        fo(j, N)
        {
            cin >> y;
            CP.push_back(pair<long int, long int>(y, y));
        }
        sort(CP.begin(), CP.end());
        PrintVec(CP.begin(), CP.end());
        while (!CP.empty())
        {
            // cout << "Inside while: x = " << x << endl;
            if (x < CP.front().first)
            {
                // cout << "Less than all: " << endl;
                CP.back().first = min((CP.back().first - x) * 2, CP.back().second);
                ;
                x = 2 * x;
                days++;
                sort(CP.begin(), CP.end());
            }
            else if (x >= CP.back().first)
            {
                // cout << "x is greater than all" << endl;
                days = days + CP.size();
                break;
            }
            else
            {
                itr = IsBefore(x, CP.begin(), CP.end());
                // cout << "lower bound is : " << itr->first << endl;
                float y = (itr + 1)->first;
                if (itr->first == x || 2 * itr->first >= (y) / 2)
                {
                    // cout << " inside else: " << itr->first << endl;

                    x = 2 * itr->first;
                    CP.erase(itr);
                }
                else
                {

                    // cout << "In middle but rate low: " << endl;
                    CP.back().first = min((CP.back().first - x) * 2, CP.back().second);
                    ;
                    x = 2 * x;
                    sort(CP.begin(), CP.end());
                }

                days++;
            }
        }
        cout << days << endl;
    }
    return 0;
}
