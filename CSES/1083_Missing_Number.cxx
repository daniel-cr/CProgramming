#include <iostream>
#include <unordered_set>
using namespace std;
int main(){
    int n; cin >> n;
    unordered_set <int> t;
    for(int i = 1; i <= n; i++) {
        t.insert(i);
    }
    int num;
    while(n--) {
        cin >> num;
        t.erase(num);
    }
    auto it = t.begin();
    cout << *it << "\n";
    return 0;
}
