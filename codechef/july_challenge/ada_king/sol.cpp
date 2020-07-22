#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#define fo(i, n) for (int i = 0; i < n; i++)

using namespace std;

queue<int> Xqueue;
queue<int> Yqueue;
int xcord = 0, ycord = 0, occupied = 1;

void PrintArr(char *arr)
{
    fo(j, 8)
    {
        fo(k, 8)
        {
            cout << *((arr + j * 8) + k);
        }
        cout << endl;
    }
}
void checkAvail(char *arr, int N)
{
    // cout << "Checking for: " << xcord << " and " << ycord << endl;
    // cout << "Occupied: " << occupied << " N: " << N << endl;
    fo(j, 8)
    {
        fo(k, 8)
        {
            if (pow(j - xcord, 2.0) + pow(k - ycord, 2.0) <= 2 && occupied < N && *((arr + j * 8) + k) != '.' && *((arr + j * 8) + k) != 'O')
            {
                // cout << "Selected: . " << j << " " << k << endl;
                *((arr + j * 8) + k) = '.';
                Xqueue.push(j);
                Yqueue.push(k);
                occupied++;
            }
            else if (pow(j - xcord, 2.0) + pow(k - ycord, 2.0) <= 2 && occupied == N && *((arr + j * 8) + k) != '.' && *((arr + j * 8) + k) != 'O')
            {
                // cout << "Selected:X " << j << " " << k << endl;
                *((arr + j * 8) + k) = 'X';
            }
            else
            {
                // cout << " Not in range " << j << " " << k << endl;
            }
        }
    }
}

int main()
{
    int T, N;
    cin >> T;
    fo(i, T)
    {
        xcord = 0;
        ycord = 0;
        occupied = 1;
        cin >> N;
        char row[8][8];
        fo(j, 8)
        {
            fo(k, 8)
            {
                row[j][k] = 'W';
            }
        }
        row[xcord][ycord] = 'O';
        // PrintArr(&row[0][0]);
        Xqueue.push(xcord);
        Yqueue.push(ycord);
        while (!Xqueue.empty())
        {
            xcord = Xqueue.front();
            ycord = Yqueue.front();
            Xqueue.pop();
            Yqueue.pop();
            checkAvail(&row[0][0], N);
        }
        fo(j, 8)
        {
            fo(k, 8)
            {
                if (row[j][k] != '.' && row[j][k] != 'O' && row[j][k] != 'X')
                {
                    row[j][k] = '.';
                }
            }
        }
        PrintArr(&row[0][0]);
    }
    return 0;
}
