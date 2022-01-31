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

const int MXK = 100 + 1;
const int MXN = 1e6 + 1;

int ks[MXK];
int ps[MXN];

int main() {
    
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	int k; cin >> k;

	fill_n(&ps[0], sizeof(ps) / sizeof(*ps), 0);
	
	for (int i = 0; i < k; i++)
	{
		cin >> ks[i];
		ps[ks[i]] = ks[i];
	}
	ps[0] = -1;
	sort(ks, ks + k);

	for (int i = 1; i <= n; i++)
	{
		if (ps[i]) {
			cout << 'W';
		} else {
			bool flag = 1;
			for (int j = 0; j < k; j++)
			{
				if (i - ks[j] >= 0 && ps[i - ks[j]] == 0) {
					ps[i] = ks[j];
					cout << 'W';
					flag = 0;
					break;
				}
			}
			if (flag) {
				cout << 'L';
			}
		}
	}
	cout << '\n';
	return 0;
}