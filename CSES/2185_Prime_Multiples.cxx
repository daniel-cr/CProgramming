#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <random>
#include <ctime>
#include <string>
#include <iomanip>
#include <set>
#include <numeric>

using namespace std;

typedef long long li;

li primes[21];

struct c_unique {
  li current;
  c_unique() {current=0;}
  li operator()() {return ++current;}
} UniqueNumber;

li func(vector<li>& vect, li n) {
	li p = 1;
	for(int i : vect) {
		if (p > n / primes[i - 1]) {
			return 0;
		}
		p *= primes[i - 1];
	}
	return p;
}


li combination_seq(int n, int r, li big_n) {
	li ans;
    vector<li> idx_seq(r);
    vector<li>::iterator first = idx_seq.begin(), last = idx_seq.end();
    generate(first, last, UniqueNumber);

	li den = func(idx_seq, big_n);
	ans = den ? big_n / den : 0;

    while((*first) != n-r+1) {
        vector<li>::iterator mt = last;

        while (*(--mt) == n-(last-mt)+1);
        (*mt)++;
        while (++mt != last) *mt = *(mt-1)+1;

		den = func(idx_seq, big_n);
		ans += den ? big_n / den : 0;
    }
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	li n, k; cin >> n >> k;

	for (int i = 0; i < k; i++)	cin >> primes[i];

	li sum = 0;
	for (int i = 1; i <= k; i++)
	{
		li sign = i % 2 ? 1 : -1;
		sum = sum + sign * combination_seq(k, i, n);
	}

	cout << sum << "\n";

	return 0;
}