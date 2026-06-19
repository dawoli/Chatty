#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int T,n,limit,ans,tot=0;
struct node{
	int a,b,c;
}club[N];
void dfs(int i,int one,int two,int three,int tot){
	if(i>n){
		ans=max(ans,tot);
		return ;
	}
	if(one>limit || two>limit || three>limit) return ;
	dfs(i+1,one+1,two,three,tot+club[i].a);
	dfs(i+1,one,two+1,three,tot+club[i].b);
	dfs(i+1,one,two,three+1,tot+club[i].c);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		memset(club,0,sizeof club);
		ans=0;
		cin>>n;
		limit=n/2;
		for(int i=1;i<=n;i++){
			int a,b,c; cin>>a>>b>>c;
			club[i].a=a,club[i].b=b,club[i].c=c;
			if(n>1e5) ans+=a;
		}
		if(n>1e5){
			cout<<ans<<endl;
			break;
		}
		dfs(1,0,0,1,0); dfs(1,0,1,0,0); dfs(1,1,0,0,0);
		cout<<ans<<endl;
	}
}
