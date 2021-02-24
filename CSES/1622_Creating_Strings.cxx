#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
 
 
int main() {
    string s; cin >> s;   
    sort(s.begin(), s.end());
    
    vector<string> t;

    do{
        t.push_back(s);
    }while(next_permutation(s.begin(), s.end()));
    
    cout << t.size() << endl;
    for(auto i : t) {
        cout << i << endl;
    }
    return 0;
}
