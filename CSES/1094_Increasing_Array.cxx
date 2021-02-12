#include <iostream>
#include <string>
using namespace std;
int main(){
    int n; cin >> n;
    
    long long res = 0;
    int m = 0;
    while(n--) {
        int x; cin >> x;
        m = max(m, x);
        
        if (x < m) {
            res += m - x;
        }
    }
    cout << res << "\n";
 
    return 0;
}
