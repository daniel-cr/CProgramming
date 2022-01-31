#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <random>
#include <ctime>
#include <string>
#include <iomanip>
#include <set>
#include <map>
#include <queue>
#include <stack>

using namespace std;

typedef pair<int, int> pii;
typedef long long li;

const int MOD = 1e9 + 7;


void decToBinary(int n, int max)
{
    for (int i = max - 1; i >= 0; i--) {
        int k = n >> i;
        if (k & 1)
            cout << '1';
        else
            cout << '0';
    }
}

int main() {
    
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;

	for (int i = 0; i < (1 << n); i++)
	{
		decToBinary(i ^ (i >> 1), n);
		cout << '\n';
	}	

	return 0;
}