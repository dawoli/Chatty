#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,col[25],last[25],red,blue,res,ans=0,n,a[25];
void dfs(ll st,ll num){
	if(st==0){
		red=blue=res=0;
		for(int i=1;i<=n;i++){
			col[i]=(num>>(i-1))&1;
			if(col[i]){last[i]=blue;blue=i;}
			else last[i]=red,red=i;
		}
		for(int i=1;i<=n;i++){
			res+=(a[last[i]]==a[i])*a[i];
		}
		ans=max(ans,res);
		return;
	}
	dfs(st-1,num|(1<<(st-1)));
	dfs(st-1,num);
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;memset(last,0,sizeof(last));ans=0; 
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		dfs(n,0);
		cout<<ans<<endl;
	}
}
