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
const double PI = 3.1415926535897932384;
const double EPS = 1e-7;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	li x1, y1, x2, y2, x3, y3;
	while (n-- > 0)
	{
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

		double theta = -atan2(y2 - y1, x2 - x1);
		
		//double x = x2 * cos_t - y2 * sin_t;
		double y = (x3 - x1) * sin(theta) + (y3 - y1) * cos(theta);

		if (fabs(y) < EPS) {
			cout << "TOUCH";
		} else if (y < 0.0) {
			cout << "RIGHT";
		} else {
			cout << "LEFT";
		}

		cout << "\n";
	}

	return 0;
}