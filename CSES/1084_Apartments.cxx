#include "bits/stdc++.h"
using namespace std;

int main(int argc, char **argv) {
	int n, m, k; cin >> n >> m >> k;
	
	vector<int> a(n);
	vector<int> b(m);
	
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for(int i = 0; i < m; i++) {
		cin >> b[i];
	}
	
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	
	int good = 0;
	int last = 0;
	for (int i = 0; i < n; i++) {
		for (int j = last; j < m; j++) {
			if(a[i] - k > b[j]) {
				continue;
			}
			last = j;

			if(a[i] + k < b[j]) {
				break;
			}
			good++;
			last++;  
			break;
		}
	}
	cout << good << endl;
	
	return 0;
}

