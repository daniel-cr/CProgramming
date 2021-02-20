#include <iostream>
#include "bits/stdc++.h"

using namespace std;

const int MOD = 1e9 + 7;
const int mxN = 500 + 1;

const long long int INF = 1LL << 60;
long long int dst[mxN][mxN];

int main(int argc, char **argv) {
	int n, m, qs; cin >> n >> m >> qs;
	
	fill(&dst[0][0], &dst[0][0] + mxN * mxN + sizeof(long long int), INF);
	
    for (int i = 0, a = 0, b = 0; i < m; i++){
		long long int c; 
		cin >> a >> b >> c; //a--; b--;
		long long int v = min (dst[a][b], c);
		dst[a][b] = dst[b][a] = v;
	}
	for (int i = 1; i <= n; i++){
		dst[i][i] = 0;
	}
	
	for (int k = 1; k <= n; k++){
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				dst[i][j] = min(dst[i][j], dst[i][k] + dst[k][j]);
			}
		}
	}
	
	for (int i = 0, a = 0, b = 0; i < qs; i++) {
		cin >> a >> b;
		cout << (dst[a][b] >= INF ? -1 : dst[a][b]) << endl;
	}
	
	return 0;
}

