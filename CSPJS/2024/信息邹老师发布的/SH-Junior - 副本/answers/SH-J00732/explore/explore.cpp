#include<bits/stdc++.h>
using namespace std;
int T, n, m, k, x, y, d, ans = 1;
string jungle[1000], tmp;

bool test(int tx, int ty){
	if(0 <= tx < m && 0 <= ty < n && jungle[ty][tx] == '.') return true;
	return false;
}
void solve(int lx, int ly, int dir, int step){
	for(int i = 0;i < step;i ++){
		if(dir == 0){
			if(test(lx+1, ly)){
				lx+=1;
				ans++;
				continue;
			}
			dir = (dir+1%4);
		}
		else if(dir == 1){
			if(test(lx, ly+1)){
				ly+=1;
				ans++;
				continue;
			}
			dir = (dir+1%4);
		}
		else if(dir == 2){
			if(test(lx-1, ly)){
				lx-=1;
				ans++;
				continue;
			}
			dir = (dir+1%4);
		}
		else if(dir == 3){
			if(test(lx, ly-1)){
				ly-=1;
				ans++;
				continue;
			}
			dir = (dir+1%4);
		}
	}
}
int main(){
	freopen("explore.in", "r", stdin);
	freopen("explore.out", "w", stdout);
	cin>>T;
	for(int i = 0;i < T;i ++){
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int j = 0;j < n;j ++){
			cin>>tmp;
			jungle[j] = tmp;
		}
		x -= 1;
		y -= 1;
		solve(x, y, d, k);
		cout<<ans<<endl;
		ans = 0;
	}
	return 0;
}
