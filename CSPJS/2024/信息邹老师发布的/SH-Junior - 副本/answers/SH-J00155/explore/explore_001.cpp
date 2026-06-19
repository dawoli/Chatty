#include<bits/stdc++.h>
using namespace std;

int times;
long long m,n,k;
long long x,y,d,ans;
long long cnt = 0;
char mapp[1010][1010];

int dfs(long long ax,long long ay,long long ad){
	if(cnt == k){
		return 0;
	}
	mapp[ax][ay] = 'm';
	cnt ++;
	if(ad == 0){
		if(mapp[ax][ay+1] == '.'){
			dfs(ax,ay+1,0);
		}
		else{
			ad = 1;
		}
	}
	if(ad == 1){
		if(mapp[ax+1][ay] == '.'){
			dfs(ax+1,ay,1);
		}
		else{
			ad = 2;
		}
	}
	if(ad == 2){
		if(mapp[ax][ay-1] == '.'){
			dfs(ax,ay-1,2);
		}
		else{
			ad = 3;
		}
	}
	if(ad == 3){
		if(mapp[ax-1][ay] == '.'){
			dfs(ax-1,ay,3);
		}
		else{
			ad = 0;
		}
	}
	
	
}
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	cin>>times;
	for(int i = 1;i <= times;i++){
		cin>>m>>n>>k;
		cin>>x>>y>>d;
		for(int p = 1;p <= m;p++){
			for(int q = 1;q <= n;q++){
				cin>>mapp[p][q];
			}
		}
		dfs(x,y,d);
		for(int p = 1;p <= m;p++){
			for(int q = 1;q <= n;q++){
				if(mapp[p][q] == 'm'){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
		ans = 0;
	}
	return 0;
}
/*
2
1 5 4
1 1 2
....x
5 5 20
1 1 0
.....
.xxx.
.x.x.
..xx.
x....

1
1 5 4
1 1 2
....x

*/
