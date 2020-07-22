// #include <iostream>
// #include <bits/stdc++.h>
// #define fo(i, n) for (long int i = 1; i < n; i++)

// using namespace std;

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     long int Q, N, q, b, k, maxT = 0;
//     long int minHeight, maxHeight, maxIndex = 0, minIndex = -1, currMin;
//     map<long int, long int> mapA;
//     map<long int, long int>::iterator itr;
//     map<long int, long int>::iterator itrend;
//     cin >> N;
//     cin >> Q;
//     long int heights[N + 1];
//     long int tastes[N + 1];
//     long int tree[N + 1];
//     fo(i, N + 1)
//     {
//         cin >> heights[i];
//         maxIndex = heights[maxIndex] < heights[i] ? maxIndex : i;
//     }
//     if (maxIndex >= N / 2)
//     {
//         long int j = 1;
//         while (minIndex == -1 && j < maxIndex)
//         {
//             if (heights[j] < heights[j + 1])
//             {
//                 minIndex = j;
//             }
//             j++;
//         }
//         currMin = heights[minIndex];
//         mapA.insert(pair<long int, long int>(heights[minIndex], minIndex));
//         fo(i, N + 1)
//         {
//             cin >> tastes[i];
//             if (i < maxIndex && i > minIndex && heights[i] > currMin)
//             {
//                 mapA.insert(pair<long int, pair<long int, long int>>(heights[i], pair<long int, long int>(i, tastes[i])));
//                 currMin = heights[i];
//             }
//         }
//         mapA.insert(pair<long int, pair<long int, long int>>(heights[maxIndex], pair<long int, long int>(maxIndex, tastes[maxIndex])));
//     }
//     else
//     {
//     }

//     fo(i, Q + 1)
//     {
//         maxT = 0;
//         cin >> q;
//         cin >> b;
//         cin >> k;
//         if (q == 1)
//         {
//             tastes[b] = k;
//         }
//         else
//         {
//             if (heights[b] <= heights[k])
//             {
//                 maxT = -1;
//             }
//             else
//             {
//                 if (b > k)
//                 {
//                 }
//                 else if (b < k)
//                 {
//                 }
//                 else
//                 {
//                     maxT = tastes[b];
//                 }
//             }

//             cout << maxT << endl;
//         }
//     }

//     return 0;
// }
