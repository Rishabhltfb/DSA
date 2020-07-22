#include <iostream>
#include <bits/stdc++.h>
#define fo(i, n) for (long int i = 0; i < n; i++)

using namespace std;

// void PrintArr(long int *Arr, long int N)
// {
//     cout << "Printing:" << endl;
//     fo(j, N)
//     {
//         cout << *(Arr + j) << " ";
//     }
//     cout << endl;
// }

// bool checkPossibility(long int start, long int end, long int *heights)
// {
//     if (start > end)
//     {
//         for (int j = start - 2; j >= end - 1; j--)
//         {
//             if (*(heights + j) >= *(heights + start - 1))
//             {
//                 return false;
//             }
//         }
//     }
//     else if (start < end)
//     {
//         for (int j = start; j < end; j++)
//         {
//             if (*(heights + j) >= *(heights + start - 1))
//             {
//                 return false;
//             }
//         }
//     }

//     return true;
// }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long int Q, N, q, b, k, maxT = 0;
    long int minHeight, maxHeight;
    bool isPossible = true;
    cin >> N;
    cin >> Q;
    long int heights[N];
    long int tastes[N];
    fo(i, N)
    {
        cin >> heights[i];
    }
    fo(i, N)
    {
        cin >> tastes[i];
    }
    // PrintArr(&heights[0], N);
    // PrintArr(&tastes[0], N);

    fo(i, Q)
    {
        maxT = 0;
        cin >> q;
        cin >> b;
        cin >> k;
        if (q == 1)
        {
            tastes[b - 1] = k;
        }
        else
        {
            if (heights[b - 1] <= heights[k - 1])
            {
                maxT = -1;
            }
            else
            {
                minHeight = heights[k - 1];
                maxHeight = heights[b - 1];
                maxT = maxT + tastes[k - 1];
                maxT = maxT + tastes[b - 1];
                if (b > k)
                {
                    // cout << " minH and maxH : " << minHeight << " " << maxHeight << endl;
                    for (int j = k; j < b - 1 && maxT != -1; j++)
                    {
                        // cout << "Checking h = " << heights[j] << " maxT = " << maxT << endl;
                        if (heights[j] > minHeight && heights[j] < maxHeight)
                        {
                            minHeight = heights[j];
                            maxT = maxT + tastes[j];
                        }
                        else if (heights[j] >= maxHeight)
                        {
                            maxT = -1;
                        }
                    }
                    // cout << "!!!!!!!!!!" << endl;
                }
                else if (b < k)
                {
                    // cout << " minH and maxH : " << minHeight << " " << maxHeight << endl;
                    for (int j = k - 2; j > b - 1 && maxT != -1; j--)
                    {
                        // cout << "Checking h = " << heights[j] << " maxT = " << maxT << endl;
                        if (heights[j] > minHeight && heights[j] < maxHeight)
                        {
                            minHeight = heights[j];
                            maxT = maxT + tastes[j];
                        }
                        else if (heights[j] >= maxHeight)
                        {
                            maxT = -1;
                        }
                    }
                    // cout << " !!!!!!!!!" << endl;
                }
                else
                {
                    maxT = tastes[b - 1];
                }
            }

            cout << maxT << endl;
        }
    }

    return 0;
}
