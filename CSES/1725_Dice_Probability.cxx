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

double dp[101][601];


void print_arr(int n){
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 6 * n; j++)
		{
			cout << dp[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

int main() {
    
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, a ,b;
	cin >> n >> a >> b;
	
	fill_n(&dp[0][0], sizeof(dp) / sizeof(**dp), 0.0);
	dp[0][0] = 1.0;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= 6; j++)
		{
			int k = 0;
			while (k + j <= 6 * n && k <= 6 * n)
			{
				dp[i][k + j] += 1.0 / 6.0 * dp[i - 1][k];
				k++;
			}
		}
	}

	//print_arr(n);

	double outcome = 0.0;
	for (int i = a; i <= b; i++)
	{
		outcome += dp[n][i];
	}
	cout << fixed << setprecision(6) << outcome << '\n';
	


	return 0;
}