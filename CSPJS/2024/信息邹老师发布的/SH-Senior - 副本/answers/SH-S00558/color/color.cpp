#include<bits/stdc++.h>
using namespace std;
int T,col[20],ans,n,a[20],lst[2];
void calc(){
	lst[2]=lst[1]=0;
	int tmp=0;
	for(int i=1;i<=n;i++){
		if(!lst[col[i]])
			lst[col[i]]=i;
		else{
			if(a[i]==a[lst[col[i]]])
				tmp+=a[i];
		}
		lst[col[i]]=i;
	}
	ans=max(ans,tmp);
}
void dfs(int x){
	if(x==n+1){
		calc();
		return ;
	}
	col[x]=1;
	dfs(x+1);
	col[x]=2;
	dfs(x+1);
	col[x]=0;
}
void solve(){
	ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dfs(1);
	cout<<ans<<"\n";
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--)
		solve();
}
