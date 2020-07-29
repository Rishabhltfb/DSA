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

ll dist(ll y2, ll y1, ll x2, ll x1)
{
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}
void solve()
{
	// int n;
	// cin >> n;
	ll x1, x2, y1, y2, minx, miny, maxx, maxy;
	ll points = 0;
	cin >> x1 >> y1 >> x2 >> y2;
	bool increasing = y2 > y1 ? true : false;
	ll totaldis = dist(y2, y1, x2, x1);
	if (increasing)
	{
		fo(i, min(x1, x2) + 1, max(x1, x2))
		{
			fo(j, y1 + 1, y2)
			{
				if ((j - y1) * (x2 - x1) == (i - x1) * (y2 - y1))
				{
					cout << totaldis / dist(j, y1, i, min(x1, y1)) << endl;
					i = max(x1, y1);
					j = y2;
				}
			}
		}
	}
	else
	{
		fo(i, min(x1, x2) + 1, max(x1, x2))
		{
			fo(j, y2 + 1, y1)
			{
				if ((j - y1) * (x2 - x1) == (i - x1) * (y2 - y1))
				{
					cout << totaldis / dist(j, y2, i, min(x1, y1)) << endl;
					i = max(x1, x2);
					j = y1;
				}
			}
		}
	}
	// cout << points << endl;
}
// void solve()
// {
// 	// int n;
// 	// cin >> n;
// 	ll x1, x2, y1, y2, minx, miny, maxx, maxy;
// 	ll points = 0;
// 	cin >> x1 >> y1 >> x2 >> y2;
// 	minx = min(x1, x2);
// 	miny = min(y1, y2);
// 	maxx = max(x1, x2);
// 	maxy = max(y1, y2);
// 	ll a, b;
// 	bool flag = true;
// 	if (miny != y1)
// 	{
// 		flag = false;
// 	}
// 	fo(i, minx + 1, maxx)
// 	{
// 		fo(j, miny + 1, maxy)
// 		{
// 			if ((j - y1) * (x2 - x1) == (i - x1) * (y2 - y1))
// 			{
// 				// printf("x: %d \ty: %d\n", i, j);
// 				a = i - minx;
// 				if (flag)
// 				{

// 					b = j - miny;
// 				}
// 				else
// 				{
// 					b = j - maxy;
// 				}
// 				points++;
// 				i = maxx;
// 				j = maxy;
// 			}
// 		}
// 	}
// 	ll x = minx + a + a, y = miny + b + b;
// 	if (flag)
// 	{

// 		while (x < maxx && y < maxy)
// 		{
// 			points++;
// 			x += a;
// 			y += b;
// 		}
// 	}
// 	else
// 	{
// 		while (x < maxx && y > miny)
// 		{
// 			points++;
// 			x += a;
// 			y += b;
// 		}
// 	}
// 	cout << points << endl;
// }

int main()
{
	fast_io int t;

	// freopen("pinput.txt", "r", stdin);
	// freopen("poutput.txt", "w", stdout);
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}