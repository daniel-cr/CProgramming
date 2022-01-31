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

//move(from, using, to, ~)
// move n from x to z using y
// // move (n-1) from x to y using z
// // move single disk from x to z
// // move (n-1) from y to z using x
void move(int x, int y, int z, int n) {
	if (n) {
		move(x, z, y, n - 1);
		cout << x << ' ' << z << '\n';
		move(y, x, z, n - 1);
	}
}

int main() {
    
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;

	cout << (1 << n) - 1 << '\n';
	move(1, 2, 3, n);

	return 0;
}