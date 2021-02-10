#include "bits/stdc++.h"

using namespace std;

const int MOD = 1e9 + 7;
const int mxN = 2e5;

int n, m;
vector<vector<int>> network(mxN);
int parent[mxN];

int main(int argc, char **argv) {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b; a--; b--;
		network[a].push_back(b);
		network[b].push_back(a);
	}
	

	memset(parent, -1, sizeof(int) * n);
	
	queue<int> q;
	q.push(0);
	
	while(!q.empty()) {
		int current = q.front();
		//cout << current << endl;
		q.pop();
		for(int pc : network[current]) {
			if (parent[pc] < 0) {
				//cout << '\t' << pc << " : " << parent[pc] << endl;
				parent[pc] = current;
				q.push(pc);
				if (pc == n - 1) {
					break;
				}
			}
		}
	}
	if (parent[n - 1] < 0) {
		cout << "IMPOSSIBLE" << endl;
	} else {
		vector<int> path;
		int node = n - 1;
		while (node) {
			path.push_back(node);
			node = parent[node];
		}
		//When it reaches 0 it exits and we add 0 to add it to the path.
		path.push_back(0);
		reverse(path.begin(), path.end());
		cout << path.size() << endl;
		for(int a : path) {
			cout << a+1 << ' ';
		}
		cout << endl;
	}
	
	
	return 0;
}

