#include "bits/stdc++.h"
using namespace std;

int main(int argc, char **argv) {
	int n, x; cin >> n >> x;
	
	set<pair<int, int>> s;
	for (int i = 0; i < n; i++)	{
		int a; cin >> a;
		s.insert(make_pair(a, i));
	}
	
	for (auto it = s.begin(); it != s.end(); ++it) {
		int val = abs((*it).first - x);
		
		auto pos = s.lower_bound(make_pair(val, 0));
		if (pos != s.end() && pos != it && (*it).first + (*pos).first == x) {
			cout << (*it).second+1 << " " << (*pos).second+1 << endl;
			return 0;
		}
	}
	cout << "IMPOSSIBLE" << endl;
	return 0;
}

