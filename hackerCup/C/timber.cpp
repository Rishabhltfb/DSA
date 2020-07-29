#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void pairsort(vector<ll> a, vector<ll> b, ll n)
{
    pair<ll, ll> pairt[n];

    // Storing the respective array
    // elements in pairs.
    for (ll i = 0; i < n; i++)
    {
        pairt[i].first = a[i];
        pairt[i].second = b[i];
    }

    // Sorting the pair array.
    sort(pairt, pairt + n);

    // Modifying original arrays
    for (ll i = 0; i < n; i++)
    {
        a[i] = pairt[i].first;
        b[i] = pairt[i].second;
    }
}
int main()
{
    freopen("timber_input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll t;
    cin >> t;
    for (ll k = 1; k <= t; k++)
    {
        ll n, maximum = 0, origin, end;
        map<ll, ll> left, right;
        cin >> n;
        // vector<ll> p(n), h(n);
        // for (ll i = 0; i < n; i++)
        //     cin >> input[i].first >> input[i].second;
        // pair<ll, ll> pairt[n];

        // // Storing the respective array
        // // elements in pairs.
        // for (ll i = 0; i < n; i++)
        // {
        //     pairt[i].first = input[i].first;
        //     pairt[i].second = input[i].second;
        // }

        // // Sorting the pair array.
        // sort(pairt, pairt + n);

        // // Modifying original arrays
        // for (ll i = 0; i < n; i++)
        // {
        //     input[i].first = pairt[i].first;
        //     input[i].second = pairt[i].second;
        // }
        vector<pair<ll, ll>> input(n);
        for (ll i = 0; i < n; i++)
            cin >> input[i].first >> input[i].second;
        sort(input.begin(), input.end());
        for (ll i = 0; i < n; i++)
        {
            origin = input[i].first;
            end = input[i].first + input[i].second;
            right[end] = max(right[end], right[origin] + input[i].second);
        }
        for (ll i = n - 1; i >= 0; i--)
        {
            origin = input[i].first;
            end = input[i].first - input[i].second;
            left[end] = max(left[end], left[origin] + input[i].second);
        }
        for (auto i = right.begin(); i != right.end(); i++)
            maximum = max(maximum, right[i->first] + left[i->first]);
        for (auto i = left.begin(); i != left.end(); i++)
            maximum = max(maximum, right[i->first] + left[i->first]);
        cout << "Case #" << k << ": " << maximum << endl;
    }
}