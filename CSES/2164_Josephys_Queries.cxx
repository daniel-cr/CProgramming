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

int main() {
    
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int q;
	cin >> q;
	
	int n, k;
	while(q-- > 0) {
		cin >> n >> k;
		k = n - k + 1;

		int r = 2 * k - 1;
		if (r > n) {
			cout << 2 * (n - k + 1) << "\n";
		} else {
			int l = n - r * pow(2, int(log(n / (double) r) / log(2)));
			cout << 2 * l + 1 << "\n";
		}

	}
 
	return 0;
}