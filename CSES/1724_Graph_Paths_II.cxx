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
#include <limits> 
using namespace std;

typedef pair<int, int> pii;
typedef long long li;

const int MOD = 1e9 + 7;
const int MAX = 100;
const li W = 2e18;//9223372036854775807 - 1;

int n;
///https://cp-algorithms.com/graph/fixed_length_paths.html
//https://quickmathintuitions.org/finding-paths-length-n-graph/
void multiply(li A[MAX][MAX], li B[MAX][MAX]) {
	li T[MAX][MAX];
	fill_n(&T[0][0], sizeof(T) / sizeof(**T), W);
	//memcpy (A, T, 100*100*sizeof(li));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				T[i][j] = min(A[i][k] + B[k][j], T[i][j]);
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			A[i][j] = T[i][j];
		}
	}
}

void power(li A[MAX][MAX], li B[MAX][MAX], int k) {
   if (k == 0 || k == 1){
	   return;
   }
   
   power(A, B, k >> 1);
   multiply(A, A);

   if (k & 1) {
	   multiply(A, B);
   }
}


int main() {
    
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int m, k;
	cin >> n >> m >> k;

	li B[MAX][MAX];
	li A[MAX][MAX];

	fill_n(&A[0][0], sizeof(A) / sizeof(**A), W);
	fill_n(&B[0][0], sizeof(B) / sizeof(**B), W);

	int n1, n2;
	li w12;
	for (int i = 0; i < m; i++)
	{
		cin >> n1 >> n2 >> w12;
		A[n1 - 1][n2 - 1] = B[n1 - 1][n2 - 1] = min(A[n1 - 1][n2 - 1], w12);
	}

	power(A, B, k);

	cout << (A[0][n - 1] == W ? -1 : A[0][n - 1]) << '\n';

	return 0;
}