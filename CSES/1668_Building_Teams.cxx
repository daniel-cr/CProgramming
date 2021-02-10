#include "bits/stdc++.h"

using namespace std;

const int MOD = 1e9 + 7;
const int mxN = 1e5;
bool visited[mxN];

int main(int argc, char **argv) {
	int n, m; cin >> n >> m;
	
	vector<vector<int>> network(n);
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		a--; b--;
		network[a].push_back(b);
		network[b].push_back(a);
	}
	
	
	int teams[n];
	memset(teams, -1, sizeof(int) * n);	
	
	queue<int> q;
	for (int i = 0; i < n; i++){
		if (teams[i] != -1) {
			continue;
		}
		teams[i] = 1;
		q.push(i);
		
		while(q.size()) {
			int id = q.front();
			q.pop();
			int ntid = (teams[id] == 1 ? 2 : 1);
			for (int p : network[id]) {
				if (teams[p] < 0) {
					teams[p] = ntid;
					q.push(p);
				} else if(teams[p] == teams[id]) {
					cout << "IMPOSSIBLE"<< endl;
					return 0;
				}
			}
		}
	}
	for (int i = 0; i < n; i++){
		cout << teams[i] << ' ';
	}
	cout << endl;
	
		
}

