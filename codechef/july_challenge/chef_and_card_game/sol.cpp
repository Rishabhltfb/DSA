#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#define fo(i, n) for (int i = 0; i < n; i++)

using namespace std;

int numParser(unsigned long int x)
{
    unsigned long int temp;
    int sum = 0;
    while (x != 0)
    {
        temp = x % 10;
        x = x / 10;
        sum = sum + temp;
    }
    return sum;
}

int main()
{
    int T, N;
    cin >> T;
    fo(i, T)
    {
        cin >> N;
        unsigned long int chef[N], morty[N];
        int chefP = 0, mortyP = 0;
        fo(j, N)
        {
            cin >> chef[j];
            chef[j] = numParser(chef[j]);
            cin >> morty[j];
            morty[j] = numParser(morty[j]);
            if (chef[j] > morty[j])
            {
                chefP++;
            }
            else if (chef[j] < morty[j])
            {
                mortyP++;
            }
            else
            {
                chefP++;
                mortyP++;
            }
        }
        if (chefP > mortyP)
        {
            cout << "0 " << chefP;
        }
        else if (chefP < mortyP)
        {
            cout << "1 " << mortyP;
        }
        else
        {
            cout << "2 " << chefP;
        }
        if (i != T - 1)
        {
            cout << endl;
        }
    }
    return 0;
}
