#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int long long
const int N=200009;
const int mod=998244353;
inline int read(){
	int s=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		s=s*10+(ch^48);
		ch=getchar();
	}
	return s*f;
}
int n,m,a[N],lsh[N];
ll f[2][N];
inline void solve(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=lsh[i]=read();
	sort(lsh+1,lsh+n+1); int m=unique(lsh+1,lsh+n+1)-lsh-1;
	for(int i=1;i<=n;i++)a[i]=lower_bound(lsh+1,lsh+m+1,a[i])-lsh;
	memset(f,-1,sizeof(f));
	f[1][0]=0;
	for(int i=2;i<=n;i++){
		int now=i%2,pre=now^1;
		for(int x=0;x<=m;x++)f[now][x]=-1;
		for(int x=0;x<=m;x++){
			if(f[pre][x]==-1)continue;
			f[now][a[i-1]]=max(f[now][a[i-1]],f[pre][x]+(a[i]==x)*lsh[a[i]]);
			f[now][x]=max(f[now][x],f[pre][x]+(a[i]==a[i-1])*lsh[a[i]]);
		}
	}
	cout<<*max_element(f[n%2]+1,f[n%2]+m+1)<<'\n';
}
signed main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int _=read();
	while(_--){
		solve();
	}
	return 0;
}
