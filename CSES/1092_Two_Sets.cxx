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

	li n; cin >> n;

	li sum = n * (n + 1) / 2;

	if (sum % 2 != 0) {
		cout << "NO" << '\n';
	} else {
		vector<li> A;
		vector<li> B;

		li asum = sum / 2;
		li bsum = sum / 2;

		bool flag = 1;
		while (n)
		{
			if (flag) {
				if (asum - n >= 0) {
					A.push_back(n);
					asum -= n;
					n--;
				}
			} else {
				if (bsum - n >= 0) {
					B.push_back(n);
					bsum -= n;
					n--;
				}
			}
			flag = !flag;
		}	

		cout << "YES" << '\n';
		cout << A.size() << '\n';
		for (int  i = 0; i < A.size(); i++)
		{
			cout << A[i] << ' ';
		}
		cout << '\n';

		cout << B.size() << '\n';
		for (int  i = 0; i < B.size(); i++)
		{
			cout << B[i] << ' ';
		}
		cout << '\n';

	}

	return 0;
}