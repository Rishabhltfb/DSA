// / C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define m 998244353

set<string, long int>::value_compare() setA;
#define fo(i, n) for (int i = 1; i < n; i++)

// Function to return the GCD of given numbers
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

// Recursive function to return (x ^ n) % m
ll modexp(ll x, ll n)
{
    if (n == 0)
    {
        return 1;
    }
    else if (n % 2 == 0)
    {
        return modexp((x * x) % m, n / 2);
    }
    else
    {
        return (x * modexp((x * x) % m, (n - 1) / 2) % m);
    }
}

// Function to return the fraction modulo mod
ll getFractionModulo(ll a, ll b)
{
    ll c = gcd(a, b);

    a = a / c;
    b = b / c;

    // (b ^ m-2) % m
    ll d = modexp(b, m - 2);

    // Final answer
    ll ans = ((a % m) * (d % m)) % m;

    return ans;
}

long int countFreq(string &pat, string &txt)
{
    long int M = pat.length();
    long int N = txt.length();
    long int res = 0;

    /* A loop to slide pat[] one by one */
    for (long int i = 0; i <= N - M; i++)
    {
        /* For current index i, check for  
           pattern match */
        long int j;
        for (j = 0; j < M; j++)
            if (txt[i + j] != pat[j])
                break;

        // if pat[0...M-1] = txt[i, i+1, ...i+M-1]
        if (j == M)
        {
            res++;
            j = 0;
        }
    }
    return res;
}

// Function to print all sub strings
void subString(string S, int n)
{
    long int freq;
    // Pick starting point
    for (long int len = 1; len <= n; len++)
    {
        // Pick ending polong int
        for (long int i = 0; i <= n - len; i++)
        {
            //  Prlong int characters from current
            // starting polong int to current ending
            // polong int.
            long int j = i + len - 1;
            string Stemp = "";
            for (long int k = i; k <= j; k++)
            {

                // Str.insert(S[k]);
                Stemp = Stemp + S[k];
                cout
                    << S[k];
            }
            freq = countFreq(Stemp, S);
            setA.insert(pair<string, long int>(Stemp, freq));
            cout << endl;
        }
    }
}

// Driver code
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long int T;
    long int W[27];
    string S;
    cin >> T;
    fo(i, T + 1)
    {
        cin >> S;
        fo(j, 27)
        {
            cin >> W[j];
        }

        subString(S, S.length());

        // ll P = 15, Q = 6;
        // cout << getFractionModulo(P, Q) << endl;
    }

    return 0;
}