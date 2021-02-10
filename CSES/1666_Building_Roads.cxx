#include "bits/stdc++.h"

using namespace std;

const int MOD = 1e9 + 7;
const int mxN = 1e5;
int parent[mxN + 1];

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
    if (irep > jrep) {
		parent[irep] = jrep;
	} else {
		parent[jrep] = irep;
	}
}

int main(int argc, char **argv) {
	int n, m; cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}

//	for (int i = 1; i <= n; i++) {
//		cout << parent[i] << '\t';
//	}
//	cout << endl;
	vector<array<int, 2>> v(m);
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		union_p(a, b);
		v[i] = {a,b};
		//for (int j = 1; j <= n; j++) {
		//	cout << parent[j] << '\t';
		//}
		//cout << endl;
	}
	
	
	reverse(v.begin(), v.end());
	for (int i = 0; i < m; i++) {
		union_p(v[i][0], v[i][1]);
	}
	
	//for (int i = 1; i <= n; i++) {
	//	cout << parent[i] << '\t';
	//}
	//cout << endl;
	
	
	set<array<int, 2>> s;
	for (int i = 1; i <= n; i++){
		auto it = s.lower_bound({parent[i]});
		if (it == s.end()) {
			s.insert({parent[i], i});
		} else if ((*it)[0] != parent[i]) {
			s.insert({parent[i], i});
		}
	}
	
	int size = s.size() - 1;
	cout << size << endl;
	
	auto it = s.begin();
	if (size % 2 == 0) {
		for (int i = 0; i < size; i++) {
			cout << (*it)[1] << ' ';
			it++;
			cout << (*it)[1] << endl;
		}
	} else {
		for (int i = 0; i <= size-1; i++) {
			cout << (*it)[1] << ' ';
			it++;
			cout << (*it)[1] << endl;
		}
	}
	return 0;
}

