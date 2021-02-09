#include "bits/stdc++.h"
using namespace std;

const int maxn = 2e5;

int main(int argc, char **argv) {
	int n; cin >> n;
	
	vector<pair<int, int>> t(n);
	for (int i = 0; i < n; i++) {
		
		cin >> t[i].second >> t[i].first;	
	}
	sort(t.begin(), t.end());

	int movies_n = 0;
	int current_time = 0;
	for (int i = 0; i < n; i++) {
		if (current_time <= t[i].second){
			current_time = t[i]. first;
			movies_n++;
		}
	}
	cout << movies_n << endl;
	
	
	return 0;
}

