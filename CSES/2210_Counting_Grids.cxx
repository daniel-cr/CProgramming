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

li bin_expo(li x, li n) {
	li cur = 1;
	while (n)
	{
		if (n & 1) {
			cur = cur * x % MOD;
		}
		x = x * x % MOD;
		n >>= 1;
	}
	return cur;
}


// Burnside's lemma for even and odd number of n^2 cells turn out to be the same.
int main() {
    
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;

	// for (int n = 7; n <=8; n++)
	// {
		if (n == 1) {
			cout << 2 << '\n';
		} else {
			li n2 = bin_expo(n, 2) % MOD;
			li ans = bin_expo(2, n2) % MOD;
			if (n % 2 == 0) {
				ans += bin_expo(2, (n2 / 2) / 2) % MOD +  bin_expo(2, (n2 / 4 + 1) / 4) % MOD;
			} else {
				ans += bin_expo(2, ((n2 + 1) / 2) / 2) % MOD + 2 * bin_expo(2, ((n2 + 3) / 4) / 4) % MOD;
			}
			
			cout << (ans / 4) % MOD << '\n';
		}
	// }
	
	return 0;


}