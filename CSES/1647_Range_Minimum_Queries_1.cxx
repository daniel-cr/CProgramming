#include "bits/stdc++.h"

using namespace std;
#define ar array
#define ll long long

const int MOD = 1e9 + 7;

const int mxN = 2e5;
const int K = log2(mxN) + 1;

ll st[K][mxN];

int main(int argc, char **argv) {
	int n, q; cin >> n >> q;

	for (int i = 0; i < n; i++) {
		cin >> st[0][i];
	}
	
	for (int i = 1; i < K ; i++) {
		for (int j = 0; j + (1 << i) <= n; j++) {
			st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
		}
	}
	
	for (int i = 0, left = 0, right = 0; i < q; i++) {
		cin >> left >> right; left--, right--;
		
		ll min_v = 1e18;
		for (int j = K; j >= 0; j--) {
			if ((1 << j) <= right - left + 1) {
				min_v = min(min_v, st[j][left]);
				left += (1 << j);
			}
		}
		cout << min_v << endl;
	}
	
	return 0;
}

