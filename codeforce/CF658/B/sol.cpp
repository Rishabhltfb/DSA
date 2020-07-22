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

int occurCount(int Arr[], int index, int size)
{
    int occur = 1;
    fo(i, index, size)
    {
        if (Arr[index + 1] == 1)
        {
            occur++;
        }
        else
        {
            break;
        }
    }
    return occur;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long int t, n;
    bool exist = false;
    cin >> t;
    while (t--)
    {
        cin >> n;
        bool allone = true;
        bool startOne = false;
        bool FControl = true;
        bool SControl = true;
        long int a[n];
        fo(i, 0, n)
        {
            cin >> a[i];
            if (a[i] != 1)
            {
                allone = false;
            }
        }
        if (allone)
        {
            n % 2 == 0 ? cout << "Second" : cout << "First";
            cout << endl;
        }
        else
        {
            startOne = a[0] == 1 ? true : false;
            if (startOne)
            {
                int occur = 1;
                for (int j = 1; j < n; j++)
                {
                    if (a[j] == 1)
                    {
                        occur++;
                    }
                    else
                    {
                        break;
                    }
                }
                if (occur % 2 == 0)
                {
                    cout << "First" << endl;
                }
                else
                {

                    cout << "Second" << endl;
                }
            }
            else
            {
                cout << "First" << endl;
            }
        }
    }
    return 0;
}
