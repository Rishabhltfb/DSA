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
#define fo(i, a, b) for (int i = a; i <= b; i++)
#define sqr(x) ((ll)(x) * (x))
#define p(a) cout << a << "\n"
#define fast_io              \
    ios::sync_with_stdio(0); \
    cin.tie(0);

/*.................................................................code starts here.........................................................*/

void solve(int t)
{
    ll n, m;
    cin >> n >> m;
    ll min = 0;
    ll Cost[n + 1];
    ll pre[n + 1];
    deque<ll> preQ;

    fo(i, 1, n)
    {
        cin >> Cost[i];
        if (Cost[i] == 0)
        {
            Cost[i] = 1000000000000000;
        }
    }
    Cost[1] = 0;
    Cost[n] = 0;
    ll ans;

    // printf("n: %d\t m: %d\n", n, m);
    if (m < n - 1)
    {
        fo(j, 2, m + 1)
        {
            preQ.push_back(Cost[j]);
            min = min < Cost[j] ? min : Cost[j];
        }
        deque<ll>::iterator itr = min_element(preQ.begin(), preQ.end());
        min = *itr;
        fo(i, m + 2, n)
        {
            // printf("iteration:%d   deque size:  %d,\tmin: %d\n", i, preQ.size(), min);
            if (Cost[i] != 0 && i != n)
            {
                ans = min + Cost[i];
                if (preQ.size() >= m)
                {
                    if (min == preQ.front() && preQ.size() != 1)
                    {
                        preQ.pop_front();
                        //Calculate new min
                        itr = min_element(preQ.begin(), preQ.end());
                        min = *itr;
                    }
                    else if (preQ.size() == 1)
                    {
                        min = 1000000000;
                        preQ.pop_front();
                    }
                    else
                    {
                        preQ.pop_front();
                    }
                    preQ.push_back(ans);
                }
                else
                {
                    preQ.push_back(ans);
                }

                min = min < ans ? min : ans;
            }
            else if (min == 1000000000)
            {
                min = -1;
                break;
            }
            else if (i == n)
            {
                break;
            }
            else
            {
                if (preQ.size() >= m)
                {
                    if (min == preQ.front())
                    {
                        preQ.pop_front();
                        //Calculate new min
                        deque<ll>::iterator itr = min_element(preQ.begin(), preQ.end());
                        min = *itr;
                    }
                    else
                    {
                        preQ.pop_front();
                    }
                    preQ.push_back(1000000000);
                }
            }
        }
    }

    cout << "Case #" << t << ": " << min << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("running_on_fumes_chapter_1_validation_input.txt", "r", stdin);
    // freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    fo(i, 1, t)
    {
        solve(i);
    }
    return 0;
}