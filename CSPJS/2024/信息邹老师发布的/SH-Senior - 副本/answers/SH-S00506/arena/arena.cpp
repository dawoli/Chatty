#include<bits/stdc++.h>
#define N 100009
using namespace std;
int n,m,K,a_[N],a[N],c[N],T,x[4];
bool d[N][N],win[N];
int solve(int k){
	for(int i=1;(1<<i)<=k;i++){
		for(int j=1,cnt;j<=k;cnt++,j+=(1<<i)){
			if(d[i][j]){
				if(a[])
			}
		}
	}
	return a[1]
}
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a_[i];
	for(int i=1;i<=m;i++)cin>>c[N];
	K=0;while((1<<K)<n)K++;
	for(int i=1;i<=K;i++){
		for(int j=1;j<=(1<<(K-i));j++){
			char ch;cin>>ch;
			if(ch=='1')d[i][j]=1;
			else d[i][j]=0;
		}
	}
	cin>>T;
	while(T--){
		memset(win,0,sizeof(win));
		ans=0;
		cin>>x[0]>>x[1]>>x[2]>>x[3];
		for(int i=1;i<=m;i++){
			for(int i=1;i<=n;i++){
				a[i]=a_[i] xor (x[i%4]);
			}
			ans=ans xor (solve(c[i])*i);
		}
		cout<<ans<<endl;
	}
	return 0;
} 
