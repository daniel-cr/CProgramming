#include "bits/stdc++.h"
using namespace std;

int main(int argc, char **argv) {
	int n; cin >> n;
	
	long long int ans = -1e10;
	long long int sum = -1e10;
	long long int t;
	while (n--) {
		cin >> t;
		sum = max(t, sum + t);
		ans = max(ans, sum);
	}
	
	cout << ans << endl;

	return 0;
}

