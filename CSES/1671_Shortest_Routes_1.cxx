#include "bits/stdc++.h"

using namespace std;

const int MOD = 1e9 + 7;
const int mxN = 1e5;
const int INF = 0x3f;
	
bool vst[mxN];

int main(int argc, char **argv) {
	int n, m; cin >> n >> m;
	
	vector<vector<array<long long int, 2>>> net(n);
	for (int i = 0, a = 0, b = 0, c = 0; i < m; i++){
		cin >> a >> b >> c; a--; b--;
		net[a].push_back({b, c});
		//net[b].push_back({a, c});
	}
	

	long long int distance[n];
	memset(distance, INF, sizeof(long long int) * n);
	distance[0] = 0;
	
	priority_queue<array<long long int,2>> q;
	q.push({0, 0});
	
	while(q.size()) {
		int u = q.top()[1];
		q.pop();
		
		if (vst[u]) {
			continue;
		}
		vst[u] = 1;
		
		for (auto t : net[u]) {
			int v = t[0], d = t[1];
			if (distance[u] + d < distance[v]) {
				distance[v] = distance[u] + d;
				q.push({-distance[v], v});
			}
		}
	}
	for (int i = 0; i < n; i++){
		cout << distance[i] << ' ';
	}
	cout << endl;
	
	return 0;
}

