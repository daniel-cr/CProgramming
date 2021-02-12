#include <iostream>
#include <string>
using namespace std;
int main(){
    string s; cin >> s;
    
    int m = 0;
    int max_s = 1;
    char last_c = s[0];
    for(int i = 1; i < (int)s.size(); i++) {
        if (s[i] == last_c) {
            max_s++;
        } else { 
            m = max(m, max_s);
            last_c = s[i];
            max_s = 1;
        }
    }
    cout << max(m, max_s) << "\n";
 
    return 0;
}
