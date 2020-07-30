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

float A, B, G;
float L;
ll Q;

void checkpoint(float *time, float *u, float *dist1, int type, float dist2)
{
    float v;
    if (type == 1)
    {
        v = sqrt(*u * (*u) - 2 * B * (dist2 - *dist1));
        *time += (v - *u) / B;
    }
    else if (type == 2)
    {

        v = sqrt(*u * (*u) + 2 * A * (dist2 - *dist1));
        *time += (v - *u) / A;
    }
    else
    {

        v = sqrt(*u * (*u) - 2 * G * (dist2 - *dist1));
        *time += (v - *u) / G;
    }
    *dist1 = dist2;
    *u = v;
}

void solve()
{
    float time = 0.0;
    float dist1 = 0, dist2;
    int type;
    float u = 0;
    float v;
    cin >> A, B, G;
    cin >> L, Q;
    fo(i, 0, Q)
    {
        cin >> type >> dist2;
        checkpoint(&time, &u, &dist1, type, dist2);
    }
    checkpoint(&time, &u, &dist1, type, L);
    cout << time << endl;
}

int main()
{
    fast_io int t;

    freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}