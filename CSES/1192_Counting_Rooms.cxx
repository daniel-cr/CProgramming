#include "bits/stdc++.h"

using namespace std;

const int MOD = 1e9 + 7;
const int mxN = 1000;

int grid[mxN][mxN];

int parent[mxN * mxN];

int find(int i) {
    if (parent[i] == i) {
		return i;
	}
    else {
        int res = find(parent[i]);
        parent[i] = res;
        return res;
    }
}
 
void union_p(int i, int j){
    int irep = find(i);
    int jrep = find(j);
    parent[irep] = jrep;
}
 
int main(int argc, char **argv) {
	int n, m; cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < m; j++){
			grid[i][j] = (s[j] == '.' ? 0 : -1);
		}
	}
	
	for (int i = 0; i < mxN * mxN; i++){
		parent[i] = i;
	}
	
	int ids = 1;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == 0) {
				int ct = 0;
				if (i && grid[i-1][j] != -1) {
					ct |= grid[i-1][j];
				}
				int cl = 0;
				if (j && grid[i][j-1] != -1) {
					cl |= grid[i][j-1];
				}
				if (ct && cl && ct != cl) {
					if (ct > cl) {
						union_p(ct, cl);
					} else {
						union_p(cl, ct);
					}
					grid[i][j] = find(ct);
				} else {
					if (ct == cl) {
						if (ct == 0) {
							grid[i][j] = find(ids++);
						} else {
							grid[i][j] = find(ct);
						}
					} else {
						if (ct) {
							grid[i][j] = find(ct);
						} else {
							grid[i][j] = find(cl);
						}
					}
				}
			}
		}
	}
 
	set<int> s;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			if (grid[i][j] > 0) {
				grid[i][j] = find(grid[i][j]);
				s.insert(grid[i][j]);
			}
		}
	}
	
 
 
	cout << s.size() << endl;
 
	
	
	return 0;
}
 
