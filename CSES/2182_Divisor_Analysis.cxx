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

const int L = 1e5 + 1;
li primes[L];
li pwr[L];

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
	for (int i = 0; i < n; i++)
	{
		cin >> primes[i] >> pwr[i];
	}

	int count_div = 1, sum_div = 1, prod_div = 1, l_fermat = 1;
	for (int i = 0; i < n; i++)
	{
		count_div = count_div * (pwr[i] + 1) % MOD;
		sum_div = sum_div * (bin_expo(primes[i], pwr[i] + 1) - 1) % MOD * bin_expo(primes[i] - 1, MOD - 2) % MOD;
		prod_div = bin_expo(prod_div, pwr[i] + 1) * bin_expo(bin_expo(primes[i], (pwr[i] * (pwr[i] + 1) / 2)), l_fermat) % MOD;

		l_fermat = l_fermat * (pwr[i] + 1) % (MOD - 1);
	}
	
	cout << count_div << " " << sum_div << " " << prod_div << endl;

	return 0;
}