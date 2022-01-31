#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <random>
#include <ctime>
#include <string>
#include <iomanip>
#include <set>
#include <map>
#include <queue>
#include <stack>

using namespace std;

typedef pair<int, int> pii;
typedef long long li;

const int MOD = 1e9 + 7;
const int MXN = 2 * 1e5 + 1;

struct Point {
    li x,y;
} pts[MXN];

int dist(Point p1,Point p2) {
    return sqrt((p2.x-p1.x)*(p2.x-p1.x) + (p2.y-p1.y)*(p2.y-p1.y));
}

li closestpair(int lo, int hi) {
    if(lo<hi)
    {
        int m=(lo+hi)/2,d1,d2,d;
        d1=closestpair(lo,m);
        d2=closestpair(m+1,hi);
        d=min(d1,d2);

        int i,j,best;

        for(i=(m-7>=0?m-7:0); i<=m; i++)              //This is in accordance with Stanford lecture. Basically we know that select crossing points(about middle)
            for(j=m+1;j<=m+7&&j<=hi;j++)              //Crossing distance[about middle line]   // for(j=i+1;j<=i+7&&j<=hi;j++)
                best=min(dist(pts[i],pts[j]), d);           
                                                                      
                                                                       //we are calculating best distance with 7 closest points across the middle (sorted x-corrdinate wise).
        return best;                                              //->An assumption which is fairly strong.
    }
    else return -1;        //INF=10000000
}


int main() {
    
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;

	vector<pii> arr(n);

	for (int i = 0; i < n; i++)
	{
		cin >> pts[i].x >> pts[i].y;
	}
	sort(pts, pts + n);

	cout << closestpair(0, n - 1) << '\n';

	return 0;
}