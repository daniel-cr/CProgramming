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
#include <cmath>

using namespace std;

typedef pair<int, int> pii;
typedef long long li;

const int MOD = 1e9 + 7;

void multiply(li F[2][2], li M[2][2]) {
   li a = F[0][0] * M[0][0] % MOD + F[0][1] * M[1][0] % MOD;
   li b = F[0][0] * M[0][1] % MOD + F[0][1] * M[1][1] % MOD;
   li c = F[1][0] * M[0][0] % MOD + F[1][1] * M[1][0] % MOD;
   li d = F[1][0] * M[0][1] % MOD + F[1][1] * M[1][1] % MOD;
   F[0][0] = a % MOD;
   F[0][1] = b % MOD;
   F[1][0] = c % MOD;
   F[1][1] = d % MOD;
}

li bin_expo(li x, li n) {
	li cur = 1;
	while (n)
	{
		if (n & 1) {
			cur = cur * x % MOD;
		}
		x = x * x % MOD;
		n >>= 1;
	}
	return cur;
}

li M[2][2] = {{1,1},{1,0}};
void iterative_power(li F[2][2], li n) {
	while (n)
	{
		if (n & 1) {
			multiply(F, M);
		}
		multiply(F, F);

		cout << n << '\t' << F[0][0] << '\n';
		n >>= 1;
	}
}

void power(li F[2][2], li n) {
   if (n == 0 || n == 1){
	   return;
   }
   
   power(F, n >> 1);
   multiply(F, F);

   if (n & 1) {
	   multiply(F, M);
   }
}

li fibonacci_matrix(li n) {
   if (n == 0) {
	   return 0;
   }
	li F[2][2] = {{1,1},{1,0}};
    //power(F, n - 1);

	iterative_power(F, n-1);
	return F[0][0];
}


int main() {
    
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	li n; cin >> n;	
	cout << fibonacci_matrix(n) << endl;
	
	return 0;
}