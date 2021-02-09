#include "bits/stdc++.h"

using namespace std;

const int MOD = 1e9 + 7;
const int maxn = 1e6;

int n, x;
int c[maxn];

int main(int argc, char **argv) {
	cin >> n >> x;
	
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
		
	int dp[x + 1] = {0}; dp[0] = 1;
	
	for (int j = 0; j < n; j++) {
		for (int i = 1; i <= x; i++) {
			if (i - c[j] >= 0) {
				dp[i] = (dp[i] + dp[i - c[j]]) % MOD;
			}
		}
	}


	cout << dp[x] << endl;
	
	return 0;
}
