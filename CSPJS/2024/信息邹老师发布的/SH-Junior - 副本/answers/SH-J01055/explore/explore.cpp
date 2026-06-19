# include<bits/stdc++.h>
using namespace std;
int fxs[4]{0,1,0,-1};
int fys[4]{1,0,-1,0};
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int T;
	cin >> T;
	while(T--){
		int n,m,k,x,y,d;
		cin >> n >> m >> k >> x >> y >> d;
		bool mp[1003][1003]{},mp2[1003][1003]{};
		long long cnt = 0;
		for(int i = 1;i <= n;i++){{}
			for(int j = 1;j <= m;j++){
				char cc;
				cin >> cc;
				if(cc=='.'){
					mp[i][j] = 1;
				}
			}
		}
//		for(int i = 0;i <= n+1;i++){
//			for(int j = 0;j <= m+1;j++){
//				cout << mp[i][j] << ' ';
//			}
//			cout << endl;
//		}
		int newx = x+fxs[d],newy = y+fys[d];
		for(;k--;){
			newx = x+fxs[d],newy = y+fys[d];
			if(!mp2[x][y]){
				cnt++;
				mp2[x][y] = 1;
			}
			if(mp[newx][newy]){
				x = newx,y = newy;
			}else{
				d = (d+1)&3;
			}
		}
		if(mp[newx][newy]&&mp2[newx][newy]==0)cnt++;
		cout << cnt << endl;
	} 
	return 0;
}
