#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <numeric>
using namespace std;
 
string s; 
bool vis[7][7];
int ans;
 
void dfs(int i, int j, int a){
     //cout << i << " " << j << " " << a << endl;
     //cout << "\t" << s[a] << endl;
     if (i == 6 && j == 0) {
         if (a == 48){
             ans++;
             //cout << "\t" << ans << endl;
         }
         return;
     }
     
	int ppaths = 0;
	if (i+1 < 7 && !vis[i+1][j]) {
		ppaths++;
	}
	if (i-1 >= 0 && !vis[i-1][j]) {
		ppaths++;
	}	
	if (j+1 < 7 && !vis[i][j+1]) {
		ppaths++;
	}
	if (j-1 >= 0 && !vis[i][j-1]) {
		ppaths++;
	}
	
	if (ppaths == 2) {
		if (i+1 < 7 && i-1 >= 0) {
			if (!vis[i+1][j] && !vis[i-1][j]) {
				return;
			}
		}
		if (j+1 < 7 && j-1 >=0) {
			if (!vis[i][j+1] && !vis[i][j-1]) {
				return;
			}	
		}
	}
     vis[i][j] = 1;
     if(s[a] == '?' || s[a] == 'L') {
         if(j>0 && !vis[i][j-1]) {
             //vis[i][j-1] = 1;
             dfs(i, j-1, a+1);
             //vis[i][j-1] = 0;
         }
     }
     if(s[a] == '?' || s[a] == 'R') {
         if(j < 6 && !vis[i][j+1]) {
            //vis[i][j+1] = 1;
            dfs(i, j+1, a+1);
            //vis[i][j+1] = 0;
         }
     }
     if(s[a] == '?' || s[a] == 'U') {
         if(i>0 && !vis[i-1][j]) {
             //vis[i-1][j] = 1;
             dfs(i-1, j, a+1);
             //vis[i-1][j] = 0;
         }
     }
     if(s[a] == '?' || s[a] == 'D') {
         if(i < 6 && !vis[i+1][j]) {
             //vis[i+1][j] = 1;
             dfs(i+1, j, a+1);
             //vis[i+1][j] = 0;
         }
     }
     vis[i][j] = 0;
     return;
}
int main() {
    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 6; j++) {
            vis[i][j] = 0;
        }
    }
    cin >> s;
    dfs(0, 0, 0);
    cout << ans << endl;
}
