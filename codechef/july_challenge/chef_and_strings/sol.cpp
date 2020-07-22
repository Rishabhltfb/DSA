#include <iostream>
#define fo(i, n) for (int i = 0; i < n; i++)

using namespace std;

int main()
{
    int T, N;
    cin >> T;
    fo(i, T)
    {
        cin >> N;
        long int totalSum = 0;
        long int arr[N];
        fo(j, N)
        {
            cin >> arr[j];
        }

        fo(j, N - 1)
        {
            long int temp = (arr[j + 1] - arr[j] - 1) >= 0 ? (arr[j + 1] - arr[j] - 1) : (arr[j] - arr[j + 1] - 1);
            totalSum = totalSum + temp;
        }
        cout << totalSum << endl;
    }
    return 0;
}
