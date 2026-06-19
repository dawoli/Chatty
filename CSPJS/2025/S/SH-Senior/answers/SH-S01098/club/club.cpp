//Ren5Jie4Di4Ling5%
#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N = 2e4 + 86;

int t, maxx[N], maxx2[N];

struct node{
	int x, y, z;
}a[N];

queue<int >q;
queue<int >x;
queue<int >y;
queue<int >z;

bool cmp(node a, node b){
	return a.x > b.x;
}

signed main(){
	cin.tie(0), cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	for(int i = 1; i <= t; ++i){
		int n;
		cin >> n;
		for(int j = 1; j <= n; ++j ){
			cin >> a[j].x >> a[j].y >> a[j].z;
			x.push(j);
			y.push(j);
			z.push(j);
			maxx[j] = max(a[j].x, max(a[j].y, a[j].z));
			maxx2[j] = min(maxx[j], max(min(a[j].y, a[j].z), min(a[j].x, a[j].y)));
			
		} 
		if(n == 2){
			cout << maxx[1] + maxx[2];
			
		}
		else if(a[1].y == 0 && a[1].z == 0){
			sort(a+1, a+n+1, cmp);
			int ans = 0;
			for(int j = 1; j <= n / 2; ++j){
				ans += a[j].x;
			}
			cout << ans << '\n';
		}
	}
	return 0;
} 
