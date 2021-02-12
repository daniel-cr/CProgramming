#include <iostream>
using namespace std;
int main(){
    long long n; cin >> n;
    cout << n << " ";
    while(n>1) {
        n = (n % 2 == 0) ? n/2 : 3 * n + 1;
        cout << n << " ";
    }
    
    return 0;
}
