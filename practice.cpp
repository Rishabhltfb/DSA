#include <iostream>
#include <bits/stdc++.h>
typedef long long int ll;
#define fo(i, a, n) for (ll i = a; i < n; i++)

using namespace std;
inline ll StringToInt(string a, int arr[])
{
	char x[1000];
	ll res;
	strcpy(x, a.c_str());
	fo(i, 0, 1000)
	{

		sscanf(x[i], "%lld", arr[i]);
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	char num[1000];
	int arr[1000];
	unsigned long long int product = 0;
	fo(i, 0, 1000)
	{
		cin >> num[i];
		arr[i] = num[i];
	}
	fo(j, 0, 5)
	{
		cout << arr[j] << endl;
	}
	unsigned long long int x = 1;
	// fo(i, 0, 1000)
	// {
	// 	x = 1;
	// 	fo(j, 0, 4)
	// 	{
	// 		x *= arr[j];
	// 	}
	// 	if (x > product)
	// 	{
	// 		product = x;
	// 	}
	// }
	cout << "-------- " << product << endl;

	return 0;
}
