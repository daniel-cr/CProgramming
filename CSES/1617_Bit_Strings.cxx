#include <iostream>
#include <string>
#include <vector>
using namespace std;
 
long long int MOD = (long long int)1e9 + 7;
int main() {
    int n; cin >> n;
    
    long long int sum = 1;
    for(int i = 0; i < n; i++) {
        sum = (2 * sum) % MOD;
    }
    cout << sum << endl;
}
