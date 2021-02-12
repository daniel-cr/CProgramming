#include <iostream>
#include "bits/stdc++.h"
using namespace std;
     
int main(){
    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        cout << (long long int) (i - 1) * (i + 4) * (i * i - 3 * i + 4) / 2 << "\n";
    }
    return 0;
}
