//...START BY DOING WHAT IS NECESSARY, THEN WHAT IS POSSIBLE AND SUDDENLY YOU ARE DOING THE IMPOSSIBLE...
#include <bits/stdc++.h>
using namespace std;
#define FAST_IO                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define pb push_back
typedef long long ll;
#define endl '\n'
#define M 1000000007
bool comp(int x, int y)
{
    return x > y;
}

/*..............................code starts here........................*/

const int mx = 1000001, mod = 1e9 + 7;

//int n, t;
int prime[mx];
//seive of erasthanose

void mark_primes()
{
    memset(prime, -1, sizeof prime);

    for (int i = 2; i <= 1000001; ++i)
    {
        if (prime[i] == -1)
        {
            prime[i] = 1;
            for (int j = i + i; j <= 1000001; j += i)
                prime[j] = 0;
        }
    }
}

//to find no of power of that prime no in factorial
ll findPowerPrime(ll fact, ll p)
{
    int res = 0;
    while (fact > 0)
    {
        res += fact / p;
        fact /= p;
    }

    return res;
}

//to calcuatel power in O(log(n))
ll power(ll no, ll p)
{
    if (p == 1)
        return no;
    if (p == 0)
        return 1;
    ll q = power(no, p / 2) % M;
    q = (q * q) % M;
    if (p % 2 != 0)
        q = (q * no) % M;
    return q % M;
}
int main()
{
    FAST_IO;
    int t = 1;
    //cin >> t;
    ll m, n;
    string a, b;
    mark_primes();
    while (t--)
    {
        cin >> n;
        ll pro = 1;

        // cout << pro << endl;
        vector<pair<int, int>> vec;
        for (int i = 2; i <= n; i++)
        {
            if (prime[i])
            {
                vec.pb(make_pair(i, findPowerPrime(n, i)));
            }
        }

        ll p = 1;
        for (auto j : vec)
        {
            if (j.second % 2 == 1)
                j.second -= 1;
            p = (p * power(j.first, j.second)) % M;
        }
        cout << p << endl;
    }
}

//remarks..
/*
1.seive of erasthanos till n=10000
2.lcm
3.power function..dont forget to apply mod if needed
4.int to string and vice-versa
5.checking the prime no
6.pascal triangle implementation
*/