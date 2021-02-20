 
#include <iostream>
#include "bits/stdc++.h"
 
using namespace std;
 
const int MOD = 1e9 + 7;
const int mxN = 1e3;
const int INF = 1 << 30;
 
int di[4] = {-1, 1 , 0, 0};
int dj[4] = {0, 0 , -1, 1};
char letters[4] = {'U', 'D' , 'L', 'R'};
 
int n, m;
int D[mxN][mxN];
int M[mxN][mxN];
 
array<int,2> parent[mxN][mxN];
char pLetter[mxN][mxN];
 
 
bool av(int i, int j) {
	if (i < 0 || j < 0 || i >= n || j >= m)
		return 0;
	return D[i][j] == 0;
}
 
bool avm(int i, int j) {
	if (i < 0 || j < 0 || i >= n || j >= m)
		return 0;
	return M[i][j] > 1;
}
 
bool m_gang(int i, int j) {
	if (i && j) {
		if (M[i-1][j] == 0 && M[i+1][j] == 0 && M[i][j-1] == 0 && M[i][j+1] == 0) {
			return 1;
		}
		if (M[i-1][j] == 0 && M[i+1][j] == 0 && M[i][j+1] == 0) {
			//M[i][j] =-1;
			return 0;
		}
		if (M[i-1][j] == 0 && M[i+1][j] == 0 && M[i][j-1] == 0) {
			//M[i][j] =-1;
			return 0;
		}
		if (M[i-1][j] == 0 && M[i+1][j] == 0) {
			//M[i][j] =-1;
			return 1;
		}
	}
	return 0;
}
 
bool isexit(int i, int j) {
	return (i == n - 1 || j == m - 1 || i == 0 || j == 0);
}
 
int main(int argc, char **argv) {
	cin >> n >> m;
 
	vector<array<int,2>> ms;
	array<int, 2> p;	
	for (int i = 0; i < n; i++){
		string s; cin >> s;
		for (int j = 0; j < m; j++) {
			D[i][j] = s[j] == '#' ? -1 : 0;
			M[i][j] = s[j] == '#' ? -1 : (s[j] == 'M' ? 0 : INF);
			if (s[j] == 'A')
				p = {i, j};
			if (s[j] == 'M')
				ms.push_back({i, j});
		}		
	}
	
	queue<array<int,2>> q;
	q.push(p);
	D[p[0]][p[1]] = 1;
	parent[p[0]][p[1]] = {-1,-1};
	pLetter[p[0]][p[1]] = 'X';
	
	vector<array<int,3>> sols;
	while(q.size()) {
		array<int,2> current = q.front();
		q.pop();
 
		if (isexit(current[0], current[1])) { 
			sols.push_back({D[current[0]][current[1]] - 1, current[0], current[1]});
		}
 
		for (int k = 0; k < 4; k++) {
			int ci = current[0] + di[k];
			int cj = current[1] + dj[k];
			if (av(ci, cj)) {
				q.push({ci, cj});
				D[ci][cj] = D[current[0]][current[1]] + 1;
				parent[ci][cj] = {current[0], current[1]};
				pLetter[ci][cj] = letters[k];
			}
		}
	}
	
	if (sols.size() == 0) {
		cout << "NO" << endl;
		return 0;
	}
	sort(sols.begin(), sols.end());
	for (int i = 0; i < (int)ms.size(); i++) {
		//cout << i << endl;
		queue<array<int,2>> qm;
		qm.push(ms[i]);
		M[ms[i][0]][ms[i][1]] = 0;
		
		if (m_gang(ms[i][0],ms[i][1])) {
			continue;
		}
		
		while(qm.size()) {
			array<int,2> current = qm.front();
			qm.pop();
			
			for (int k = 0; k < 4; k++) {
				int ci = current[0] + di[k];
				int cj = current[1] + dj[k];
				if (avm(ci, cj)) {
					if (M[current[0]][current[1]] + 1 < M[ci][cj]) {
						qm.push({ci, cj});
						M[ci][cj] = M[current[0]][current[1]] + 1;
					}
				}
			}
		}
	}
	
	vector<char> ans;
	for (int i = 0; i < (int)sols.size(); i++){
		int steps = sols[i][0];
		int a = sols[i][1], b = sols[i][2];
		//cout << a << ',' << b << ':' << steps<< endl;
		if (steps < M[a][b]) {
			array<int,2> id = parent[a][b];
			ans.push_back(pLetter[a][b]);
 
			while (id[0] >= 0 && id[1] >= 0) {
				//cout << id[0] << '-' << id[1] << endl;
				ans.push_back(pLetter[id[0]][id[1]]);
				id = parent[id[0]][id[1]];
			}
			cout << "YES" << endl;
			cout << (int)ans.size() - 1 << endl;
			reverse(ans.begin(), ans.end());
			for (char c : ans) {
				if (c == 'X')
					continue;
				cout << c;
			}
			cout << endl;
			exit(0);
		}
	}
 
	cout << "NO" << endl;
	return 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (D[i][j] >= 0) {
				cout << D[i][j] << " ";
			} else {
				cout << "# ";
			}
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (M[i][j] == INF) {
				cout << ". ";
			} else if (M[i][j] >= 0) {
				cout << M[i][j] << " ";
			} else {
				cout << "# ";
			}
		}
	cout << endl;
	}	
	
	
	return 0;
}
 
 	
