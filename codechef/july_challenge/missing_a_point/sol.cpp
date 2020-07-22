#include <iostream>
#include <bits/stdc++.h>
#define fo(i, n) for (long int i = 0; i < n; i++)

using namespace std;

int main()
{
    int T;
    long int N;
    cin >> T;
    fo(i, T)
    {
        cin >> N;
        long int xvec[4 * N - 1], yvec[4 * N - 1];
        long int xCord, yCord;
        fo(j, 4 * N - 1)
        {
            cin >> xvec[j];
            cin >> yvec[j];
        }
        sort(xvec, xvec + 4 * N - 1);
        sort(yvec, yvec + 4 * N - 1);
        int init = 0, remainder = 0;
        fo(j, 4 * N - 1)
        {
            while (xvec[init] == xvec[j])
            {
                j++;
            }
            remainder = (j - init) % 2;

            if (remainder != 0)
            {
                xCord = xvec[init];
                break;
            }
            init = j;
            j--;
        }

        init = 0;
        fo(j, 4 * N - 1)
        {
            while (yvec[init] == yvec[j])
            {
                j++;
            }
            remainder = (j - init) % 2;
            if (remainder != 0)
            {
                yCord = yvec[init];
                break;
            }
            init = j;
            j--;
        }

        cout << xCord << " " << yCord << endl;
    }
    return 0;
}
