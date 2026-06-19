#include<bits/stdc++.h>
#define N 200010
#define M 2010 
using namespace std;
typedef long long ll;
ll _,n,ans,a[N],fyl[2];
void input(){
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>a[i];
}
// 0 - red , 1 - blue 
bool fyx[N];
void Dfs(ll x){
	if(x>n){
		fyl[0]=fyl[1]=-1;
		ll fyw=0;
		for(int i=1;i<=n;++i){
			if(fyl[fyx[i]]>0&&a[fyl[fyx[i]]]==a[i])
				fyw+=a[i];
			fyl[fyx[i]]=i;
		}ans=max(ans,fyw);
		return;
	}
	fyx[x]=0;Dfs(x+1);
	fyx[x]=1;Dfs(x+1);
}
void solveBF(){
	ans=0;Dfs(1);
	cout<<ans<<endl;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>_;
	while(_--){
		input();
		if(n<=15) solveBF();
	}
	return 0;
}
