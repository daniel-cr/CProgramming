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
const int MXN = 100 + 1;
const int MXGRID = 8;

double dp[MXN][MXGRID][MXGRID];
double res[MXGRID][MXGRID];

int main() {
    
	ios_base::sync_with_stdio(0);
	cin.tie(0); 
	cout << fixed << setprecision(6);
	
	int k; cin >> k;

	fill_n(&res[0][0], sizeof(res) / sizeof(**res), 1.0);

	for (int i = 0; i < MXGRID; i++)
	{
		for (int j = 0; j < MXGRID; j++)
		{
			for (int k_ = 0; k_ <= k; k_++)
			{
				for (int ii = 0; ii < MXGRID; ii++)
				{
					for (int jj = 0; jj < MXGRID; jj++)
					{
						dp[k_][ii][jj] = 0;
					}
				}
			}

			dp[0][i][j] = 1.0;
			for (int k_ = 0; k_ <= k; k_++)
			{
				for (int ii = 0; ii < MXGRID; ii++)
				{
					for (int jj = 0; jj < MXGRID; jj++)
					{
						if (dp[k_][ii][jj]) {
							int avaialble = (ii > 0) + (ii < MXGRID - 1) + (jj > 0) + (jj < MXGRID - 1);
							double t = dp[k_][ii][jj] / avaialble;
							if (ii) {
								dp[k_ + 1][ii - 1][jj] += t;
							}
							if (jj) {
								dp[k_ + 1][ii][jj - 1] += t;
							}
							if (ii < MXGRID - 1) {
								dp[k_ + 1][ii + 1][jj] += t;
							}
							if (jj < MXGRID - 1) {
								dp[k_ + 1][ii][jj + 1] += t;
							}
						}
					}
				}
			}

			for (int ii = 0; ii < MXGRID; ii++)
			{
				for (int jj = 0; jj < MXGRID; jj++)
				{
					res[ii][jj] *= (1.0 - dp[k][ii][jj]);
				}
			}		
		}
	}
	
	double expected_linearity_answer = 0.0;
	for (int i = 0; i < MXGRID; i++)
	{
		for (int j = 0; j < MXGRID; j++)
		{
			expected_linearity_answer += res[i][j];
		}
	}

	cout << expected_linearity_answer << '\n';
	
	return 0;
}