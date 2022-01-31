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

void multiply(li F[6][6], li M[6][6]) {
	li T[6][6] = {0};

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			for (int k = 0; k < 6; k++)
			{
				T[i][j] += F[i][k] * M[k][j] % MOD;
			}
		}
	}

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			F[i][j] = T[i][j] % MOD;
		}
	}
}

li M[6][6] = {{1,1,1,1,1,1},{1,0,0,0,0,0},{0,1,0,0,0,0},{0,0,1,0,0,0},{0,0,0,1,0,0},{0,0,0,0,1,0}};
void power(li F[6][6], li n) {
   if (n == 0 || n == 1){
	   return;
   }
   
   power(F, n >> 1);
   multiply(F, F);

   if (n & 1) {
	   multiply(F, M);
   }
}

li recurrence_matrix6(li n) {
	if (n == 0) return 0;
	if (n <= 6) return pow(2, n - 1);

	li F[6][6] = {{1,1,1,1,1,1},{1,0,0,0,0,0},{0,1,0,0,0,0},{0,0,1,0,0,0},{0,0,0,1,0,0},{0,0,0,0,1,0}};
    power(F, n);

	return F[0][0];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	li n; cin >> n;
	cout << recurrence_matrix6(n) << '\n';
	
	return 0;
}