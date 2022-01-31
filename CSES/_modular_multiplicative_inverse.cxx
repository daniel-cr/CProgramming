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

//https://cp-algorithms.com/algebra/module-inverse.html#mod-inv-all-num
using namespace std;

typedef pair<int, int> pii;
typedef long long li;

// const int MOD = 1e9 + 7;
const int MOD = 7;

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

li extended_gcd(li a, li b, li& x, li &y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}

	li _x, _y;
	li d = extended_gcd(b, a % b, _x, _y);
	x = _y;
	y = _x - _y * (a / b);

	return d;
}

void modular_inverse_by_gcd(li a) {
	li x, y;
	int g = extended_gcd(a, MOD, x, y);
	if (g != 1) {
		cout << "No solution!";
	}
	else {
		x = (x % MOD + MOD) % MOD;
		cout << x << endl;
	}
}

int inv[MOD + 1];
int main() {
    
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	inv[1] = 1;
	for (int i = 2; i < MOD; i++)
	{
		inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;
		cout << i << " * " << inv[i] << "\t (mod " << MOD << ") = " << (i * inv[i]) % MOD << "\n";

		modular_inverse_by_gcd(i);
	}

	return 0;
}