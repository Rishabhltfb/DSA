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

float dist(ll y2, ll y1, ll x2, ll x1)
{
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}
void solve()
{
	// int n;
	// cin >> n;
	ll x1, x2, y1, y2, minx, miny, maxx, maxy;
	ll points = 0;
	bool isdone = false;
	cin >> x1 >> y1 >> x2 >> y2;
	bool isx1small = x1 <= x2 ? true : false;
	bool increasing = y2 >= y1 ? true : false;
	float totaldis = dist(y2, y1, x2, x1);
	if (increasing && isx1small)
	{
		fo(i, x1, x2 + 1)
		{
			fo(j, y1, y2 + 1)
			{
				if ((j - y1) * (x2 - x1) == (i - x1) * (y2 - y1))
				{
					if (i == min(x1, x2) && j == y1)
					{
					}
					else
					{

						float pdist = dist(j, y1, i, min(x1, x2));
						printf("point x: %d,   y: %d\n", i, j);
						printf("point xstart : %d,   ystart : %d\n", min(x1, x2), j);
						printf("tDist: %f,   pdist: %f\n", totaldis, pdist);

						float k = totaldis / pdist;
						cout << "k: " << k << endl;

						// if (totaldis == pdist * k)
						// {
						// 	cout << k - 1 << endl;
						// }
						// else
						// {

						// 	cout << k << endl;
						// }
						i = max(x1, x2);
						j = y2;
						isdone = true;
					}
				}
			}
		}
	}
	else
	{
		fo(i, min(x1, x2), max(x1, x2) + 1)
		{
			fo(j, y2, y1 + 1)
			{
				if ((j - y1) * (x2 - x1) == (i - x1) * (y2 - y1))
				{
					if (i == min(x1, x2) && j == y2)
					{
					}
					else
					{

						float pdist = dist(j, y2, i, min(x1, x2));
						printf("point x: %d,   y: %d\n", i, j);
						printf("tDist: %f,   pdist: %f\n", totaldis, pdist);
						float k = totaldis / pdist;
						cout << "k: " << k << endl;
						// if (totaldis == pdist * k)
						// {
						// 	cout << k - 1 << endl;
						// }
						// else
						// {

						// 	cout << k << endl;
						// }
						i = max(x1, x2);
						j = y1;
						isdone = true;
					}
				}
			}
		}
	}
	if (!isdone)
	{

		cout << points << endl;
	}
}

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