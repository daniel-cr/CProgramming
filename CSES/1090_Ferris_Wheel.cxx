#include "bits/stdc++.h"
using namespace std;

const int mxN = 2e5;

int main(int argc, char **argv) {
	int n, x; cin >> n >> x;
	
	int w[mxN];
	for(int i = 0; i < n; i++) {
		cin >> w[i];
	}
	
	sort(w, w + n);
	
	int g = 0;
	for (int i = 0, j = n - 1; i <= j; i++){
		while(j > i && w[i] + w[j] > x) {
			j--; g++;
		}
		if(j > i) {
			j--; g++;
		} else if(i == j) {
			g++;
		}
	}
	cout << g << endl;
	
	return 0;
}

