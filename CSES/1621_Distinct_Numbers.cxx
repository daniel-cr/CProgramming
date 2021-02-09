#include "bits/stdc++.h"
using namespace std;

int main(int argc, char **argv) {
	int n; cin >> n;
	
	set<int> data;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		data.insert(x);
	}
	cout << data.size() << endl;
	return 0;
}

