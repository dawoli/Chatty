#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int T,n,A[maxn],ans,cnt;
int c[maxn];
void dfs(int now){
	if(now==n+1){
		ans=max(ans,cnt);
	//	for(int i=1;i<=n;++i){
	//		cout<<c[i]<<" ";
	//	}
	//	cout<<'\n';
		return;
	}
//	cout<<"c["<<now<<"]="<<c[now]<<'\n';
	c[now+1]=1;
	int pl=0;
	for(int i=now;i>=1;--i){
		if(A[i]==A[now+1] and c[i]==c[now+1]){pl=A[i];cnt+=A[i];break;}
	}
	dfs(now+1);
	cnt-=pl;
	c[now+1]=2;
	for(int i=now;i>=1;--i){
		if(A[i]==A[now] and c[i]==c[now]){pl=A[i];cnt+=A[i];break;}
	}
	dfs(now+1);
	cnt-=pl;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--){
		ans=0;
		memset(c,0,sizeof(c));
		cin>>n;
		for(int i=1;i<=n;++i){
			cin>>A[i];
		}
		c[1]=1;
		dfs(1);
		c[1]=2;
		dfs(1);
		cout<<ans<<'\n';
	}
	return 0;
}

