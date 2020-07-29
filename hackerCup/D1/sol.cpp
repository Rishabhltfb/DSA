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
ll n = 1;
vl Cost(n + 1);
void solve(int t)
{
    ll m;
    cin >> n >> m;
    // cout << n << "    " << m << endl;
    ll min = 0, freq = 0;
    Cost.resize(n + 1);
    // ll pre[n + 1];
    deque<ll> preQ;

    fo(i, 1, n)
    {
        cin >> Cost[i];
        if (Cost[i] == 0)
        {
            Cost[i] = 1000000000000000;
        }
    }
    min = Cost[2];
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
        deque<ll>::iterator itr;
        stack<ll> stk;
        while (preQ.size())
        {
            if (preQ.back() == min)
            {
                freq++;
            }
            stk.push(preQ.back());
            preQ.pop_back();
        }
        while (stk.size())
        {
            preQ.push_back(stk.top());

            stk.pop();
        }
        // cout << "Min: & freq: " << min << " " << freq << endl;

        // itr = min_element(preQ.begin(), preQ.end());
        // min = *itr;
        // printf("min: %d\n", min);

        if (m < n / 2 || m < (n + 1) / 2)
        {

            fo(i, m + 2, n)
            {
                if (min < 1000000000000000)
                {
                    ans = Cost[i] + min;

                    preQ.push_back(ans);
                    if (preQ.front() == min && freq != 1 && m != 1)
                    {
                        freq--;

                        preQ.pop_front();
                        // itr = min_element(preQ.begin(), preQ.end());
                        // min = *itr;
                    }
                    else if (preQ.front() == min && freq == 1 && m != 1)
                    {
                        freq--;
                        preQ.pop_front();
                        itr = min_element(preQ.begin(), preQ.end());
                        min = *itr;
                        while (preQ.size())
                        {
                            if (preQ.back() == min)
                            {
                                freq++;
                            }
                            stk.push(preQ.back());
                            preQ.pop_back();
                        }
                        while (stk.size())
                        {
                            preQ.push_back(stk.top());

                            stk.pop();
                        }
                        // cout << "Min: & freq: " << min << " " << freq << endl;
                    }
                    else if (m == 1)
                    {
                        preQ.pop_front();
                        min = ans;
                    }
                    else
                    {
                        preQ.pop_front();
                        // preQ.push_back(ans);
                    }
                    // if (m == 1)
                    // {
                    //     min = ans;
                    // }
                    // else
                    // {
                    if (min != ans && ans < min)
                    {

                        min = ans;
                        while (preQ.size())
                        {
                            if (preQ.back() == min)
                            {
                                freq++;
                            }
                            stk.push(preQ.back());
                            preQ.pop_back();
                        }
                        while (stk.size())
                        {
                            preQ.push_back(stk.top());

                            stk.pop();
                        }
                        // cout << "Min: & freq: " << min << " " << freq << endl;
                    }
                    // }
                }
                else
                {
                    min = -1;
                    break;
                }
            }
        }
    }
    else
    {
        min = 0;
    }

    cout << "Case #" << t << ": " << min << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("running_on_fumes_chapter_1_input.txt", "r", stdin);
    // freopen("running_on_fumes_chapter_1_validation_input.txt", "r", stdin);
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