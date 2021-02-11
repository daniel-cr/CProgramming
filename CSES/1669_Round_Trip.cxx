#include "bits/stdc++.h"

using namespace std;

const int MOD = 1e9 + 7;
const int mxN = 1e5;

vector<vector<int>> net(mxN);
int n, m;

int dist[mxN];
int parent[mxN];

//depth first search works nicely with parent arrays as it overrides,
//instead of sharing the space as breadth first search
void dfs2(int u, int s=0) {
	if (~dist[u]) {
		return;
	}

	dist[u] = s++;
	for (int v : net[u]) {
		parent[u] = v;
		int size = abs(dist[v] - s);
		if (dist[v] >= 0 && size > 2) {
			cout << size+1 << endl;
			int node = v;
			for (int i = 0; i <= size; i++){
				cout << node + 1 << ' ';
				node = parent[node];
			}
			cout << endl;
			exit(0);
		} else {
			dfs2(v, s);
		}
	}
}

int main(int argc, char **argv) {
	cin >> n >> m;
	
	for (int i = 0, a , b; i < m; i++){
		cin >> a >> b; a--; b--;
		net[a].push_back(b);
		net[b].push_back(a);
	}
	
	memset(dist, -1, sizeof(int) * n);
	memset(parent, -1, sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		dfs2(i);
	}
	cout << "IMPOSSIBLE" << endl;
	
	
	return 0;
}

