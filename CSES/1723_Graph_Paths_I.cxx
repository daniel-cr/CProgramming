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
const int MAX = 101;

int n;

void multiply(li A[MAX][MAX], li B[MAX][MAX]) {
	li T[MAX][MAX] = {0};

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				T[i][j] += A[i][k] * B[k][j] % MOD;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			A[i][j] = T[i][j] % MOD;
		}
	}
}

void power(li A[MAX][MAX], li B[MAX][MAX], li k) {
   if (k == 0 || k == 1){
	   return;
   }
   
   power(A, B, k >> 1);
   multiply(A, A);

   if (k & 1) {
	   multiply(A, B);
   }
}

void print_matrix(li A[MAX][MAX]) {
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << A[i][j] << ' ';
		}
		cout << '\n';
	}
}


int main() {
    
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int m, k;
	cin >> n >> m >> k;

	int n1, n2;
	li B[MAX][MAX] = {0};
	li A[MAX][MAX] = {0};

	for (int i = 0; i < m; i++)
	{
		cin >> n1 >> n2;
		A[n1 - 1][n2 - 1]++;
		B[n1 - 1][n2 - 1]++;
	}

	power(A, B, k);
	cout << A[0][n - 1] << '\n';
	return 0;
}