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

 
int main() {
    
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	int n;
	cin >> n;
 
	double log2 = log(2.0);
	double logn = log((double) n);
 
	int half = n / 2;
	for (int i = 1; i <= half; i++)
	{
		cout << 2 * i << " ";
	}
 
	if (n % 2 != 0) {
		half++;
	}
 
	for (int i = half; i >=1; i--)
	{
		int r = 2 * i - 1;
		int power = (logn - log(r)) / log2;
		int l = n - r * pow(2, power);
 
		cout << 2 * l + 1 << " ";
	}
 
	return 0;
}