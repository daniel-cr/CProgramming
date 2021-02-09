#include "bits/stdc++.h"

using namespace std;

const int MOD = 1e9 + 7;

int main(int argc, char **argv) {
	int n; cin >> n;
	int dp[n + 1] = {0}; dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 6 && i - j >= 0; j++) {
			dp[i] = (dp[i] + dp[i - j]) % MOD;
		}
	}
	cout << dp[n] << endl;
	
	return 0;
}

