#include "bits/stdc++.h"

using namespace std;

const int MOD = 1e9 + 7;
const int maxn = 1e6;

int main(int argc, char **argv) {
	int n, x; cin >> n >> x;
	
	int c[maxn];
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	
	//cout << "0 : 1" << endl;
	int dp[x + 1] = {0}; dp[0] = 1;
	for (int i = 1; i <= x; i++) {
		dp[i] = 0;
		for (int j = 0; j < n; j++) {
			if (i - c[j] >= 0) {
				dp[i] = (dp[i] + dp[i - c[j]]) % MOD;
			}
		}
		//cout << i << " : " << dp[i] << endl;
	}
	cout << dp[x] << endl;
	
	return 0;
}
