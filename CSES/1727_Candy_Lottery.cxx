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

// Expected maximum value of 
// n samples with Uniform(1, k) i.i.d

using namespace std;

typedef pair<int, int> pii;
typedef long long li;

const int MOD = 1e9 + 7;

const int MXN = 100 + 1;
double a[MXN];

int main() {
    
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k; cin >> n >> k;

	for (int i = 1; i <= k; i++)
	{
		a[i] = 1;
		for (int j = 0; j < n; j++)
		{
			a[i] *= (double) i / k;
		}
	}

	double ans = 0.0;
	for (int i = k; i; i--)
	{
		ans += i * (a[i] - a[i - 1]);
	}

	cout << fixed << setprecision(6) << ans << '\n';
	
	return 0;
}