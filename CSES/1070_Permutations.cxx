#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n; cin >> n;
    
    if (n == 1) {
        cout << "1" << "\n";
        return 0;
    }
    
    if (n <= 3) {
        cout << "NO SOLUTION" << "\n";
        return 0;
    }
 
    vector<int> odd;
    vector<int> even;
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            even.push_back(i);
        } else {
            odd.push_back(i);
        }
    }
    reverse(even.begin(), even.end()); 
    reverse(odd.begin(), odd.end());
    for (auto i : odd) {
        cout << i << " ";
    }
    for (auto i : even) {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}
