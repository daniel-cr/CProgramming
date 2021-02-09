#include "bits/stdc++.h"
using namespace std;

int main(int argc, char **argv) {
	int n; cin >> n;
	set<pair<int, int>> t;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		t.insert(make_pair(a, 1));
		t.insert(make_pair(b, -1));
	}
	int current = 0;
	int maxc = 0;
	for(auto tc : t) {
		current += tc.second;
		maxc = max(maxc, current);
	}
	cout << maxc << endl;
	
	return 0;
}

