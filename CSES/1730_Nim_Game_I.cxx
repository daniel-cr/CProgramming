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

	int t; cin >> t;
	
	int n;
	while (t--)
	{
		cin >> n;
		int nimsum = 0;

		int xi;
		while (n--)
		{
			cin >> xi;
			nimsum ^= xi;
		}
		cout << (nimsum ? "first" : "second") << '\n';
	}
	
	return 0;
}