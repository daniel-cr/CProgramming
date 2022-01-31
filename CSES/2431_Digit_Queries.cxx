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
			cur = cur * x;
		}
		x = x * x;
		n >>= 1;
	}
	return cur;
}

int main() {
    
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	li arr[17];
	for (int i = 1; i <= 17; i++)
	{
		arr[i - 1] = 9 * i * bin_expo(10, i - 1);
	}

	int q; cin >> q;

	li k;
	while (q--)
	{
		cin >> k;
		if (k < 10) {
			cout << k << '\n';
		} else {
			int c;
			for (c = 0; c < 17; c++)
			{
				if (k - arr[c] <= 0) {
					c++; k--;
					break;
				}
				k -= arr[c];
			}

			li x = k / c;
			li y = k % c;
			li ans = bin_expo(10, c - 1) + x;
			cout << to_string(ans)[y] << '\n';
		}
	}
	return 0;
}