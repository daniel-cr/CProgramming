#include <utility>
#include "bits/stdc++.h"
using namespace std;

int main(int argc, char **argv) {
	int n, m; cin >> n >> m;
	
	set<pair<int, int>> s2;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		s2.insert(make_pair(a, i));
	}
	for (int i = 0; i < m; i++) {
		int t; cin >> t;
		auto it = s2.lower_bound(make_pair(t+1, 0));
		if (it == s2.begin()) {
			cout << "-1" << "\n";
		} else {
			--it;
			cout << (*it).first << endl;
			s2.erase(it);
		}
	}
	return 0;
}

