#include<bits/stdc++.h> 
using namespace std;
const int N=2e5+9,K=20;
int n,m,k;
int a_[N],a[N],c[N];
bool d[K][N];
bool wn(int x,int nx){
//	for(int i=1;(1<<i)<=nx;i++){
//		if((d[i][x>>i]&&(x>>i)%2==0)||((!d[i][x>>i]&&(x>>i)%2==1)));
//		else{
//			if()
//		}
//	}
	return true;
} 
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	if(n>5000)
		return 0;
	for(int i=1;i<=n;i++) cin>>a_[i];
	for(int i=1;i<=m;i++) cin>>c[i];
	k=0;
	while((1<<k)<n) k++;
	for(int i=1;i<=k;i++)
		for(int j=1;j<=(1<<(k-i));j++){
			char x; cin>>x;
			if(x-'0'==1) d[i][j]=true;
			else d[i][j]=false;
		}
	for(int i=n+1;i<=(1<<k);i++)
		a[i]=-1;
	int T;
	cin>>T;
	while(T--){
		int x[4],ans=0;
		cin>>x[0]>>x[1]>>x[2]>>x[3];
		for(int i=1;i<=n;i++) a[i]=a_[i]^x[i%4];
		for(int i=1;i<=m;i++){
			k=0;while((1<<k)<c[i])k++;
			int cnt=0;
			for(int j=1;j<=(1<<k);j++){
				if(wn(j,c[i]))
					cnt+=j;
			}
			ans=ans^(i*cnt);
		}
		cout<<ans<<'\n';
	}
	cout<<endl;
	return 0;
}
