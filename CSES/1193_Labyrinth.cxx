#include "bits/stdc++.h"
 
using namespace std;
 
const int mxN = 1e3;
const int INF = 1 << 30;
 
int g[mxN][mxN];
array<int, 2> start;
array<int, 2> end_;

queue<array<int,2>> q;

int n, m;
 
int get_val(int i, int j) {
	if (i < 0 || j < 0 || i >= n || j >= m) {
		return INF;
	}
	if (g[i][j]) {
		return g[i][j];
	} else {
		return INF;
	}
}
 
void mv(int i, int j) {
	if (i == start[0] && j == start[1]) {
		g[i][j] = 1;
	} else {
		if (g[i][j] > 0) {
			return;
		}
		g[i][j] = min({get_val(i, j-1), get_val(i, j+1), get_val(i-1, j), get_val(i+1, j)}) + 1;
	}
	if (i + 1 < n && g[i+1][j] == 0) {
		q.push({i+1, j});
	}
	if (i - 1 >= 0 && g[i-1][j] == 0) {
		q.push({i-1, j});
	}
	if (j + 1 < m && g[i][j+1] == 0) {
		q.push({i, j+1});
	}
	if (j - 1 >= 0 && g[i][j-1] == 0) {
		q.push({i, j-1});
	}
}
 
int main(int argc, char **argv) {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < m; j++) {
			if (s[j] == 'A') {
				start = {i,j};
				g[i][j] = 1;
			} else if(s[j] == 'B') {
				end_ = {i, j};
				g[i][j] = INF;
			} else {
				g[i][j] = (s[j] == '.') ? 0 : INF;
			}
		}
	}

	q.push({start[0], start[1]});
	while(!q.empty()) {
		array<int, 2> temp = q.front();
		mv(temp[0], temp[1]);
		q.pop();
	}
	
	int i = end_[0], j = end_[1];
	int s = min({get_val(i, j-1), get_val(i, j+1), get_val(i-1, j), get_val(i+1, j)});
	if (s == INF) {
		cout << "NO" << endl;
	} else {
		cout << "YES" 	<< endl;
		
		vector<char> moves;
		while(s) {
			if (s == get_val(i-1, j)) {
				i--;
				moves.push_back('D');
			} else if (s == get_val(i+1, j)) {
				i++;
				moves.push_back('U');
			} else if (s == get_val(i, j-1)) {
				j--;
				moves.push_back('R');
			} else if (s == get_val(i, j+1)) {
				j++;
				moves.push_back('L');
			}
			s--;
		}
		
		reverse(moves.begin(), moves.end());
		cout << moves.size() << endl;
		for(char c : moves) {
			cout << c;
		}
		cout << endl;
	}
	return 0;
}
