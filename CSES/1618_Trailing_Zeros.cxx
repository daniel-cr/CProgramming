#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;
 
int main() {
    int n; cin >> n;
    
    int tz = 0;
    int llog5 = log(n) / log(5);
    for(int i = 1; i <= llog5; i++) {
        tz += n / pow(5,i);
    }
    cout << tz << endl;
}
