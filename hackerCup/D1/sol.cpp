//...START BY DOING WHAT IS NECESSARY, THEN WHAT IS POSSIBLE AND SUDDENLY YOU ARE DOING THE IMPOSSIBLE...
#include <iostream>
#include <string>
#include <bits/stdc++.h>
// #include <vector>
// #include <set>
// #include <map>
// #include <stack>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vl;
#define pb push_back
#define fo(i, a, b) for (int i = a; i < b; i++)
#define sqr(x) ((ll)(x) * (x))
#define p(a) cout << a << "\n"
#define fast_io              \
    ios::sync_with_stdio(0); \
    cin.tie(0);

/*.................................................................code starts here.........................................................*/

void solve(int t)
{
    ll n, m;
    cin >> n;
    cin >> m;
    ull total = 0;
    ull Cost[n];
    fo(i, 0, n)
    {
        cin >> Cost[i];
    }

    cout << "Case #" << t << ": " << total << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    fo(i, 1, t + 1)
    {
        solve(i);
    }
    return 0;
}