#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;
 
int main() {
    int n; cin >> n;
 
    while(n--){
        int a, b; cin >> a >> b;
        if ((a+b) % 3 == 0 &&  2 * a >= b && 2 * b >= a) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
