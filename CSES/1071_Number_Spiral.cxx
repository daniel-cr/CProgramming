#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n; cin >> n;
    while(n--) {
        long long y, x; cin >> y >> x;
        
        long long m = max(y, x);
        long long s = m * m - 2 * m + 2;
        
        if (m % 2 == 0) {
            s += y - 1 + m - x;
        } else {
            s += x - 1 + m - y;
        }
        cout << s << "\n";
    }
    return 0;
}
