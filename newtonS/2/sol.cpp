//...START BY DOING WHAT IS NECESSARY, THEN WHAT IS POSSIBLE AND SUDDENLY YOU ARE DOING THE IMPOSSIBLE...
#include <iostream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

#define pb push_back
#define fo(i, a, b) for (int i = a; i <= b; i++)
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

bool isPerfectSquare(long double x)
{
    // Find floating point value of
    // square root of x.
    long double sr = sqrt(x);

    // If square root is an integer
    return ((sr - floor(sr)) == 0);
}

int height(ll node)
{
    ll h = -1;
    while (node)
    {
        node /= 2;
        h++;
    }
    return h;
}

int range(ll node){

}

void solve()
{
    ll n;
    ll mod = 1000000007;
    ll ans;
    vector<vector<ll>> tree(101);
    cin >> n;
    ll nodes[n + 1];
    fo(i, 1, n)
    {
        cin >> nodes[i];
    }
    fo(i, 1, 101)
    {
        tree[i - 1] = vector<ll>(i);
    }
    
    fo(i, 1, tree.size())
    {
        fo(j, 1, tree[i].size())
        {
            tree[i][j] = 1;
        }
    }

    cout << ans % mod << endl;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}