#include "bits/stdc++.h"
using namespace std;

const int maxn = 2e5;

int main(int argc, char **argv) {
	int n; cin >> n;
	
	int s[maxn];
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	
	sort(s, s+n);
	int median = s[n/2];
	
	long long int m = 0;
	for(int i = 0; i < n; i++) {
		m += abs(s[i] - median);
	}
	cout << m << endl;
	
	return 0;
}

