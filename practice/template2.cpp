//...START BY DOING WHAT IS NECESSARY, THEN WHAT IS POSSIBLE AND SUDDENLY YOU ARE DOING THE IMPOSSIBLE...
#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

#define pb push_back
#define fo(i, a, b) for (int i = a; i < b; i++)
#define sqr(x) ((ll)(x) * (x))
#define p(a) cout << a << "\n"
#define fast_io              \
    ios::sync_with_stdio(0); \
    cin.tie(0);

inline string IntToString(ll a)
{
    char x[100];
    sprintf(x, "%lld", a);
    string s = x;
    return s;
}

inline ll StringToInt(string a)
{
    char x[100];
    ll res;
    strcpy(x, a.c_str());
    sscanf(x, "%lld", &res);
    return res;
}
bool prime(ll no)
{
    if (no < 3)
        return false;
    int factor = 0;
    for (int i = 2; i * i <= no; i++)
    {
        if (no % i == 0)
        {
            return false;
        }
    }
    return true;
}
long long lcm(ll a, ll b)
{
    return (a * b) / (__gcd(a, b));
}
/*.................................................................code starts here.........................................................*/

void solve()
{
    int n;
    cin >> n;
}

int main()
{
    fast_io int t;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}