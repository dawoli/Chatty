#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define antirep(i,a,b) for(int i=a;i>=b;i--)
#define speed ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
const int N=1e6+9,M=1e3+9,INF=1e9+7;
int n,ans,m,tmp,c[N],a[N],b[N],e[N];
void dfs(int cur,int red,int blue){
	bool flag=0;
	if(cur>=n+1){ 
		if(tmp>=ans){
			ans=tmp;
//			rep(i,1,n) cout<<a[i]<<' ';
//			cout<<endl;
//			rep(i,1,n) cout<<c[i]<<" ";
//			cout<<endl;
//			cout<<ans<<endl;
//			cout<<"____"<<endl;
		}
		return;
	}
	c[cur]=0;
	if(a[red]==a[cur]) tmp+=a[red],flag=1;
	dfs(cur+1,cur,blue);
	if(flag) tmp-=a[red];
	flag=0;
	c[cur]=1;
	if(a[blue]==a[cur]) tmp+=a[blue],flag=1;
	dfs(cur+1,red,cur);
	if(flag) tmp-=a[blue];
	return;
}
signed main(){
	speed;
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		memset(e,0,sizeof(e));
		ans=0,m=0;
		rep(i,1,n) cin>>a[i];
		a[0]=0;
		if(n<=100)dfs(1,0,0);
		cout<<ans<<endl;
//		cout<<"-----------"<<endl;
	}
	return 0;
}

