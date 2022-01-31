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

	int n;
	cin >> n;

	li x0, y0;
	cin >> x0 >> y0;

	li ans = 0, x, y, px = x0, py = y0;
	while (--n > 0)
	{
		cin >> x >> y;
		ans += px * y;
		ans -= x * py;

		px = x; py = y;
	}
	ans += px * y0;
	ans -= x0 * py;
 
	cout << li(abs(ans)) << "\n";
	

	return 0;
}