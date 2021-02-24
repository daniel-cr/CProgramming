#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>
#include <numeric>
 
using namespace std;
 
int main() {
    int n; cin >> n;
    vector<long long int> t(n);
    for(int i = 0; i < n; i++) {
        cin >> t[i];
    }
    
    sort(t.begin(), t.end());

    long long int sumt = accumulate(t.begin(), t.end(), (long long int)0);
    long long int best = 0;
    for(int i = 0; i < (1 << n); i++) {
        long long int s = 0;
        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) {
                s += t[j];
            }
        }
        if (s <= sumt / 2) {
            best = max(best, s);
        }
    }
    
    cout << sumt - 2 * best;
    
    return 0;
}
