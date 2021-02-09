#include "bits/stdc++.h"

using namespace std;
const int max_f = 10000000;
const int maxn = 1e6;
int c[maxn];
int n, x;

int main(int argc, char **argv) {
	cin >> n >> x;

	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}

	int dp[x + 1];
	dp[0] = 0;
	
	for (int i = 1; i <= x; i++) {
		dp[i] = max_f;
		for (int j = 0; j < n; j++) {
			int val = i - c[j];
			if (val >= 0) {
				dp[i] = min(dp[i], dp[val]);
			}
		}
		dp[i]++;
	}
	if (dp[x] == max_f + 1 ) {
		cout << -1 << endl;
	} else {
		cout << dp[x] << endl;
	}
	return 0;
}

