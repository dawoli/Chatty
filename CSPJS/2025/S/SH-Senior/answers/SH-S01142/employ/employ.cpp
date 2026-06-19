#include<bits/stdc++.h>
using namespace std;
#define int long long
//怎么T234都这么难啊，感觉一等奖线应该非常低吧，绝望了，总感觉这点分根本不够
//我还浪费一堆时间做T2这个神秘题没部分分的 
//J组这么简单，S组这么难，上午先给增长点信心，下午直接趋势 
//what can i say,mamba out 
int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return x*f;
}
int n,m;
char c[505];
int a[505];
bool v[505];
int ans=0;
void dfs(int i,int q){
	if(n-q<m)return ; 
	if(i>n){
		if(n-q>=m)ans++;
		ans%=998244353;
		return ;
	}
	for(int j=1;j<=n;j++){
		if(v[j])continue;
		v[j]=1;
		if(q>=a[j]||c[i]=='0')dfs(i+1,q+1);
		else dfs(i+1,q);
		v[j]=0;
	}
}
signed main(){//employ
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	dfs(1,0);
	cout<<ans%998244353;
	return 0;
}

