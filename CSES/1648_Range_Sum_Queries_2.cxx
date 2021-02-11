#include "bits/stdc++.h"

using namespace std;
#define ar array
#define ll long long

const int MOD = 1e9 + 7;

const int mxN = 2e5;

int n, q;
ll segment_tree[mxN * 2 + 1];

ll sum_stree(int a, int b) {
	a += n,  b += n;
	ll s = 0;
	while (a<=b) {
		if (a%2 == 1) s+= segment_tree[a++];
		if (b%2 == 0) s+= segment_tree[b--];
		a /= 2; b /= 2;
	}
	return s;
}

int main(int argc, char **argv) {
	cin >> n >> q;

	for (int i = n; i < 2 * n; i++) {
		cin >> segment_tree[i];
	}
	for (int k = n - 1; k > 0; k--) {
		segment_tree[k] = segment_tree[2 * k] + segment_tree[2 * k + 1]; 
	}
	
	for (int i = 0, k=0, left=0, right=0; i < q; i++) {
		cin >> k >> left >> right; k--;//, left, right;
		
		if (!k) {
			left = left + n - 1;
			segment_tree[left] = right;// - 1;

			left /= 2;
			while (left) {
					segment_tree[left] = segment_tree[2 * left] + segment_tree[2 * left + 1];
					left /= 2;
			}
			continue;
		}
		cout << sum_stree(left-1, right-1) << endl;
	}
	
	
	
	return 0;
}

