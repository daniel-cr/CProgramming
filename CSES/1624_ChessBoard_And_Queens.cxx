#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>
#include <numeric>
#include <stdio.h>
#include <string.h>
 
using namespace std;
 
 
int main() {
    int n = 8;
    vector<string> rows(n);
    for(int i =0; i < n; i++) {
        cin >> rows[i];
    }
    
    int qc[8];
    iota(qc, qc + n, 0);
    
    bool q_diagonal[15];
    int good = 0;
    do {
        bool check = 1;
        for(int i = 0; i < n; i++) {
            if (rows[i][qc[i]] == '*') {
                check ^= 1;
                break;
            }
        }
        if (check) {
            memset (q_diagonal, 0, 15);
            for(int i = 0; i < n; i++) {
                if(q_diagonal[i + qc[i]]) {
                    check ^= 1;
                    break;
                } else {
                    q_diagonal[i + qc[i]] ^= 1;
                }
            }
        }
        if (check) {
            memset (q_diagonal, 0, 15);
            for(int i = 0; i < n; i++) {
                if(q_diagonal[i + 7 - qc[i]]) {
                    check ^= 1;
                    break;
                } else {
                    q_diagonal[i + 7 - qc[i]] ^= 1;
                }
            }
        }
        if (check) {
            good++;
        }
    }while(next_permutation(qc, qc + n));
    cout << good << endl;
    return 0;
}
