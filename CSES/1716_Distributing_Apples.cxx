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

const int MX = 2 * 1e6 + 1;

li factorial[MX];
li inverse[MX];

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

// Stars & Bars Problem
// Calculate binomial (n + k - 1, n) = (n + k - 1, k - 1)
// That is (n + k - 1)! / (n! * (k - 1)!)
// Problem wants/requires modulo 1e9 + 7
// Fermat's Little theorem to calculate the inverse and binary exponentiation.
int main() {
    
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int k, n; cin >> k >> n;
	
	factorial[0] = 1;
	for (int i = 1; i <= n + k - 1; i++)
	{
		factorial[i] = factorial[i - 1] * i % MOD;
	}
	
	inverse[1] = 1;
	for(int i = 2; i <= n + k - 1; ++i) {
		inverse[i] = MOD - (MOD / i) * inverse[MOD % i] % MOD;
	}

	cout << (factorial[n + k - 1] % MOD * bin_expo(factorial[n], MOD - 2) % MOD * bin_expo(factorial[k - 1], MOD - 2) % MOD) % MOD << '\n';

	return 0;
}