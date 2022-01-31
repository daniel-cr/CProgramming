#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <random>
#include <ctime>
#include <string>
#include <iomanip>
#include <set>
#include <map>
#include <queue>
#include <stack>

using namespace std;

typedef pair<int, int> pii;
typedef long long li;

const int MOD = 1e9 + 7;

int arr[101];

int main() {
    
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	
	double k;
	double ans = 0.0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			double exp = arr[i] * arr[j];
			if (arr[j] <= arr[i]) {
				k = arr[j] * (arr[j] - 1) / 2.0;
			} else {
				k = exp - arr[i] * (arr[i] - 1) / 2.0 - arr[i];
				//k = arr[i] * (arr[i] - 1) / 2.0 + (arr[j] - arr[i]) * arr[i];
			}
			ans += k / exp;
		}
	}
	cout << fixed << setprecision(6) << ans << '\n';

	return 0;
}