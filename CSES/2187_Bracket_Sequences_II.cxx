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

li fac[1000002], inv[1000002];

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

int main() {
    
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	string s; cin >> s;
	int p = 0;
	int t = 0;

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(') {
			p++;
		} else {
			if (p > 0) {
				p--;
				t++;
			} else {
				cout << "0" << "\n";
				return 0;
			}
		}
	}
	if (n < 2 * p) {
		cout << "0" << "\n";
		return 0;
	}
	

	if (n % 2) {
		cout << "0" << "\n";
		return 0;
	}
	
	n -= t * 2;

	fac[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		fac[i] = (fac[i - 1] * i) % MOD;
		inv[i] = bin_expo(fac[i], MOD - 2);
	}

	cout << fac[n] * inv[n / 2] % MOD * inv[n / 2] % MOD * bin_expo(n / 2 + 1, MOD - 2) % MOD << endl;

	return 0;
}